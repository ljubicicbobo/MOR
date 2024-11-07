#include "tug_mr2/KinematicNode.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include <chrono>
#include <functional>
#include <cmath>
using namespace std;

namespace tug_mr2
{
  
KinematicNode::KinematicNode() :
  Node("kinematic_node", "tug_mr2"),
  mode_(0),
  step_count_(0)
{
  // Init Publisher
  robot_pose_pub_ = create_publisher<RobotPose>(
    "/tug_stage_ros2/robot_0/cmd_pose",
    10
  );
  cmd_vel_pub_ = create_publisher<Twist>("/tug_stage_ros2/robot_0/cmd_vel", 10);
  bicycle_pub_ = create_publisher<Bicycle>(
    "/tug_stage_ros2/robot_0/cmd_bicycle",
    10
  );

  // Init Subscription
  movement_sub_ = create_subscription<Movement>(
    "init_movement",
    10,
    std::bind(&KinematicNode::movementCallback, this, std::placeholders::_1)
  );

  // Init timer
  timer_ = rclcpp::create_timer(
    this,
    get_clock(),
    std::chrono::milliseconds(50),
    std::bind(&KinematicNode::step,this)
  );
}

// -----------------------------------------------------------------------------
KinematicNode::~KinematicNode()
{

}

struct RobotPose1 {
	double x;
	double y;
	double theta;
};

// -----------------------------------------------------------------------------
//
void parametric_equation(double t, double &x, double &y)
{
  x = 5*std::sin(3*t); // Example: a sinusoidal path for x
  y = 4*std::cos(2*3*t); // Example: a cosine path for y
}

void KinematicNode::movementCallback(const Movement::ConstSharedPtr& msg)
{
  RCLCPP_INFO_STREAM(
    get_logger(),
    "Starting new movement with mode: "
      << static_cast<unsigned>(msg->mode)
  );

  mode_ = msg->mode;
  step_count_ = 0;

  robot_pose_msgs_.clear();
  cmd_vel_msgs_.clear();
  double duration = 30.0;
  double frequency = 20.0;


  // TODO: Compute the robot's position and heading
  /*
  int A=5;
  int B=4;
  int a = 3;
  int b = 6;
  int num_points = static_cast<int>(duration*frequency);
  double dt = duration/num_points;

  for (int i=0; i < num_points; ++i) {
	  double t = i*dt;
	  double x = A * sin(a * t);
	  double y = B*sin(b*t);

	  double dx = A*a*cos(a*t);
	  double dy = B*b*cos(b*t);

	  double theta1 = atan2(dy, dx);
	  tug_msgs::msg::RobotPose pose;
	  pose.x = x;
	  pose.y = y;
	  pose.yaw = theta1;
	  
	  robot_pose_msgs_.push_back(pose);
  //       Push the calculated values to the robot_pose_msgs_ vector
  }

  cout << "Generated " << robot_pose_msgs_.size() << " positions along the path." << endl;
  cmd_vel_msgs_.clear();
  */
  // TODO: Compute the robot's linear and angular velocities
  int A=5;
  int B=4;
  int a = 3;
  //int b = 3;
  int num_points = static_cast<int>(duration*frequency);
  double dt = duration/num_points;

  int round = 1;
  for (double i=0; i < num_points; ++i) {
    double t = i*dt;
    double x, y, x_next, y_next;
    parametric_equation(t, x, y);
    parametric_equation(t + dt, x_next, y_next);

    // Approximate derivatives
    double dx = (x_next - x) / dt;
    double dy = (y_next - y) / dt;

    // Calculate linear velocity
    double linear_velocity = std::sqrt(dx * dx + dy * dy);

    // Calculate the orientation (theta) and angular velocity
    double theta = std::atan2(dy, dx);

    // For angular velocity, compute theta at the next time step
    double x_next2, y_next2;
    parametric_equation(t + 2 * dt, x_next2, y_next2);
    double dx_next = (x_next2 - x_next) / dt;
    double dy_next = (y_next2 - y_next) / dt;
    double theta_next = std::atan2(dy_next, dx_next);
    double angular_velocity = (theta_next - theta) / dt;

    // Create a Twist message
    auto twist_msg = geometry_msgs::msg::Twist();
    twist_msg.linear.x = linear_velocity;
    twist_msg.linear.y = 0.0;
    twist_msg.linear.z = 0.0;
    twist_msg.angular.x = 0.0;
    twist_msg.angular.y = 0.0;
    twist_msg.angular.z = angular_velocity;
    cmd_vel_msgs_.push_back(twist_msg);
  }

  //       Push the calculated values to the cmd_vel_msgs_ vector

  bicycle_msgs_.clear();

  // TODO: Compute the robot's translational velocity and steering angle
  //       Push the calculated values to the bicycle_msgs_ vector

}

// -----------------------------------------------------------------------------
void KinematicNode::step()
{
  switch (mode_)
  {
    case Movement::MOVEMENT_POSE:
    {
      if (step_count_ < robot_pose_msgs_.size())
        robot_pose_pub_->publish(robot_pose_msgs_[step_count_++]);
      break;
    }

    case Movement::MOVEMENT_VELOCITY:
    {
      if (step_count_ < cmd_vel_msgs_.size())
        cmd_vel_pub_->publish(cmd_vel_msgs_[step_count_++]);
      break;
    }

    case Movement::MOVEMENT_BICYCLE:
    {
      if (step_count_ < bicycle_msgs_.size())
        bicycle_pub_->publish(bicycle_msgs_[step_count_++]);
      break;
    }

    default:
      RCLCPP_WARN_STREAM(get_logger(), "Invalid movement mode: " << mode_);
  }
}

} /* namespace tug_mr2 */