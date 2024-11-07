// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tug_msgs:msg/Movement.idl
// generated code does not contain a copyright notice

#ifndef TUG_MSGS__MSG__DETAIL__MOVEMENT__STRUCT_HPP_
#define TUG_MSGS__MSG__DETAIL__MOVEMENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tug_msgs__msg__Movement __attribute__((deprecated))
#else
# define DEPRECATED__tug_msgs__msg__Movement __declspec(deprecated)
#endif

namespace tug_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Movement_
{
  using Type = Movement_<ContainerAllocator>;

  explicit Movement_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
    }
  }

  explicit Movement_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
    }
  }

  // field types and members
  using _mode_type =
    uint8_t;
  _mode_type mode;

  // setters for named parameter idiom
  Type & set__mode(
    const uint8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t MOVEMENT_POSE =
    0u;
  static constexpr uint8_t MOVEMENT_VELOCITY =
    1u;
  static constexpr uint8_t MOVEMENT_BICYCLE =
    2u;

  // pointer types
  using RawPtr =
    tug_msgs::msg::Movement_<ContainerAllocator> *;
  using ConstRawPtr =
    const tug_msgs::msg::Movement_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tug_msgs::msg::Movement_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tug_msgs::msg::Movement_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tug_msgs::msg::Movement_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tug_msgs::msg::Movement_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tug_msgs::msg::Movement_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tug_msgs::msg::Movement_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tug_msgs::msg::Movement_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tug_msgs::msg::Movement_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tug_msgs__msg__Movement
    std::shared_ptr<tug_msgs::msg::Movement_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tug_msgs__msg__Movement
    std::shared_ptr<tug_msgs::msg::Movement_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Movement_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const Movement_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Movement_

// alias to use template instance with default allocator
using Movement =
  tug_msgs::msg::Movement_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Movement_<ContainerAllocator>::MOVEMENT_POSE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Movement_<ContainerAllocator>::MOVEMENT_VELOCITY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Movement_<ContainerAllocator>::MOVEMENT_BICYCLE;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace tug_msgs

#endif  // TUG_MSGS__MSG__DETAIL__MOVEMENT__STRUCT_HPP_
