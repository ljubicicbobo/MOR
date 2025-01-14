// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2cpp_tutorials_service:srv/AddTwoInts.idl
// generated code does not contain a copyright notice

#ifndef ROS2CPP_TUTORIALS_SERVICE__SRV__DETAIL__ADD_TWO_INTS__BUILDER_HPP_
#define ROS2CPP_TUTORIALS_SERVICE__SRV__DETAIL__ADD_TWO_INTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2cpp_tutorials_service/srv/detail/add_two_ints__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2cpp_tutorials_service
{

namespace srv
{

namespace builder
{

class Init_AddTwoInts_Request_b
{
public:
  explicit Init_AddTwoInts_Request_b(::ros2cpp_tutorials_service::srv::AddTwoInts_Request & msg)
  : msg_(msg)
  {}
  ::ros2cpp_tutorials_service::srv::AddTwoInts_Request b(::ros2cpp_tutorials_service::srv::AddTwoInts_Request::_b_type arg)
  {
    msg_.b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2cpp_tutorials_service::srv::AddTwoInts_Request msg_;
};

class Init_AddTwoInts_Request_a
{
public:
  Init_AddTwoInts_Request_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AddTwoInts_Request_b a(::ros2cpp_tutorials_service::srv::AddTwoInts_Request::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_AddTwoInts_Request_b(msg_);
  }

private:
  ::ros2cpp_tutorials_service::srv::AddTwoInts_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2cpp_tutorials_service::srv::AddTwoInts_Request>()
{
  return ros2cpp_tutorials_service::srv::builder::Init_AddTwoInts_Request_a();
}

}  // namespace ros2cpp_tutorials_service


namespace ros2cpp_tutorials_service
{

namespace srv
{

namespace builder
{

class Init_AddTwoInts_Response_sum
{
public:
  Init_AddTwoInts_Response_sum()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2cpp_tutorials_service::srv::AddTwoInts_Response sum(::ros2cpp_tutorials_service::srv::AddTwoInts_Response::_sum_type arg)
  {
    msg_.sum = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2cpp_tutorials_service::srv::AddTwoInts_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2cpp_tutorials_service::srv::AddTwoInts_Response>()
{
  return ros2cpp_tutorials_service::srv::builder::Init_AddTwoInts_Response_sum();
}

}  // namespace ros2cpp_tutorials_service

#endif  // ROS2CPP_TUTORIALS_SERVICE__SRV__DETAIL__ADD_TWO_INTS__BUILDER_HPP_
