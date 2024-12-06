// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tug_msgs:msg/WheelEncoder.idl
// generated code does not contain a copyright notice

#ifndef TUG_MSGS__MSG__DETAIL__WHEEL_ENCODER__BUILDER_HPP_
#define TUG_MSGS__MSG__DETAIL__WHEEL_ENCODER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tug_msgs/msg/detail/wheel_encoder__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tug_msgs
{

namespace msg
{

namespace builder
{

class Init_WheelEncoder_right_counter
{
public:
  explicit Init_WheelEncoder_right_counter(::tug_msgs::msg::WheelEncoder & msg)
  : msg_(msg)
  {}
  ::tug_msgs::msg::WheelEncoder right_counter(::tug_msgs::msg::WheelEncoder::_right_counter_type arg)
  {
    msg_.right_counter = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tug_msgs::msg::WheelEncoder msg_;
};

class Init_WheelEncoder_left_counter
{
public:
  Init_WheelEncoder_left_counter()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WheelEncoder_right_counter left_counter(::tug_msgs::msg::WheelEncoder::_left_counter_type arg)
  {
    msg_.left_counter = std::move(arg);
    return Init_WheelEncoder_right_counter(msg_);
  }

private:
  ::tug_msgs::msg::WheelEncoder msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tug_msgs::msg::WheelEncoder>()
{
  return tug_msgs::msg::builder::Init_WheelEncoder_left_counter();
}

}  // namespace tug_msgs

#endif  // TUG_MSGS__MSG__DETAIL__WHEEL_ENCODER__BUILDER_HPP_
