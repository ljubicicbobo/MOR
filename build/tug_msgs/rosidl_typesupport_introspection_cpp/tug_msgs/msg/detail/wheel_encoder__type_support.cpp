// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from tug_msgs:msg/WheelEncoder.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "tug_msgs/msg/detail/wheel_encoder__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace tug_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void WheelEncoder_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tug_msgs::msg::WheelEncoder(_init);
}

void WheelEncoder_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tug_msgs::msg::WheelEncoder *>(message_memory);
  typed_message->~WheelEncoder();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember WheelEncoder_message_member_array[2] = {
  {
    "left_counter",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tug_msgs::msg::WheelEncoder, left_counter),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "right_counter",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tug_msgs::msg::WheelEncoder, right_counter),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers WheelEncoder_message_members = {
  "tug_msgs::msg",  // message namespace
  "WheelEncoder",  // message name
  2,  // number of fields
  sizeof(tug_msgs::msg::WheelEncoder),
  WheelEncoder_message_member_array,  // message members
  WheelEncoder_init_function,  // function to initialize message memory (memory has to be allocated)
  WheelEncoder_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t WheelEncoder_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &WheelEncoder_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace tug_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tug_msgs::msg::WheelEncoder>()
{
  return &::tug_msgs::msg::rosidl_typesupport_introspection_cpp::WheelEncoder_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tug_msgs, msg, WheelEncoder)() {
  return &::tug_msgs::msg::rosidl_typesupport_introspection_cpp::WheelEncoder_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif