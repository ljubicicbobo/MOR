// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tug_msgs:msg/WheelEncoder.idl
// generated code does not contain a copyright notice
#include "tug_msgs/msg/detail/wheel_encoder__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
tug_msgs__msg__WheelEncoder__init(tug_msgs__msg__WheelEncoder * msg)
{
  if (!msg) {
    return false;
  }
  // left_counter
  // right_counter
  return true;
}

void
tug_msgs__msg__WheelEncoder__fini(tug_msgs__msg__WheelEncoder * msg)
{
  if (!msg) {
    return;
  }
  // left_counter
  // right_counter
}

bool
tug_msgs__msg__WheelEncoder__are_equal(const tug_msgs__msg__WheelEncoder * lhs, const tug_msgs__msg__WheelEncoder * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // left_counter
  if (lhs->left_counter != rhs->left_counter) {
    return false;
  }
  // right_counter
  if (lhs->right_counter != rhs->right_counter) {
    return false;
  }
  return true;
}

bool
tug_msgs__msg__WheelEncoder__copy(
  const tug_msgs__msg__WheelEncoder * input,
  tug_msgs__msg__WheelEncoder * output)
{
  if (!input || !output) {
    return false;
  }
  // left_counter
  output->left_counter = input->left_counter;
  // right_counter
  output->right_counter = input->right_counter;
  return true;
}

tug_msgs__msg__WheelEncoder *
tug_msgs__msg__WheelEncoder__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tug_msgs__msg__WheelEncoder * msg = (tug_msgs__msg__WheelEncoder *)allocator.allocate(sizeof(tug_msgs__msg__WheelEncoder), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tug_msgs__msg__WheelEncoder));
  bool success = tug_msgs__msg__WheelEncoder__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tug_msgs__msg__WheelEncoder__destroy(tug_msgs__msg__WheelEncoder * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tug_msgs__msg__WheelEncoder__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tug_msgs__msg__WheelEncoder__Sequence__init(tug_msgs__msg__WheelEncoder__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tug_msgs__msg__WheelEncoder * data = NULL;

  if (size) {
    data = (tug_msgs__msg__WheelEncoder *)allocator.zero_allocate(size, sizeof(tug_msgs__msg__WheelEncoder), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tug_msgs__msg__WheelEncoder__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tug_msgs__msg__WheelEncoder__fini(&data[i - 1]);
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
tug_msgs__msg__WheelEncoder__Sequence__fini(tug_msgs__msg__WheelEncoder__Sequence * array)
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
      tug_msgs__msg__WheelEncoder__fini(&array->data[i]);
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

tug_msgs__msg__WheelEncoder__Sequence *
tug_msgs__msg__WheelEncoder__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tug_msgs__msg__WheelEncoder__Sequence * array = (tug_msgs__msg__WheelEncoder__Sequence *)allocator.allocate(sizeof(tug_msgs__msg__WheelEncoder__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tug_msgs__msg__WheelEncoder__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tug_msgs__msg__WheelEncoder__Sequence__destroy(tug_msgs__msg__WheelEncoder__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tug_msgs__msg__WheelEncoder__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tug_msgs__msg__WheelEncoder__Sequence__are_equal(const tug_msgs__msg__WheelEncoder__Sequence * lhs, const tug_msgs__msg__WheelEncoder__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tug_msgs__msg__WheelEncoder__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tug_msgs__msg__WheelEncoder__Sequence__copy(
  const tug_msgs__msg__WheelEncoder__Sequence * input,
  tug_msgs__msg__WheelEncoder__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tug_msgs__msg__WheelEncoder);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tug_msgs__msg__WheelEncoder * data =
      (tug_msgs__msg__WheelEncoder *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tug_msgs__msg__WheelEncoder__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tug_msgs__msg__WheelEncoder__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tug_msgs__msg__WheelEncoder__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
