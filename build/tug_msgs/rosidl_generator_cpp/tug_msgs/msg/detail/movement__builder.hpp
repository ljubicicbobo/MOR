// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tug_msgs:msg/Movement.idl
// generated code does not contain a copyright notice

#ifndef TUG_MSGS__MSG__DETAIL__MOVEMENT__BUILDER_HPP_
#define TUG_MSGS__MSG__DETAIL__MOVEMENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tug_msgs/msg/detail/movement__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tug_msgs
{

namespace msg
{

namespace builder
{

class Init_Movement_mode
{
public:
  Init_Movement_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tug_msgs::msg::Movement mode(::tug_msgs::msg::Movement::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tug_msgs::msg::Movement msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tug_msgs::msg::Movement>()
{
  return tug_msgs::msg::builder::Init_Movement_mode();
}

}  // namespace tug_msgs

#endif  // TUG_MSGS__MSG__DETAIL__MOVEMENT__BUILDER_HPP_
