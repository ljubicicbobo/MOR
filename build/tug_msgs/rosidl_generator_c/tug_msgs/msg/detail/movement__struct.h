// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tug_msgs:msg/Movement.idl
// generated code does not contain a copyright notice

#ifndef TUG_MSGS__MSG__DETAIL__MOVEMENT__STRUCT_H_
#define TUG_MSGS__MSG__DETAIL__MOVEMENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'MOVEMENT_POSE'.
enum
{
  tug_msgs__msg__Movement__MOVEMENT_POSE = 0
};

/// Constant 'MOVEMENT_VELOCITY'.
enum
{
  tug_msgs__msg__Movement__MOVEMENT_VELOCITY = 1
};

/// Constant 'MOVEMENT_BICYCLE'.
enum
{
  tug_msgs__msg__Movement__MOVEMENT_BICYCLE = 2
};

/// Struct defined in msg/Movement in the package tug_msgs.
typedef struct tug_msgs__msg__Movement
{
  uint8_t mode;
} tug_msgs__msg__Movement;

// Struct for a sequence of tug_msgs__msg__Movement.
typedef struct tug_msgs__msg__Movement__Sequence
{
  tug_msgs__msg__Movement * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tug_msgs__msg__Movement__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUG_MSGS__MSG__DETAIL__MOVEMENT__STRUCT_H_
