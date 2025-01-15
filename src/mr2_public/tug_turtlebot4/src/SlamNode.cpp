#include "tug_turtlebot4/SlamNode.hpp"

#include <functional>
#include <memory>
#include <cmath>
#include <fstream>
namespace tug_turtlebot4
{

// -----------------------------------------------------------------------------
SlamNode::SlamNode() :
  Node("slam", "tug_turtlebot4")
{

  // declare_parameter<int>("task_mode", 1);
  int task_mode_ = 2;

  // Publishers
  occupancy_grid_pub_ = create_publisher<OccupancyGrid>("map", 10);

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


  if(task_mode_ == 1) {
    RCLCPP_INFO(get_logger(), "Initializing Task 1 for real-time mapping.");
    task1();
  }else if (task_mode_ == 2) {
    RCLCPP_INFO(get_logger(), "Initializing Task 2 for global optimization.");
    task2();
  }else {
    RCLCPP_ERROR(get_logger(), "Invalid task_mode: %d. Must be 1 or 2.", task_mode_);
    throw std::invalid_argument("Invalid task_mode parameter");
  }

}

// -----------------------------------------------------------------------------
SlamNode::~SlamNode()
{

}

// -------------------------------------------------------------------------------
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

// -----------------------------------------------------------------------------------

void SlamNode::task1() {
  // Subscription and the callback
  laser_scan_sub_ = create_subscription<LaserScan>(
      "scan", 10, std::bind(&SlamNode::laserScanCallback, this, std::placeholders::_1));

  // Service to save sensor data for Task 2
  save_service_ = create_service<std_srvs::srv::Trigger>(
      "/tug_turtlebot4/slam/save_sensor_data",
      std::bind(&SlamNode::handleSaveSensorData, this, std::placeholders::_1, std::placeholders::_2));

  RCLCPP_INFO(get_logger(), "Task 1 initialized for real-time mapping.");
}


void SlamNode::task2() {

  loadSensorDataFromCSV("sensor_data.csv");
  // Perform global optimization
  optimizeMap();

  // Publish the optimized map
  auto optimized_map = occupancy_grid_map_->toOccupancyGrid();
  occupancy_grid_pub_->publish(*optimized_map);

  RCLCPP_INFO(get_logger(), "Task 2 initialized for global optimization.");
}


// ----------------------------------------------------------------------------------
// Service to handle saving the sensor data and poses to a file
void SlamNode::handleSaveSensorData(
  const std_srvs::srv::Trigger::Request::SharedPtr,
  const std_srvs::srv::Trigger::Response::SharedPtr response) 
{
  saveSensorDataToCSV("sensor_data.csv");
  response->success = true;
  response->message = "Sensor data saved successfully.";
  RCLCPP_INFO(get_logger(), "Sensor data saved successfully.");
}

// ------------------------------------------------------------------------------------

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

  SensorReading reading;
  reading.scan = *msg;
  reading.pose = bot_to_odom.transform;
  sensor_readings_.push_back(reading);

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

    double prevLog = (occupancy_grid_map_->getCell(cell_x, cell_y));
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
      double prevLog = (occupancy_grid_map_->getCell(cell_x, cell_y));
      if (isinf(prevLog) || isnan(prevLog)) {
        logOddsUpdate = 0.5;
      } else {
        logOddsUpdate = probToLog((P_FREE) + prevLog);
      }
      occupancy_grid_map_->updateCell(cell_x, cell_y, logOddsUpdate);
    }
  }

}

// ------------------------------------------------------------------------------------------
void SlamNode::optimizeMap() {
    RCLCPP_INFO(get_logger(), "Starting global optimization...");

    bool improved = true;
    while (improved) {
        improved = false;

        for (uint32_t cell_x = 0; cell_x < occupancy_grid_map_->getWidth(); ++cell_x) {
            for (uint32_t cell_y = 0; cell_y < occupancy_grid_map_->getHeight(); ++cell_y) {
                // Get current log-odds
                double current_log_odds = (occupancy_grid_map_->getCell(cell_x, cell_y));

                // Test flipping the cell state
                double flipped_log_odds = (current_log_odds > 0) ? probToLog(P_FREE) : probToLog(P_OCCUPIED);
                double current_likelihood = calculateLogLikelihood(cell_x, cell_y, current_log_odds);
                double flipped_likelihood = calculateLogLikelihood(cell_x, cell_y, flipped_log_odds);

                // Accept the flip if it improves likelihood
                if (flipped_likelihood > current_likelihood) {
                    RCLCPP_INFO(get_logger(), "Optimize cell x(%f), y(%f); %f", cell_x, cell_y, flipped_log_odds);
                    occupancy_grid_map_->updateCell(cell_x, cell_y, flipped_log_odds);
                    improved = true;
                }
            }
        }
    }

    RCLCPP_INFO(get_logger(), "Global optimization complete.");
}

