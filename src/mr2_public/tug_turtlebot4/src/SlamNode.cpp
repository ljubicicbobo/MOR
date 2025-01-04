#include "tug_turtlebot4/SlamNode.hpp"

#include <functional>
#include <memory>
#include <cmath>
namespace tug_turtlebot4
{

// -----------------------------------------------------------------------------
SlamNode::SlamNode() :
  Node("slam", "tug_turtlebot4")
{
  // Publishers
  occupancy_grid_pub_ = create_publisher<OccupancyGrid>("map", 10);

  // Subscriptions
  laser_scan_sub_ = create_subscription<LaserScan>(
    "scan",
    10,
    std::bind(&SlamNode::laserScanCallback, this, std::placeholders::_1)
  );

  // Occupancy grid map
  occupancy_grid_map_ = std::make_shared<OccupancyGridMap>(
    this,
    300U,
    300U,
    0.1F
  );

  // TF2
  tf_buffer_ = std::make_shared<tf2_ros::Buffer>(get_clock());
  tf_listener_ = std::make_shared<tf2_ros::TransformListener>(
    *tf_buffer_,
    this
  );
}

// -----------------------------------------------------------------------------
SlamNode::~SlamNode()
{

}

const double P_OCCUPIED = 0.9;
const double P_FREE = 0.1;

double logToProb(double x) {
  return 1.0 / (1.0 + exp(-x));
}

double probToLog(double x) {
  if (x==0) {
    return 0;
  }
  return log(x / (1.0 - x));
}

// -----------------------------------------------------------------------------
void SlamNode::laserScanCallback(const LaserScan::ConstSharedPtr& msg)
{
  // TODO: Add map estimation

  // Get robot's pose
 // ----------------------------------------------------------------------------
  geometry_msgs::msg::TransformStamped bot_to_odom;
  geometry_msgs::msg::TransformStamped link_to_bot;

  try {
	rclcpp::Time now = this->get_clock()->now();
    link_to_bot = tf_buffer_->lookupTransform("tug_turtlebot4", "rplidar_link", msg->header.stamp);
    bot_to_odom = tf_buffer_->lookupTransform("odom", "tug_turtlebot4", msg->header.stamp);
  } catch (tf2::TransformException &ex) {
    RCLCPP_WARN(get_logger(), "Could not transform: %s", ex.what());
    return;
  }
  auto& robot_pose = bot_to_odom.transform.translation;
  static int j=0;
  // Laser Scan ranges
  for (size_t i = 0; i < msg->ranges.size(); i++) {
    double range = msg->ranges[i];
    if (range < (msg->range_min) || range > (msg->range_max-4)) {
      continue;
    }
    double angle = msg->angle_min + i * msg->angle_increment;

    geometry_msgs::msg::PointStamped point;
    point.header.frame_id = msg->header.frame_id;
    point.point.x = range*cos(angle);
    point.point.y = range*sin(angle);
    point.point.z = 0;

    geometry_msgs::msg::PointStamped point_odom;
    try {
      tf2::doTransform(point, point_odom, link_to_bot);
    } catch (tf2::TransformException &ex) {
      RCLCPP_WARN(get_logger(), "Could not transform: %s", ex.what());
      continue;
    }

	//
    geometry_msgs::msg::PointStamped point_map;
    try {
      tf2::doTransform(point_odom, point_map, bot_to_odom);
    } catch (tf2::TransformException &ex) {
      RCLCPP_WARN(get_logger(), "Could not transform: %s", ex.what());
    }

    double x = point_map.point.x;
    double y = point_map.point.y;

    // update endpoints
    uint32_t cell_x, cell_y;
    occupancy_grid_map_->worldToCell(x, y, cell_x, cell_y);

    double prevLog = probToLog(occupancy_grid_map_->getCell(cell_x, cell_y));
    double logOddsUpdate;
    if (isinf(prevLog) || isnan(prevLog)) {
      logOddsUpdate = 0.5;
    } else {
      logOddsUpdate = probToLog((P_OCCUPIED) + prevLog);
    }

    if (j < 100) {
      RCLCPP_INFO(get_logger(), "log update black %f", logOddsUpdate);
      j++;
    }
   	occupancy_grid_map_->updateCell(cell_x, cell_y, logOddsUpdate);

    //RCLCPP_INFO(get_logger(), "[i - %ld] Cell - X: %ud, Y: %ud",i, cell_x, cell_y);
    //RCLCPP_INFO(get_logger(), "[i - %ld] X: %f, Y: %f",i, x_rotated, y_rotated);

    // Bresenham algorithm
	std::vector<std::pair<double, double>> points;

    double x0 = robot_pose.x;
    double y0 = robot_pose.y;
    double x1 = x;
    double y1 = y;


    double dx = x1 - x0;
    double dy = y1 - y0;
    double step = (fabs(dx)>fabs(dy)) ? fabs(dx):fabs(dy);

    if (step != 0) {
      double stepX = dx/step;
      double stepY = dy/step;
      for (double i = 0; i < step; i += 0.01) {
        points.push_back({x0 + i*stepX, y0 + i*stepY});
      }
    }

    for (auto& p : points) {
      double x1 = p.first;
      double y1 = p.second;
      occupancy_grid_map_->worldToCell(x1, y1, cell_x, cell_y);
      double prevLog = probToLog(occupancy_grid_map_->getCell(cell_x, cell_y));
      if (isinf(prevLog) || isnan(prevLog)) {
        logOddsUpdate = 0.5;
      } else {
        logOddsUpdate = probToLog((P_FREE) + prevLog);
      }
      occupancy_grid_map_->updateCell(cell_x, cell_y, logOddsUpdate);
    }
  }


}

} /* namespace tug_turtlebot */