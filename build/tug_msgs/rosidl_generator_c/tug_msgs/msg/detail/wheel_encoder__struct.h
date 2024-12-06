// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tug_msgs:msg/WheelEncoder.idl
// generated code does not contain a copyright notice

#ifndef TUG_MSGS__MSG__DETAIL__WHEEL_ENCODER__STRUCT_H_
#define TUG_MSGS__MSG__DETAIL__WHEEL_ENCODER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/WheelEncoder in the package tug_msgs.
/**
  * Wheel encoder counters
 */
typedef struct tug_msgs__msg__WheelEncoder
{
  uint16_t left_counter;
  uint16_t right_counter;
} tug_msgs__msg__WheelEncoder;

// Struct for a sequence of tug_msgs__msg__WheelEncoder.
typedef struct tug_msgs__msg__WheelEncoder__Sequence
{
  tug_msgs__msg__WheelEncoder * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tug_msgs__msg__WheelEncoder__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUG_MSGS__MSG__DETAIL__WHEEL_ENCODER__STRUCT_H_
