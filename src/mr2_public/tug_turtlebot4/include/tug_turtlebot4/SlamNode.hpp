#ifndef _TUG_TURTLEBOT4__SLAM_NODE_HPP_
#define _TUG_TURTLEBOT4__SLAM_NODE_HPP_

#include <functional>

#include <vector>
#include <string>

#include "rclcpp/node.hpp"

#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"

#include "nav_msgs/msg/occupancy_grid.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"

#include "tug_turtlebot4/OccupancyGridMap.hpp"


#include "rclcpp/rclcpp.hpp"
#include "std_srvs/srv/trigger.hpp"


namespace tug_turtlebot4
{

// Struct for storing laser scan data and corresponding robot pose
struct SensorReading {
  sensor_msgs::msg::LaserScan scan;       
  geometry_msgs::msg::Transform pose;    
};

class SlamNode : public rclcpp::Node
{
  // Directives ----------------------------------------------------------------
  private:
    using Point = geometry_msgs::msg::Point;

    using OccupancyGrid = nav_msgs::msg::OccupancyGrid;
    using LaserScan = sensor_msgs::msg::LaserScan;

  // Variables -----------------------------------------------------------------
  private:
    // Publishers
    rclcpp::Publisher<OccupancyGrid>::SharedPtr occupancy_grid_pub_;

    // Subscriptions
    rclcpp::Subscription<LaserScan>::SharedPtr laser_scan_sub_;

    // Occupancy grid map
    OccupancyGridMap::SharedPtr occupancy_grid_map_;

    // TF2
    std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
    std::shared_ptr<tf2_ros::TransformListener> tf_listener_;

    // Sensor and pose readings vector
    std::vector<SensorReading> sensor_readings_;

    // Service to save the data
    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr save_service_;

    int task_mode_;


  // Methods -------------------------------------------------------------------
  public:
    SlamNode();
    ~SlamNode();

    void laserScanCallback(const LaserScan::ConstSharedPtr& msg);
    void task1();
    void task2();
    void saveSensorDataToCSV(const std::string& filename);
    void handleSaveSensorData(const std_srvs::srv::Trigger::Request::SharedPtr request,std_srvs::srv::Trigger::Response::SharedPtr response);
    void loadSensorDataFromCSV(const std::string& filename);
    void optimizeMap();
    double calculateLogLikelihood(uint32_t cell_x, uint32_t cell_y, double log_odds);

}; /* class SlamNode */

} /* namespace tug_turtlebot4 */

#endif /* _TUG_TURTLEBOT4__SLAM_NODE_HPP_ */