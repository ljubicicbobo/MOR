// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tug_msgs:msg/RobotPose.idl
// generated code does not contain a copyright notice

#ifndef TUG_MSGS__MSG__DETAIL__ROBOT_POSE__STRUCT_H_
#define TUG_MSGS__MSG__DETAIL__ROBOT_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/RobotPose in the package tug_msgs.
/**
  * Set the robot's pose
 */
typedef struct tug_msgs__msg__RobotPose
{
  double x;
  double y;
  double yaw;
} tug_msgs__msg__RobotPose;

// Struct for a sequence of tug_msgs__msg__RobotPose.
typedef struct tug_msgs__msg__RobotPose__Sequence
{
  tug_msgs__msg__RobotPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tug_msgs__msg__RobotPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUG_MSGS__MSG__DETAIL__ROBOT_POSE__STRUCT_H_
