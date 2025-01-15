#include "tug_mr2/TransformNode.hpp"
#include <functional>
namespace tug_mr2
{

// -----------------------------------------------------------------------------
TransformNode::TransformNode() :
  Node("transform_node", "tug_mr2")
{
  // Publisher
  point_cloud_pub_ = create_publisher<PointCloud>("point_cloud", 10);

  // Subscriber
  laser_sub_ = create_subscription<LaserScan>(
    "/tug_stage_ros2/robot_0/scan",
    10,
    std::bind(&TransformNode::laserCallback, this, std::placeholders::_1)
  );
  odom_sub_ = create_subscription<Odometry>(
    "/tug_stage_ros2/robot_0/odom",
    10,
    std::bind(&TransformNode::odomCallback, this, std::placeholders::_1)
  );

  // Matrix inititation
  // this matrix is used to transform laser frame to odom frame
  // by using equation (80) [displacement1]
  translation_BL_odom << 1., 0., 0., 0.,
                         0., 1., 0., x_mb_bl,
                         0., 0., 1., -1*(z_bf_mb + z_mb_bl),
                         0., 0., 0., 1.;

  // using cardan angles to performe roll, pitch and yaw, equation 61 [cardan]
  rot_roll << 1., 0., 0., 0.,
        0., cos(delta_mb_bl), (-1 * sin(delta_mb_bl)), 0.,
        0., sin(delta_mb_bl), cos(delta_mb_bl), 0.,
        0., 0., 0., 1.;
  rot_pitch << cos(delta_mb_bl), 0., sin(delta_mb_bl), 0.,
      0., 1., 0., 0.,
      -1 * sin(delta_mb_bl), 0., cos(delta_mb_bl), 0.,
      0., 0., 0., 1.;

  rot_yaw << cos(theta_mb_bl), (-1 * sin(theta_mb_bl)), 0., 0.,
         sin(theta_mb_bl), cos(theta_mb_bl), 0., 0.,
        0., 0., 1., 0.,
        0., 0., 0., 1.;

  // This represents our rotation matrix [cardan]
  rotation_matrix = rot_yaw * rot_roll *  translation_BL_odom;
}

// -----------------------------------------------------------------------------
TransformNode::~TransformNode()
{

}

// -----------------------------------------------------------------------------
void TransformNode::laserCallback(const LaserScan::ConstSharedPtr& msg)
{
  PointCloud pc;
  pc.header.stamp = get_clock()->now();
  pc.header.frame_id = "odom";

  // TODO: Add your manual transformation calculation here
  //       You can add variables to the class if neded
  // we are iterating over all laser one by one by taking ranges.size()
  // http://docs.ros.org/en/noetic/api/sensor_msgs/html/msg/LaserScan.html
  for (int i = 0; i < (int)msg->ranges.size(); ++i)
  {
    // using each laser point starting with the first and adding increment
    //
    double angle = msg->angle_min + i * msg->angle_increment;
    double r = msg->ranges[i];
    // specific point given as vector, angle and distance
    Eigen::Vector4d point_laser(r * cos(angle), r * sin(angle), 0.0, 1.0);
    // transform to odometry frame by multiplying rotation and translation
    Eigen::Vector4d point_odom = rotation_matrix * translation_odom * point_laser;
    geometry_msgs::msg::Point32 p;
    p.x = point_odom(0);
    p.y = point_odom(1);
    p.z = point_odom(2);
    pc.points.push_back(p);
  }
  // publish transformated point cloud
  point_cloud_pub_->publish(pc);
}

// -----------------------------------------------------------------------------
void TransformNode::odomCallback(const Odometry::ConstSharedPtr& msg)
{
  // TODO: Add your manual transformation calculation here
  //       You can add variables to the class if neded

  double x = msg->pose.pose.position.x;
  double y = msg->pose.pose.position.y;
  // theta calculated using quaternions which are multiplied by -1 because coordinate system is reversed
  theta = -1 * (2 * atan2(msg->pose.pose.orientation.z, msg->pose.pose.orientation.w));

  // robot current position and orientation in the odometry frame
  translation_odom <<   cos(theta), (-1 * sin(theta)), 0., y,
                        sin(theta), cos(theta), 0., x,
                        0., 0., 1., 0.,
                        0., 0., 0., 1.;
}

} /* namespace tug_mr2 */