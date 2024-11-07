// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tug_msgs:msg/Bicycle.idl
// generated code does not contain a copyright notice

#ifndef TUG_MSGS__MSG__DETAIL__BICYCLE__BUILDER_HPP_
#define TUG_MSGS__MSG__DETAIL__BICYCLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tug_msgs/msg/detail/bicycle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tug_msgs
{

namespace msg
{

namespace builder
{

class Init_Bicycle_steering_angle
{
public:
  explicit Init_Bicycle_steering_angle(::tug_msgs::msg::Bicycle & msg)
  : msg_(msg)
  {}
  ::tug_msgs::msg::Bicycle steering_angle(::tug_msgs::msg::Bicycle::_steering_angle_type arg)
  {
    msg_.steering_angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tug_msgs::msg::Bicycle msg_;
};

class Init_Bicycle_velocity
{
public:
  Init_Bicycle_velocity()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Bicycle_steering_angle velocity(::tug_msgs::msg::Bicycle::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_Bicycle_steering_angle(msg_);
  }

private:
  ::tug_msgs::msg::Bicycle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tug_msgs::msg::Bicycle>()
{
  return tug_msgs::msg::builder::Init_Bicycle_velocity();
}

}  // namespace tug_msgs

#endif  // TUG_MSGS__MSG__DETAIL__BICYCLE__BUILDER_HPP_
