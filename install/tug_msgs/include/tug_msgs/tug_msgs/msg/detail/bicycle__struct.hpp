// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tug_msgs:msg/Bicycle.idl
// generated code does not contain a copyright notice

#ifndef TUG_MSGS__MSG__DETAIL__BICYCLE__STRUCT_HPP_
#define TUG_MSGS__MSG__DETAIL__BICYCLE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tug_msgs__msg__Bicycle __attribute__((deprecated))
#else
# define DEPRECATED__tug_msgs__msg__Bicycle __declspec(deprecated)
#endif

namespace tug_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Bicycle_
{
  using Type = Bicycle_<ContainerAllocator>;

  explicit Bicycle_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->velocity = 0.0;
      this->steering_angle = 0.0;
    }
  }

  explicit Bicycle_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->velocity = 0.0;
      this->steering_angle = 0.0;
    }
  }

  // field types and members
  using _velocity_type =
    double;
  _velocity_type velocity;
  using _steering_angle_type =
    double;
  _steering_angle_type steering_angle;

  // setters for named parameter idiom
  Type & set__velocity(
    const double & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__steering_angle(
    const double & _arg)
  {
    this->steering_angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tug_msgs::msg::Bicycle_<ContainerAllocator> *;
  using ConstRawPtr =
    const tug_msgs::msg::Bicycle_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tug_msgs::msg::Bicycle_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tug_msgs::msg::Bicycle_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tug_msgs::msg::Bicycle_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tug_msgs::msg::Bicycle_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tug_msgs::msg::Bicycle_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tug_msgs::msg::Bicycle_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tug_msgs::msg::Bicycle_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tug_msgs::msg::Bicycle_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tug_msgs__msg__Bicycle
    std::shared_ptr<tug_msgs::msg::Bicycle_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tug_msgs__msg__Bicycle
    std::shared_ptr<tug_msgs::msg::Bicycle_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Bicycle_ & other) const
  {
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->steering_angle != other.steering_angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const Bicycle_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Bicycle_

// alias to use template instance with default allocator
using Bicycle =
  tug_msgs::msg::Bicycle_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tug_msgs

#endif  // TUG_MSGS__MSG__DETAIL__BICYCLE__STRUCT_HPP_
