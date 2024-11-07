// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tug_msgs:msg/Bicycle.idl
// generated code does not contain a copyright notice

#ifndef TUG_MSGS__MSG__DETAIL__BICYCLE__STRUCT_H_
#define TUG_MSGS__MSG__DETAIL__BICYCLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Bicycle in the package tug_msgs.
/**
  * Bicycle command
 */
typedef struct tug_msgs__msg__Bicycle
{
  double velocity;
  double steering_angle;
} tug_msgs__msg__Bicycle;

// Struct for a sequence of tug_msgs__msg__Bicycle.
typedef struct tug_msgs__msg__Bicycle__Sequence
{
  tug_msgs__msg__Bicycle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tug_msgs__msg__Bicycle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUG_MSGS__MSG__DETAIL__BICYCLE__STRUCT_H_
