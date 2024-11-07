// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tug_msgs:msg/Bicycle.idl
// generated code does not contain a copyright notice
#include "tug_msgs/msg/detail/bicycle__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
tug_msgs__msg__Bicycle__init(tug_msgs__msg__Bicycle * msg)
{
  if (!msg) {
    return false;
  }
  // velocity
  // steering_angle
  return true;
}

void
tug_msgs__msg__Bicycle__fini(tug_msgs__msg__Bicycle * msg)
{
  if (!msg) {
    return;
  }
  // velocity
  // steering_angle
}

bool
tug_msgs__msg__Bicycle__are_equal(const tug_msgs__msg__Bicycle * lhs, const tug_msgs__msg__Bicycle * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // velocity
  if (lhs->velocity != rhs->velocity) {
    return false;
  }
  // steering_angle
  if (lhs->steering_angle != rhs->steering_angle) {
    return false;
  }
  return true;
}

bool
tug_msgs__msg__Bicycle__copy(
  const tug_msgs__msg__Bicycle * input,
  tug_msgs__msg__Bicycle * output)
{
  if (!input || !output) {
    return false;
  }
  // velocity
  output->velocity = input->velocity;
  // steering_angle
  output->steering_angle = input->steering_angle;
  return true;
}

tug_msgs__msg__Bicycle *
tug_msgs__msg__Bicycle__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tug_msgs__msg__Bicycle * msg = (tug_msgs__msg__Bicycle *)allocator.allocate(sizeof(tug_msgs__msg__Bicycle), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tug_msgs__msg__Bicycle));
  bool success = tug_msgs__msg__Bicycle__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tug_msgs__msg__Bicycle__destroy(tug_msgs__msg__Bicycle * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tug_msgs__msg__Bicycle__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tug_msgs__msg__Bicycle__Sequence__init(tug_msgs__msg__Bicycle__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tug_msgs__msg__Bicycle * data = NULL;

  if (size) {
    data = (tug_msgs__msg__Bicycle *)allocator.zero_allocate(size, sizeof(tug_msgs__msg__Bicycle), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tug_msgs__msg__Bicycle__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tug_msgs__msg__Bicycle__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tug_msgs__msg__Bicycle__Sequence__fini(tug_msgs__msg__Bicycle__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tug_msgs__msg__Bicycle__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tug_msgs__msg__Bicycle__Sequence *
tug_msgs__msg__Bicycle__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tug_msgs__msg__Bicycle__Sequence * array = (tug_msgs__msg__Bicycle__Sequence *)allocator.allocate(sizeof(tug_msgs__msg__Bicycle__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tug_msgs__msg__Bicycle__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tug_msgs__msg__Bicycle__Sequence__destroy(tug_msgs__msg__Bicycle__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tug_msgs__msg__Bicycle__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tug_msgs__msg__Bicycle__Sequence__are_equal(const tug_msgs__msg__Bicycle__Sequence * lhs, const tug_msgs__msg__Bicycle__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tug_msgs__msg__Bicycle__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tug_msgs__msg__Bicycle__Sequence__copy(
  const tug_msgs__msg__Bicycle__Sequence * input,
  tug_msgs__msg__Bicycle__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tug_msgs__msg__Bicycle);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tug_msgs__msg__Bicycle * data =
      (tug_msgs__msg__Bicycle *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tug_msgs__msg__Bicycle__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tug_msgs__msg__Bicycle__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tug_msgs__msg__Bicycle__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
