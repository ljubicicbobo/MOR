#include "tug_mr2/KinematicNode.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <chrono>
#include <functional>
#include <cmath>
#include <fstream>
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

// -----------------------------------------------------------------------------
//
//

void KinematicNode::movementCallback(const Movement::ConstSharedPtr& msg) {
  RCLCPP_INFO_STREAM(
    get_logger(),
   "Starting new movement with mode: "
    << static_cast<unsigned>(msg->mode)
  );
  mode_ = msg->mode;
  step_count_ = 0;

  robot_pose_msgs_.clear();
  cmd_vel_msgs_.clear();

  // TODO: Compute the robot's position and heading

  float duration = 30.0;
  float frequency = 20.0;
  float a=5.0;
  float b=4.0;
  // We defined frequency as 2Pi divided by the duration which is 30 sec
  float omega =2*M_PI/duration;

  // num of points to take along curve, casted to int, just multiplyied frequncy by duration
  int num_points = static_cast<int>(duration*frequency);
  // delta t how much to move on curve
  double dt = duration/num_points;
  // here we have for loop which iterates until we have reached all the points, hence duration of 30s has paased
  for (double i=0; i < num_points; ++i) {
    double t = i*dt;

    // parametrization of path
    float x = a * sin(omega * t);
    float y = b*sin(2*omega*t);
    // dx, dy represent rate of charge at particular point t
    // they also represent velocity vector which lays tangent to particlar point
    float dx = a*omega*cos(omega*t);
    float dy = b*2*omega*cos(2*omega*t);
    // we calculate angle between x axis and that tanget vector effectivly calculating direction
    float theta1 = atan2(dy, dx);
    // We push the values to vector robot pose
    tug_msgs::msg::RobotPose pose;
    pose.x = x;
    pose.y = y;
    pose.yaw = theta1;
    robot_pose_msgs_.push_back(pose);
  }
  cmd_vel_msgs_.clear();

  // TODO: Compute the robot's linear and angular velocities
  for (int i=0; i < num_points; ++i) {
    // same as before ***
    double t = i*dt;
    float x = a*sin(omega * t);
    float y = b*sin(2*omega*t);

    float dx_dt = a*omega*cos(omega*t);
    float dy_dt = b*2*omega*cos(2*omega*t);

    float ddx_dtt = -a*omega*omega*sin(omega*t);
    float ddy_dtt = -b*4*omega*omega*sin(2*omega*t);

    // ***
    // We can get the magnitude of the velocity vector by squaring the first derivative of x and y.
    // that represent our linear velocity which dosnt have direction
    float linear_vel= sqrt(dx_dt * dx_dt +  dy_dt * dy_dt);

    // Angular velocity calculated using formula (33) [AngVel]
    float angular_vel1 = (ddy_dtt*dx_dt - dy_dt*ddx_dtt);
    float angular_vel2 = (dx_dt*dx_dt +  dy_dt*dy_dt);
    float angular_velocity = angular_vel1/angular_vel2;


    geometry_msgs::msg::Twist twist_msgs;
    // we only go into we direction along x axis
    twist_msgs.linear.x = linear_vel;
    twist_msgs.linear.y = 0;
    twist_msgs.linear.z = 0.0;

    // as we move around 2d plane we need only angular around z-axis
    twist_msgs.angular.x = 0.0;
    twist_msgs.angular.y = 0.0;
    twist_msgs.angular.z = angular_velocity;

    cmd_vel_msgs_.push_back(twist_msgs);
  }

  bicycle_msgs_.clear();

  // TODO: Compute the robot's translational velocity and steering angle
  //       Push the calculated values to the bicycle_msgs_ vector
  for (double i=0; i < num_points; ++i) {
    // same as before**
    double t = i*dt;
    float x = a*sin(omega * t);
    float y = b*sin(2*omega*t);

    float dx_dt = a*omega*cos(omega*t);
    float dy_dt = b*2*omega*cos(2*omega*t);

    float ddx_dtt = -a*omega*omega*sin(omega*t);
    float ddy_dtt = -b*4*omega*omega*sin(2*omega*t);

    float translational_velocity = sqrt(dx_dt * dx_dt +  dy_dt * dy_dt);
    // **

    // we calculate the steering angle,by first calculating curvature k [curvature]
    // frenet motion along a planar curve, which in essence represent a rate of change.
    float c1 = (dx_dt * ddy_dtt - ddx_dtt * dy_dt);
    float d1 = dx_dt*dx_dt;
    float d2 = dy_dt*dy_dt;
    float d = d1 + d2;
    float c2 = pow(d, 1.5);
    double curvature = c1/c2;
    // we used steeing angle presendet by equation [bycicle2] derived from [bycicle1]
    double steering_angle = atan(0.8*curvature);

    // same as before
    tug_msgs::msg::Bicycle twist_msgs;
    twist_msgs.set__velocity(translational_velocity);
    twist_msgs.set__steering_angle(steering_angle);
    bicycle_msgs_.push_back(twist_msgs);
  }

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