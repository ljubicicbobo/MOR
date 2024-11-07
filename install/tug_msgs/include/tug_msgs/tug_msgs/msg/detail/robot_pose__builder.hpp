// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tug_msgs:msg/RobotPose.idl
// generated code does not contain a copyright notice

#ifndef TUG_MSGS__MSG__DETAIL__ROBOT_POSE__BUILDER_HPP_
#define TUG_MSGS__MSG__DETAIL__ROBOT_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tug_msgs/msg/detail/robot_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tug_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotPose_yaw
{
public:
  explicit Init_RobotPose_yaw(::tug_msgs::msg::RobotPose & msg)
  : msg_(msg)
  {}
  ::tug_msgs::msg::RobotPose yaw(::tug_msgs::msg::RobotPose::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tug_msgs::msg::RobotPose msg_;
};

class Init_RobotPose_y
{
public:
  explicit Init_RobotPose_y(::tug_msgs::msg::RobotPose & msg)
  : msg_(msg)
  {}
  Init_RobotPose_yaw y(::tug_msgs::msg::RobotPose::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_RobotPose_yaw(msg_);
  }

private:
  ::tug_msgs::msg::RobotPose msg_;
};

class Init_RobotPose_x
{
public:
  Init_RobotPose_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotPose_y x(::tug_msgs::msg::RobotPose::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_RobotPose_y(msg_);
  }

private:
  ::tug_msgs::msg::RobotPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tug_msgs::msg::RobotPose>()
{
  return tug_msgs::msg::builder::Init_RobotPose_x();
}

}  // namespace tug_msgs

#endif  // TUG_MSGS__MSG__DETAIL__ROBOT_POSE__BUILDER_HPP_
