#include "tug_turtlebot4/SlamNode.hpp"

#include <functional>
#include <memory>

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

// -----------------------------------------------------------------------------
void swap(float &a, float &b) {
  float c;
  c = a;
  a = b;
  b = c;
}
  // Drawing Line
void drawLineH(float x0, float y0, float x1,float y1, OccupancyGridMap* occupancy_grid_map) {
  if (x0 > x1) {
    swap(x0, x1);
    swap(y0, y1);
  }
  float dx = x1-x0;
  float dy = y1-y0;

  float dir = (dy < 0) ? -1 : 1;
  dy *= dir;

  if (dx != 0) {
    float y = y0;
    float p = 2*dy - dx;
    for (int i =0; i < (dx+1); i++) {
      // update value (x0+i, y)
      uint32_t cell_x, cell_y;
      occupancy_grid_map->worldToCell(x0+i, y, cell_x, cell_y);
      float value = occupancy_grid_map->getCell(cell_x, cell_y);

      if (value == std::numeric_limits<float>::infinity()) {
      	RCLCPP_WARN(rclcpp::get_logger("slam_node"), "Cell value is infinite");
      	return;
      }

      occupancy_grid_map->updateCell(cell_x, cell_y, -1);
      //RCLCPP_INFO(rclcpp::get_logger("slam_node"), "H1:Cell x: %d; Cell y: %d", cell_x, cell_y);

      if (p >= 0) {
        y += dir;
        p = p - 2*dx;
      }
      p = p + 2*dy;
      if (i == (dx)) {
        occupancy_grid_map->updateCell(cell_x, cell_y, 1);
        //RCLCPP_INFO(rclcpp::get_logger("slam_node"), "H1Cell x: %d; Cell y: %d", cell_x, cell_y);

      }
    }
  }
}

void drawLineV(float x0, float y0, float x1,float y1, OccupancyGridMap* occupancy_grid_map) {
  if (y0 > y1) {
    swap(x0, x1);
    swap(y0, y1);
  }
  float dx = x1-x0;
  float dy = y1-y0;

  float dir = (dx < 0) ? -1 : 1;
  dx *= dir;

  if (dy != 0) {
    float x = x0;
    float p = 2*dx - dy;
    for (int i =0; i < (dy+1); i++) {
      // update value (x, y0+i); ray traverses
      uint32_t cell_x, cell_y;
      occupancy_grid_map->worldToCell(x, y0+i, cell_x, cell_y);
      float value = occupancy_grid_map->getCell(cell_x, cell_y);
      if (value == std::numeric_limits<float>::infinity()) {
      	RCLCPP_WARN(rclcpp::get_logger("slam_node"), "Cell value is infinite");
      	return;
      }
      occupancy_grid_map->updateCell(cell_x, cell_y, -1);
      //RCLCPP_INFO(rclcpp::get_logger("slam_node"), "Cell x: %d; Cell y: %d", cell_x, cell_y);

      if (p >= 0) {
        x += dir;
        p = p - 2*dy;
      }
      p = p + 2*dx;
      if (i == (dy)) {
        occupancy_grid_map->updateCell(cell_x, cell_y, 1);
        //RCLCPP_INFO(rclcpp::get_logger("slam_node"), "Cell x: %d; Cell y: %d", cell_x, cell_y);

      }
    }// ray reaches an end

  }
}

std::vector<std::pair<int, int>> traceRay(float x0, float y0, float x1, float y1, OccupancyGridMap* occupancy_grid_map) {
  std::vector<std::pair<int, int>> cells;
  //RCLCPP_INFO(rclcpp::get_logger("slam_node"), "Range Min: %f", abs(x1-x0));

  if (abs(x1-x0) > abs(y1-y0)) {
    drawLineH(x0, y0, x1, y1, occupancy_grid_map);
  } else {
    drawLineV(x0, y0, x1, y1, occupancy_grid_map);
  }
  return cells;
}

