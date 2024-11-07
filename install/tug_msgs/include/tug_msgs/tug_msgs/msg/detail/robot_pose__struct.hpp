// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tug_msgs:msg/RobotPose.idl
// generated code does not contain a copyright notice

#ifndef TUG_MSGS__MSG__DETAIL__ROBOT_POSE__STRUCT_HPP_
#define TUG_MSGS__MSG__DETAIL__ROBOT_POSE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tug_msgs__msg__RobotPose __attribute__((deprecated))
#else
# define DEPRECATED__tug_msgs__msg__RobotPose __declspec(deprecated)
#endif

namespace tug_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotPose_
{
  using Type = RobotPose_<ContainerAllocator>;

  explicit RobotPose_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->yaw = 0.0;
    }
  }

  explicit RobotPose_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->yaw = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _yaw_type =
    double;
  _yaw_type yaw;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__yaw(
    const double & _arg)
  {
    this->yaw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tug_msgs::msg::RobotPose_<ContainerAllocator> *;
  using ConstRawPtr =
    const tug_msgs::msg::RobotPose_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tug_msgs::msg::RobotPose_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tug_msgs::msg::RobotPose_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tug_msgs::msg::RobotPose_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tug_msgs::msg::RobotPose_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tug_msgs::msg::RobotPose_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tug_msgs::msg::RobotPose_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tug_msgs::msg::RobotPose_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tug_msgs::msg::RobotPose_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tug_msgs__msg__RobotPose
    std::shared_ptr<tug_msgs::msg::RobotPose_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tug_msgs__msg__RobotPose
    std::shared_ptr<tug_msgs::msg::RobotPose_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotPose_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotPose_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotPose_

// alias to use template instance with default allocator
using RobotPose =
  tug_msgs::msg::RobotPose_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tug_msgs

#endif  // TUG_MSGS__MSG__DETAIL__ROBOT_POSE__STRUCT_HPP_
