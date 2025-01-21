#include "tug_turtlebot4/NavNode.hpp"

#include <functional>

namespace tug_turtlebot4
{

// -----------------------------------------------------------------------------
NavNode::NavNode()
  : Node("nav", "tug_turtlebot4")
{
  // Publisher
  cmd_vel_pub_ = create_publisher<Twist>("cmd_vel", 10);

  // Subscriptions
  goal_pose_sub_ = create_subscription<PoseStamped>(
    "goal_pose",
    10,
    std::bind(&NavNode::goalPoseCallback, this, std::placeholders::_1)
  );

  laser_scan_sub_ = create_subscription<LaserScan>(
    "scan",
    10,
    std::bind(&NavNode::laserScanCallback, this, std::placeholders::_1)
  );

  pose_sub_ = create_subscription<PoseArray>(
    "pose",
    10,
    [this](const PoseArray::ConstSharedPtr& pose_array)
    {
      poseCallback(pose_array->poses[0]);
    }
  );
}

// -----------------------------------------------------------------------------
NavNode::~NavNode()
{}

// TODO
// TREBA POPRAVITI TRAZENI SECTOR DOBIVA POGRESNU VRIJEDNOSTI u TARGET_SECTOR
// ILI je pogresan update histograma polja koja bi trebala biti 1 su 0;

static double goal_x_ = 9999;
static double goal_y_ = 9999;
const int num_sectors_ = 72;
static float threshold_ = 7.0; // prev half-functioning was 7.0
static double a_ = 1.5; // increase to make more sensitive to disntante obstacels
static double b_ = 0.5; // decress to reduce the impact of distance on obstacle forces
static double m_max = 0.5;
static float c_i = 1.3; // incress to account for noisy sensor
static int m = 50; // increase in clusstered environemnt, decress in open areas
static float angular_scale = 1.0; // tune to make turning more or less aggressive
static float prev_pose_x = 9999;
static float prev_pose_y = 9999;
static float k = 1.0; // proportional for linear velocity
const float v_min = 0.3;
const float v_max = 1.8;
static int k_target = 0.0;
static int stop_vel = 1;
// 355 mm min width of robot
// -----------------------------------------------------------------------------

float computeLinVel(float d_min) {
  // Explain
  float v_sol = std::max(v_min, std::min( k / d_min, v_max));
  return v_sol;
}

double NavNode::findBestSector(int target_sector, const std::vector<int>& binary_histogram) {
  int n = binary_histogram.size();
  std::vector<std::pair<int, int>> valleys;
  int valley_start = -1;
  //RCLCPP_INFO(get_logger(), " n = %d ", n);

  // Find candidate valley
  for ( int i = 0; i < n; ++i) {
	//RCLCPP_INFO(get_logger(), "%d: %d ",i , binary_histogram[i]);
    if (binary_histogram[i] == 0) {
      if (valley_start == -1) {
        //RCLCPP_INFO(get_logger(), " i = %d ", i);
        valley_start = i;
      }
    } else if (valley_start != -1) {
        valleys.emplace_back(valley_start, i - 1);
        valley_start = -1;
    }
  }

  if (valley_start != -1) {
    valleys.emplace_back(valley_start, n - 1);
  }
  double best_sector = -1;
  double min_cost = std::numeric_limits<double>::max();

  if (valleys.empty()) {
    RCLCPP_WARN(get_logger(), "No candidate valleys found! Robot is stuck.");
    return 0.0; // Stop rotation or handle as an edge case.
  }
  RCLCPP_INFO(get_logger(), "-------------000-----------");
  for (const auto& valley : valleys) {
    int start = valley.first;
    int end = valley.second;
    int valley_size = ( end - start + 1);

    RCLCPP_INFO(get_logger(), "Start: %d; End: %d; Valley Size: %d ",start, end, valley_size);
    RCLCPP_INFO(get_logger(), "target_sector: %d;  ", target_sector);
    //RCLCPP_INFO(get_logger(), "valley size: %d", valley_size);
    // Case 1 target in valley && valley wide enough
    if ((target_sector >= start && target_sector <= end) && valley_size > m) {
      RCLCPP_INFO(get_logger(), "Case 1");
      return 2 * M_PI * target_sector / n - M_PI;
    }

    // Case 2 Valles is wide
    if (valley_size > m) {
      RCLCPP_INFO(get_logger(), "Case 2");
      int closest = (target_sector < start) ? start : end;
      double cost = abs(target_sector - closest);
      if (cost < min_cost) {
        min_cost = cost;
        best_sector = 2 * M_PI * (closest + m / 2) / n - M_PI;
      }
    }
    // Case 3
    if (valley_size <= m) {
      RCLCPP_INFO(get_logger(), "Case 3");
      int center = (start + end) / 2;
      double cost = abs(target_sector - center);
      if (cost < min_cost) {
        min_cost = cost;
        best_sector = 2 * M_PI * center / n - M_PI;
      }
    }
  }
  //RCLCPP_INFO(get_logger(), "Best Sector: %f ",best_sector);
  if (best_sector == -1) {
    stop_vel = 1;
    return 0.0;
  }
  return best_sector;
}

void NavNode::publishVelocity(float heading, float d_min, float stop_vel) {
  //RCLCPP_INFO(get_logger(), "STOP vel: %f", stop_vel);

  if (stop_vel == 1) {
    geometry_msgs::msg::Twist cmd_vel;
    cmd_vel.linear.x = 0;
    cmd_vel.angular.z = 0;

    cmd_vel_pub_->publish(cmd_vel);
    return;
  }
  geometry_msgs::msg::Twist cmd_vel;
  cmd_vel.linear.x = computeLinVel(d_min);
  cmd_vel.angular.z = heading * angular_scale;
  cmd_vel_pub_->publish(cmd_vel);
}

void NavNode::goalPoseCallback(const PoseStamped::ConstSharedPtr& goal)
{
  // TODO: Implement reactive navigation
  RCLCPP_INFO(get_logger(), "SETTING POSE");
  RCLCPP_INFO(get_logger(), "x: %f, y: %f", goal->pose.position.x, goal->pose.position.y);
  goal_x_ = goal->pose.position.x;
  goal_y_ = goal->pose.position.y;
  stop_vel = 0;
}

// -----------------------------------------------------------------------------
void NavNode::laserScanCallback(const LaserScan::ConstSharedPtr& scan)
{
  if ((goal_x_ == 9999) && (goal_y_ == 9999)) {
    return;
  }

  // TODO: Implement reactive navigation
  const auto& ranges = scan->ranges;
  const float angle_increment = scan->angle_increment;
  const float min_angle = scan->angle_min;
  float d_min = 99999;

  // Init
  std::vector<float> histogram(num_sectors_, 0.0f);



  // find farthest active cell to choose a and b a-bdmax=0;
  double d_max = 0;
  for (size_t i = 0; i < ranges.size(); ++i) {
    float angle = min_angle + i * angle_increment ;

    if (ranges[i] >= scan->range_max || ranges[i] <= scan->range_min) {
      continue;
    }
    if (i >= 320) {
      continue;
    }

    if (ranges[i] > d_max) {
      d_max = ranges[i];
    }
  }

  b_ = ( m_max / d_max );
  a_ = m_max;

  // calculate threshold based on readings
  int obstacle_count = 0;
  float total_distance = 0;
  int valid_readings = 0;


  // Populate
  for (size_t i = 0; i < ranges.size(); ++i) {

    float distance = ranges[i];
    float angle = min_angle + i * angle_increment ;
    //RCLCPP_INFO(get_logger(), "Angle: %f; i: %ld ", angle, i);
    if (distance >= scan->range_max || distance <= scan->range_min) {
      continue;
    }

    if (ranges[i] < d_min) {
      d_min = ranges[i];
    }
    if (i >= 320) {
       continue;
    }

    //if (angle >= -M_PI / 8 && angle <= M_PI / 8) {
      // Angle is in the front (e.g., within ±22.5°)
    //  continue;
    //}

    total_distance += ranges[i];
    valid_readings++;

    double force = c_i * c_i * (a_ - b_ * distance);
    force = std::max(0.0, force);

    // calculate required sector by normalizing to 0-2pi by adding M_PI
    // calcualting index by 1/(2*M_PI), mapping then to required sec by multiplying
    int sector = static_cast<int>((angle + M_PI) / (2 * M_PI) * num_sectors_) % num_sectors_;

    histogram[sector] += force;
  }

  for (size_t i = 0; i < histogram.size(); ++i) {
    if (histogram[i] >= threshold_) {
      obstacle_count += 1;
    }
  }

  float avg_distance =(valid_readings > 0) ? total_distance / valid_readings : scan->range_max;

  if (obstacle_count > num_sectors_ * 0.5) {
    threshold_ = 6.3;
  } else if (avg_distance > 3) {
    threshold_ = 7.0;
  } else {
    threshold_ = 6.0;
  }

  RCLCPP_INFO(get_logger(), "Dynamic Threshold: %f, Obstacles: %d, Avg Distance: %f",
            threshold_, obstacle_count, avg_distance);

  std::vector<int> binary_histogram(num_sectors_, 0);
  for (size_t i = 0; i < histogram.size(); ++i) {
    binary_histogram[i] = (histogram[i] >= threshold_) ? 1 : 0;
    //RCLCPP_INFO(get_logger(), "Angle: %ld; Sector : %ld; Hist: %f; Binary: %d ",5*i, i, histogram[i], binary_histogram[i]);
  }

  //RCLCPP_INFO(get_logger(), "Target: %d", k_target);
  double best_sector = findBestSector(k_target, binary_histogram);
  //RCLCPP_INFO(get_logger(), "Best Sector: %f", best_sector);
  if (1) {
    //RCLCPP_INFO(get_logger(), "Best Sector: %f", best_sector);
    publishVelocity(best_sector, d_min, stop_vel);
  }

}

// -----------------------------------------------------------------------------
void NavNode::poseCallback(const Pose& pose)
{
  // TODO: Implement reactive navigation
  // Get robot position and orientation

  //if (prev_pose_x == pose.position.x && prev_pose_y == pose.position.y) {
  //  return;
  //}
  if (goal_x_ == 9999) {
    return;
  }

  float x_robot = pose.position.x;
  float y_robot = pose.position.y;

  const auto& q = pose.orientation;
  float x = q.x;
  float y = q.y;
  float z = q.z;
  float w = q.w;

  float theta_robot = std::atan2(2.0 * (w * z - x * y), 1.0 - 2.0 * (y * y + z * z));
  float dist = std::sqrt(std::pow(goal_x_ - x_robot, 2) + std::pow(goal_y_ - y_robot, 2));
  //RCLCPP_INFO(get_logger(), "Dist: %f", dist);

  if (dist < 0.1) {
    stop_vel = 1;
  }
  // calculate relative
  float theta_target = std::atan2(goal_y_ - y_robot, goal_x_ - x_robot);
  float theta_relative = theta_target - theta_robot;
  //RCLCPP_INFO(get_logger(), "Theta relative: %f", theta_relative);
  // normalize
  if (theta_relative < -M_PI) {
    theta_relative += 2 * M_PI;
  }
  if (theta_relative > M_PI) {
    theta_relative -= 2 * M_PI;
  }

  // Map to sector
  k_target = static_cast<int>(std::round((theta_relative + M_PI) / (2 * M_PI) * num_sectors_)) % num_sectors_;
  if (k_target < 0) {
    k_target += num_sectors_;
  }

  prev_pose_x = pose.position.x;
  prev_pose_y = pose.position.y;
}

} /* namespace tug_turtlebot4 */