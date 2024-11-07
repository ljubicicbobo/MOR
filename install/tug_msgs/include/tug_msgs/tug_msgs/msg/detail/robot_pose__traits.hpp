// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tug_msgs:msg/RobotPose.idl
// generated code does not contain a copyright notice

#ifndef TUG_MSGS__MSG__DETAIL__ROBOT_POSE__TRAITS_HPP_
#define TUG_MSGS__MSG__DETAIL__ROBOT_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tug_msgs/msg/detail/robot_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tug_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotPose & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotPose & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace tug_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tug_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tug_msgs::msg::RobotPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  tug_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tug_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const tug_msgs::msg::RobotPose & msg)
{
  return tug_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tug_msgs::msg::RobotPose>()
{
  return "tug_msgs::msg::RobotPose";
}

template<>
inline const char * name<tug_msgs::msg::RobotPose>()
{
  return "tug_msgs/msg/RobotPose";
}

template<>
struct has_fixed_size<tug_msgs::msg::RobotPose>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tug_msgs::msg::RobotPose>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tug_msgs::msg::RobotPose>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TUG_MSGS__MSG__DETAIL__ROBOT_POSE__TRAITS_HPP_
