// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from tug_msgs:msg/Bicycle.idl
// generated code does not contain a copyright notice

#ifndef TUG_MSGS__MSG__DETAIL__BICYCLE__FUNCTIONS_H_
#define TUG_MSGS__MSG__DETAIL__BICYCLE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "tug_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "tug_msgs/msg/detail/bicycle__struct.h"

/// Initialize msg/Bicycle message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tug_msgs__msg__Bicycle
 * )) before or use
 * tug_msgs__msg__Bicycle__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tug_msgs
bool
tug_msgs__msg__Bicycle__init(tug_msgs__msg__Bicycle * msg);

/// Finalize msg/Bicycle message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tug_msgs
void
tug_msgs__msg__Bicycle__fini(tug_msgs__msg__Bicycle * msg);

/// Create msg/Bicycle message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tug_msgs__msg__Bicycle__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tug_msgs
tug_msgs__msg__Bicycle *
tug_msgs__msg__Bicycle__create();

/// Destroy msg/Bicycle message.
/**
 * It calls
 * tug_msgs__msg__Bicycle__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tug_msgs
void
tug_msgs__msg__Bicycle__destroy(tug_msgs__msg__Bicycle * msg);

/// Check for msg/Bicycle message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tug_msgs
bool
tug_msgs__msg__Bicycle__are_equal(const tug_msgs__msg__Bicycle * lhs, const tug_msgs__msg__Bicycle * rhs);

/// Copy a msg/Bicycle message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tug_msgs
bool
tug_msgs__msg__Bicycle__copy(
  const tug_msgs__msg__Bicycle * input,
  tug_msgs__msg__Bicycle * output);

/// Initialize array of msg/Bicycle messages.
/**
 * It allocates the memory for the number of elements and calls
 * tug_msgs__msg__Bicycle__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tug_msgs
bool
tug_msgs__msg__Bicycle__Sequence__init(tug_msgs__msg__Bicycle__Sequence * array, size_t size);

/// Finalize array of msg/Bicycle messages.
/**
 * It calls
 * tug_msgs__msg__Bicycle__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tug_msgs
void
tug_msgs__msg__Bicycle__Sequence__fini(tug_msgs__msg__Bicycle__Sequence * array);

/// Create array of msg/Bicycle messages.
/**
 * It allocates the memory for the array and calls
 * tug_msgs__msg__Bicycle__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tug_msgs
tug_msgs__msg__Bicycle__Sequence *
tug_msgs__msg__Bicycle__Sequence__create(size_t size);

/// Destroy array of msg/Bicycle messages.
/**
 * It calls
 * tug_msgs__msg__Bicycle__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tug_msgs
void
tug_msgs__msg__Bicycle__Sequence__destroy(tug_msgs__msg__Bicycle__Sequence * array);

/// Check for msg/Bicycle message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tug_msgs
bool
tug_msgs__msg__Bicycle__Sequence__are_equal(const tug_msgs__msg__Bicycle__Sequence * lhs, const tug_msgs__msg__Bicycle__Sequence * rhs);

/// Copy an array of msg/Bicycle messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tug_msgs
bool
tug_msgs__msg__Bicycle__Sequence__copy(
  const tug_msgs__msg__Bicycle__Sequence * input,
  tug_msgs__msg__Bicycle__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TUG_MSGS__MSG__DETAIL__BICYCLE__FUNCTIONS_H_