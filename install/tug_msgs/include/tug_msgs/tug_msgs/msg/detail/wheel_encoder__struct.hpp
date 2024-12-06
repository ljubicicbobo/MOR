// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tug_msgs:msg/WheelEncoder.idl
// generated code does not contain a copyright notice

#ifndef TUG_MSGS__MSG__DETAIL__WHEEL_ENCODER__STRUCT_HPP_
#define TUG_MSGS__MSG__DETAIL__WHEEL_ENCODER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tug_msgs__msg__WheelEncoder __attribute__((deprecated))
#else
# define DEPRECATED__tug_msgs__msg__WheelEncoder __declspec(deprecated)
#endif

namespace tug_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct WheelEncoder_
{
  using Type = WheelEncoder_<ContainerAllocator>;

  explicit WheelEncoder_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_counter = 0;
      this->right_counter = 0;
    }
  }

  explicit WheelEncoder_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_counter = 0;
      this->right_counter = 0;
    }
  }

  // field types and members
  using _left_counter_type =
    uint16_t;
  _left_counter_type left_counter;
  using _right_counter_type =
    uint16_t;
  _right_counter_type right_counter;

  // setters for named parameter idiom
  Type & set__left_counter(
    const uint16_t & _arg)
  {
    this->left_counter = _arg;
    return *this;
  }
  Type & set__right_counter(
    const uint16_t & _arg)
  {
    this->right_counter = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tug_msgs::msg::WheelEncoder_<ContainerAllocator> *;
  using ConstRawPtr =
    const tug_msgs::msg::WheelEncoder_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tug_msgs::msg::WheelEncoder_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tug_msgs::msg::WheelEncoder_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tug_msgs::msg::WheelEncoder_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tug_msgs::msg::WheelEncoder_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tug_msgs::msg::WheelEncoder_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tug_msgs::msg::WheelEncoder_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tug_msgs::msg::WheelEncoder_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tug_msgs::msg::WheelEncoder_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tug_msgs__msg__WheelEncoder
    std::shared_ptr<tug_msgs::msg::WheelEncoder_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tug_msgs__msg__WheelEncoder
    std::shared_ptr<tug_msgs::msg::WheelEncoder_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WheelEncoder_ & other) const
  {
    if (this->left_counter != other.left_counter) {
      return false;
    }
    if (this->right_counter != other.right_counter) {
      return false;
    }
    return true;
  }
  bool operator!=(const WheelEncoder_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WheelEncoder_

// alias to use template instance with default allocator
using WheelEncoder =
  tug_msgs::msg::WheelEncoder_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tug_msgs

#endif  // TUG_MSGS__MSG__DETAIL__WHEEL_ENCODER__STRUCT_HPP_