void SlamNode::laserScanCallback(const LaserScan::ConstSharedPtr& msg)
{
  // TODO: Add map estimation
  /*
  RCLCPP_INFO(get_logger(), "Header: %s", msg->header.frame_id.c_str());
  RCLCPP_INFO(get_logger(), "Angle Min: %f", msg->angle_min);
  RCLCPP_INFO(get_logger(), "Angle Max: %f", msg->angle_max);
  RCLCPP_INFO(get_logger(), "Range Min: %f", msg->range_min);
  RCLCPP_INFO(get_logger(), "Range Max: %f", msg->range_max);

  for (size_t i = 0; i < std::min(size_t(10), msg->ranges.size()); ++i) {
     RCLCPP_INFO(get_logger(), "Range[%zu]: %f", i, msg->ranges[i]);
  }
  */

  // Get robot's pose
 // -----------------------------------------------------------------------------
  geometry_msgs::msg::TransformStamped transform;
  try {
	rclcpp::Time now = this->get_clock()->now();
    transform = tf_buffer_->lookupTransform("odom", "tug_turtlebot4", rclcpp::Time(0));
  } catch (tf2::TransformException &ex) {
    RCLCPP_WARN(get_logger(), "Could not transform: %s", ex.what());
    return;
  }
  auto& robot_pose = transform.transform.translation;
  //RCLCPP_INFO(get_logger(), "x: %f, y: %f", robot_pose.x, robot_pose.y);

  tf2::Quaternion q (
  	transform.transform.rotation.x,
    transform.transform.rotation.y,
    transform.transform.rotation.z,
    transform.transform.rotation.w
  );

  double roll, pitch, yaw;
  tf2::Matrix3x3(q).getRPY(roll, pitch, yaw);
  static float log_x = -1;
  static float log_y = -1;
  float theta = static_cast<float>(yaw);

  static int j = 0;
  // Laser Scan ranges
  for (size_t i = 0; i < msg->ranges.size(); i++) {
    float range = msg->ranges[i];
    if (range < msg->range_min || range > msg->range_max) {
      continue;
    }
    float angle = msg->angle_min + i * msg->angle_increment;

	/*
    // Compute the angle of the ray

    // Transform the laser reading into the map frame
    float x = range*cos(angle);
    float y = range*sin(angle);

    float x_map = robot_pose.x + x*cos(theta) - y * sin(theta);
    float y_map = robot_pose.y + x*sin(theta) + y * cos(theta);
	*/

    geometry_msgs::msg::PointStamped point;
    point.header.frame_id = "laser";
    point.point.x = range*cos(angle);
    point.point.y = range*sin(angle);
    point.point.z = 0;

    geometry_msgs::msg::PointStamped point_odom;
    try {
      tf2::doTransform(point, point_odom, transform);
    } catch (tf2::TransformException &ex) {
      RCLCPP_WARN(get_logger(), "Could not transform: %s", ex.what());
      continue;
    }

    uint32_t cell_x, cell_y;
    occupancy_grid_map_->worldToCell(point_odom.point.x, point_odom.point.y, cell_x, cell_y);
    float value = occupancy_grid_map_->getCell(cell_x, cell_y);
    if (value == std::numeric_limits<float>::infinity()) {
      RCLCPP_WARN(get_logger(), "Cell value is infinite");
      return;
    }
    // Bresenham algorithm
    if ((log_x != point_odom.point.x || log_y != point_odom.point.y) && (j != 300)) {
    	RCLCPP_INFO(get_logger(), "Robot Pose - X: %f, Y: %f", robot_pose.x, robot_pose.y);
    	RCLCPP_INFO(get_logger(), "X: %f, Y: %f", point_odom.point.x, point_odom.point.y);
        log_x = point_odom.point.x;
        log_y = point_odom.point.y;
        j = 0;
    }
	j++;
    std::vector<std::pair<int, int>> cells = traceRay( robot_pose.x, robot_pose.y , point_odom.point.x, point_odom.point.y, occupancy_grid_map_.get());
  }


}

} /* namespace tug_turtlebot */