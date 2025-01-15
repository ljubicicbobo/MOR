#ifndef _TUG_MR2__TRANSFORM_NODE_HPP_
#define _TUG_MR2__TRANSFORM_NODE_HPP_


#include <eigen3/Eigen/Dense>
#include <sensor_msgs/msg/point_cloud.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <geometry_msgs/msg/point32.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include "rclcpp/node.hpp"

namespace tug_mr2
{

  class TransformNode : public rclcpp::Node
  {
    // Directives ----------------------------------------------------------------
  private:
    using Odometry = nav_msgs::msg::Odometry;

    using LaserScan = sensor_msgs::msg::LaserScan;
    using PointCloud = sensor_msgs::msg::PointCloud;

    // variables
    double z_bf_mb = 0.1;
    double z_mb_bl = 0.05;
    double x_mb_bl = 0.04;
    double delta_mb_bl = M_PI;
    double theta_mb_bl = 84 * (M_PI / 180); // concert to radians
    double theta;

    Eigen::Matrix<double, 4, 4> translation_BL_odom;
    Eigen::Matrix<double, 4, 4> translation_odom;
    Eigen::Matrix<double, 4, 4> rotation_odom;
    Eigen::Matrix<double, 4, 4> translation_total;

    Eigen::Matrix<double, 4, 4> rot_roll; // x axis rotation
    Eigen::Matrix<double, 4, 4> rot_pitch; // y axis rotation
    Eigen::Matrix<double, 4, 4> rot_yaw; // z axis rotation
    Eigen::Matrix<double, 4, 4> rotation_matrix;

  private:
    // Publisher
    rclcpp::Publisher<PointCloud>::SharedPtr point_cloud_pub_;

    // Subscriber
    rclcpp::Subscription<LaserScan>::SharedPtr laser_sub_;
    rclcpp::Subscription<Odometry>::SharedPtr odom_sub_;

    // Methods -------------------------------------------------------------------
  public:
    TransformNode();
    ~TransformNode();

  private:
    void laserCallback(const LaserScan::ConstSharedPtr& msg);
    void odomCallback(const Odometry::ConstSharedPtr& msg);

  }; /* class TransformNode */

} /* namespace tug_mr2 */
#endif /* _TUG_MR2__TRANSFORM_NODE_HPP_ */