double SlamNode::calculateLogLikelihood(uint32_t cell_x, uint32_t cell_y, double log_odds) {
    double likelihood = 0.0;

    for (const auto& reading : sensor_readings_) {
        const auto& scan = reading.scan;
        const auto& pose = reading.pose;

        for (size_t i = 0; i < scan.ranges.size(); ++i) {
            double range = scan.ranges[i];
            if (range < scan.range_min || range > scan.range_max) {
                continue;
            }

            double angle = scan.angle_min + i * scan.angle_increment;
            double x_global = pose.translation.x + range * cos(angle);
            double y_global = pose.translation.y + range * sin(angle);

            uint32_t test_cell_x, test_cell_y;
            if (occupancy_grid_map_->worldToCell(x_global, y_global, test_cell_x, test_cell_y)) {
                if (test_cell_x == cell_x && test_cell_y == cell_y) {
                    likelihood += logToProb(log_odds);
                }
            }
        }
    }

    return likelihood;
}


// --------------------------------------------------------------------------------------------

void SlamNode::saveSensorDataToCSV(const std::string& filename) {
    std::ofstream outfile(filename, std::ios::out | std::ios::trunc);
    if (!outfile.is_open()) {
        RCLCPP_ERROR(get_logger(), "Failed to open file: %s", filename.c_str());
        return;
    }

    outfile << "timestamp_sec,timestamp_nanosec,pose_x,pose_y,pose_z,"
            << "orientation_x,orientation_y,orientation_z,orientation_w,"
            << "range_count,ranges\n";

    for (const auto& reading : sensor_readings_) {
        outfile << reading.scan.header.stamp.sec << ","
                << reading.scan.header.stamp.nanosec << ","
                << reading.pose.translation.x << ","
                << reading.pose.translation.y << ","
                << reading.pose.translation.z << ","
                << reading.pose.rotation.x << ","
                << reading.pose.rotation.y << ","
                << reading.pose.rotation.z << ","
                << reading.pose.rotation.w << ",";


        outfile << reading.scan.ranges.size() << ",\"";
        for (size_t i = 0; i < reading.scan.ranges.size(); ++i) {
            outfile << reading.scan.ranges[i];
            if (i != reading.scan.ranges.size() - 1) {
                outfile << " ";
            }
        }
        outfile << "\"\n";
    }

    outfile.close();
    RCLCPP_INFO(get_logger(), "Sensor data saved to file: %s", filename.c_str());
}


void SlamNode::loadSensorDataFromCSV(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        RCLCPP_ERROR(get_logger(), "Failed to open CSV file: %s", filename.c_str());
        return;
    }

    sensor_readings_.clear();

    std::string line;
    bool header_skipped = false;
    while (std::getline(infile, line)) {
        if (!header_skipped) {  
            header_skipped = true;
            continue;
        }

        std::istringstream iss(line);
        SensorReading reading;
        std::string ranges_str;

        char delimiter;
        iss >> reading.scan.header.stamp.sec >> delimiter
            >> reading.scan.header.stamp.nanosec >> delimiter
            >> reading.pose.translation.x >> delimiter
            >> reading.pose.translation.y >> delimiter
            >> reading.pose.translation.z >> delimiter
            >> reading.pose.rotation.x >> delimiter
            >> reading.pose.rotation.y >> delimiter
            >> reading.pose.rotation.z >> delimiter
            >> reading.pose.rotation.w >> delimiter;

        size_t range_count;
        iss >> range_count >> delimiter;
        std::getline(iss, ranges_str, '\n');  
        std::istringstream ranges_iss(ranges_str);
        double range;
        while (ranges_iss >> range) {
            reading.scan.ranges.push_back(range);
        }

        sensor_readings_.push_back(reading);
    }

    infile.close();
    RCLCPP_INFO(get_logger(), "Loaded %zu sensor readings from CSV file: %s",
                sensor_readings_.size(), filename.c_str());
}




} /* namespace tug_turtlebot */