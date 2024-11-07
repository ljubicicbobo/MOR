// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2cpp_tutorials_service:srv/AddTwoInts.idl
// generated code does not contain a copyright notice

#ifndef ROS2CPP_TUTORIALS_SERVICE__SRV__DETAIL__ADD_TWO_INTS__STRUCT_H_
#define ROS2CPP_TUTORIALS_SERVICE__SRV__DETAIL__ADD_TWO_INTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/AddTwoInts in the package ros2cpp_tutorials_service.
typedef struct ros2cpp_tutorials_service__srv__AddTwoInts_Request
{
  int64_t a;
  int64_t b;
} ros2cpp_tutorials_service__srv__AddTwoInts_Request;

// Struct for a sequence of ros2cpp_tutorials_service__srv__AddTwoInts_Request.
typedef struct ros2cpp_tutorials_service__srv__AddTwoInts_Request__Sequence
{
  ros2cpp_tutorials_service__srv__AddTwoInts_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2cpp_tutorials_service__srv__AddTwoInts_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/AddTwoInts in the package ros2cpp_tutorials_service.
typedef struct ros2cpp_tutorials_service__srv__AddTwoInts_Response
{
  int64_t sum;
} ros2cpp_tutorials_service__srv__AddTwoInts_Response;

// Struct for a sequence of ros2cpp_tutorials_service__srv__AddTwoInts_Response.
typedef struct ros2cpp_tutorials_service__srv__AddTwoInts_Response__Sequence
{
  ros2cpp_tutorials_service__srv__AddTwoInts_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2cpp_tutorials_service__srv__AddTwoInts_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2CPP_TUTORIALS_SERVICE__SRV__DETAIL__ADD_TWO_INTS__STRUCT_H_
