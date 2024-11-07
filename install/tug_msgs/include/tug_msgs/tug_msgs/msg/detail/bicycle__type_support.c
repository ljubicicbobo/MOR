// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tug_msgs:msg/Bicycle.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tug_msgs/msg/detail/bicycle__rosidl_typesupport_introspection_c.h"
#include "tug_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tug_msgs/msg/detail/bicycle__functions.h"
#include "tug_msgs/msg/detail/bicycle__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void tug_msgs__msg__Bicycle__rosidl_typesupport_introspection_c__Bicycle_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tug_msgs__msg__Bicycle__init(message_memory);
}

void tug_msgs__msg__Bicycle__rosidl_typesupport_introspection_c__Bicycle_fini_function(void * message_memory)
{
  tug_msgs__msg__Bicycle__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tug_msgs__msg__Bicycle__rosidl_typesupport_introspection_c__Bicycle_message_member_array[2] = {
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tug_msgs__msg__Bicycle, velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "steering_angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tug_msgs__msg__Bicycle, steering_angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tug_msgs__msg__Bicycle__rosidl_typesupport_introspection_c__Bicycle_message_members = {
  "tug_msgs__msg",  // message namespace
  "Bicycle",  // message name
  2,  // number of fields
  sizeof(tug_msgs__msg__Bicycle),
  tug_msgs__msg__Bicycle__rosidl_typesupport_introspection_c__Bicycle_message_member_array,  // message members
  tug_msgs__msg__Bicycle__rosidl_typesupport_introspection_c__Bicycle_init_function,  // function to initialize message memory (memory has to be allocated)
  tug_msgs__msg__Bicycle__rosidl_typesupport_introspection_c__Bicycle_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tug_msgs__msg__Bicycle__rosidl_typesupport_introspection_c__Bicycle_message_type_support_handle = {
  0,
  &tug_msgs__msg__Bicycle__rosidl_typesupport_introspection_c__Bicycle_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tug_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tug_msgs, msg, Bicycle)() {
  if (!tug_msgs__msg__Bicycle__rosidl_typesupport_introspection_c__Bicycle_message_type_support_handle.typesupport_identifier) {
    tug_msgs__msg__Bicycle__rosidl_typesupport_introspection_c__Bicycle_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tug_msgs__msg__Bicycle__rosidl_typesupport_introspection_c__Bicycle_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif