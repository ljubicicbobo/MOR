#include "tug_turtlebot4/SimpleTurtleNode.hpp"

#include <cstdint>
#include <functional>
#include <cmath>

#include "geometry_msgs/msg/transform_stamped.hpp"

#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"

namespace tug_turtlebot4
{

// -----------------------------------------------------------------------------
SimpleTurtleNode::SimpleTurtleNode() :
  Node("simple_turtle", "tug_turtlebot4")
{
  wheel_enc_sub_ = create_subscription<WheelEncoder>(
    "wheel_encoder",
    10,
    std::bind(
      &SimpleTurtleNode::wheelEncoderCallback,
      this,
      std::placeholders::_1
    )
  );

  pose_sub_ = create_subscription<geometry_msgs::msg::PoseArray>(
    "pose",
    10,
    [this](const PoseArray::ConstSharedPtr& msg)
    {
      poseCallback(msg->poses[0]);
    }
  );

  tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(*this);

  step_timer_ = rclcpp::create_timer(
    this,
    get_clock(),
    std::chrono::milliseconds(50),
    std::bind(&SimpleTurtleNode::step, this)
  );

  cmd_vel_pub_ = create_publisher<Twist>("cmd_vel", 10);

  initMotionPattern();

  odom_file_.open("odom.dat", std::ios::out | std::ios::trunc);
  pose_file_.open("pose.dat", std::ios::out | std::ios::trunc);
}

// -----------------------------------------------------------------------------
SimpleTurtleNode::~SimpleTurtleNode()
{
  odom_file_.close();
  pose_file_.close();
}
struct OdometryState {
  double x = 0;
  double y = 0;
  double theta = 0;
  int32_t left = 0;   // Left encoder ticks
  int32_t right = 0;  // Right encoder ticks
} odom_state;

// -----------------------------------------------------------------------------
void SimpleTurtleNode::wheelEncoderCallback(
  const WheelEncoder::ConstSharedPtr& msg
)
{
  // TODO: Add your odometry estimation here
  //double dist = 0.0000873; // pi*diameter/ticks
  double distR = 0.000087168475;
  double distL = 0.000087782283;

  uint16_t currentLeft = msg->left_counter;
  uint16_t currentRight = msg->right_counter;
  const uint16_t maxCounter = 65535;

  int32_t diffRight = (currentRight - odom_state.right + maxCounter+1) % (maxCounter+1);
  int32_t diffLeft = (currentLeft - odom_state.left + maxCounter+1) % (maxCounter+1);
  if (diffRight > maxCounter/2) {
    diffRight -=  (maxCounter+1);
  }
  if (diffLeft > maxCounter/2) {
    diffLeft -= (maxCounter+1);
  }

  RCLCPP_INFO(this->get_logger(), "left: %d; right: %d", msg->left_counter, msg->right_counter);

  bool NotRotating = true;

  if (diffRight == (-diffLeft)) {
    NotRotating = false;
  }

  //RCLCPP_INFO(this->get_logger(), "left: %d; right: %d", diffLeft, diffRight);
  if ((diffRight != 0 || diffLeft != 0) && NotRotating) {
    double disL = distL*diffLeft;
    double disR = distR*diffRight;

    double deltaDist = (disL + disR)/2;
    double deltaTheta = (disR - disL)/0.233;

    double xT = odom_state.x + deltaDist*cos(odom_state.theta + deltaTheta/2);
    double yT = odom_state.y + deltaDist*sin(odom_state.theta + deltaTheta/2);

    double thetaT = odom_state.theta + deltaTheta;

    //RCLCPP_INFO(this->get_logger(), "xT = %f + %f*cos(%f*%f/2) = %f", odom_state.x, deltaDist,odom_state.theta, deltaTheta, xT);
    //RCLCPP_INFO(this->get_logger(), "x: %f", odom_state.x);

    tf2::Vector3 translation(xT, yT, 0.0);
    tf2::Quaternion rotation;
    rotation.setRPY(0.0, 0.0, thetaT);
    publishTransform(rotation, translation);

    // Update
    odom_state.x = xT;
    odom_state.y = yT;
    odom_state.theta = thetaT;
    odom_state.left = currentLeft;
    odom_state.right = currentRight;
  }

}

// -----------------------------------------------------------------------------
void SimpleTurtleNode::poseCallback(const Pose& msg)
{
  // TODO: Use pose callback for calibration
}

// -----------------------------------------------------------------------------
void SimpleTurtleNode::publishTransform(
  const tf2::Quaternion& rotation, 
  const tf2::Vector3& translation
)
{
  geometry_msgs::msg::TransformStamped transform;
  transform.header.stamp = get_clock()->now();
  transform.header.frame_id  = "odom";
  transform.child_frame_id = "my_base";
  transform.transform.rotation = tf2::toMsg(rotation);
  transform.transform.translation = tf2::toMsg(translation);

  tf_broadcaster_->sendTransform(transform);
}

// -----------------------------------------------------------------------------
void SimpleTurtleNode::step()
{
  static size_t step = 0;

  if (step < cmd_vel_msgs_.size())
    cmd_vel_pub_->publish(cmd_vel_msgs_[step++]);
  else if (step == cmd_vel_msgs_.size())
  {
    cmd_vel_pub_->publish(Twist());
    step++;
  }
}

// -----------------------------------------------------------------------------
void SimpleTurtleNode::initMotionPattern()
{
  //TODO: Add motion pattern
  cmd_vel_msgs_.push_back(Twist());
}

} /* namespace tug_turtlebot4 */