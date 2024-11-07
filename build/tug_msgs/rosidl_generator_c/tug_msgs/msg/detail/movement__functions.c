// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tug_msgs:msg/Movement.idl
// generated code does not contain a copyright notice
#include "tug_msgs/msg/detail/movement__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
tug_msgs__msg__Movement__init(tug_msgs__msg__Movement * msg)
{
  if (!msg) {
    return false;
  }
  // mode
  return true;
}

void
tug_msgs__msg__Movement__fini(tug_msgs__msg__Movement * msg)
{
  if (!msg) {
    return;
  }
  // mode
}

bool
tug_msgs__msg__Movement__are_equal(const tug_msgs__msg__Movement * lhs, const tug_msgs__msg__Movement * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  return true;
}

bool
tug_msgs__msg__Movement__copy(
  const tug_msgs__msg__Movement * input,
  tug_msgs__msg__Movement * output)
{
  if (!input || !output) {
    return false;
  }
  // mode
  output->mode = input->mode;
  return true;
}

tug_msgs__msg__Movement *
tug_msgs__msg__Movement__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tug_msgs__msg__Movement * msg = (tug_msgs__msg__Movement *)allocator.allocate(sizeof(tug_msgs__msg__Movement), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tug_msgs__msg__Movement));
  bool success = tug_msgs__msg__Movement__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tug_msgs__msg__Movement__destroy(tug_msgs__msg__Movement * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tug_msgs__msg__Movement__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tug_msgs__msg__Movement__Sequence__init(tug_msgs__msg__Movement__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tug_msgs__msg__Movement * data = NULL;

  if (size) {
    data = (tug_msgs__msg__Movement *)allocator.zero_allocate(size, sizeof(tug_msgs__msg__Movement), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tug_msgs__msg__Movement__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tug_msgs__msg__Movement__fini(&data[i - 1]);
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
tug_msgs__msg__Movement__Sequence__fini(tug_msgs__msg__Movement__Sequence * array)
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
      tug_msgs__msg__Movement__fini(&array->data[i]);
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

tug_msgs__msg__Movement__Sequence *
tug_msgs__msg__Movement__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tug_msgs__msg__Movement__Sequence * array = (tug_msgs__msg__Movement__Sequence *)allocator.allocate(sizeof(tug_msgs__msg__Movement__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tug_msgs__msg__Movement__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tug_msgs__msg__Movement__Sequence__destroy(tug_msgs__msg__Movement__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tug_msgs__msg__Movement__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tug_msgs__msg__Movement__Sequence__are_equal(const tug_msgs__msg__Movement__Sequence * lhs, const tug_msgs__msg__Movement__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tug_msgs__msg__Movement__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tug_msgs__msg__Movement__Sequence__copy(
  const tug_msgs__msg__Movement__Sequence * input,
  tug_msgs__msg__Movement__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tug_msgs__msg__Movement);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tug_msgs__msg__Movement * data =
      (tug_msgs__msg__Movement *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tug_msgs__msg__Movement__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tug_msgs__msg__Movement__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tug_msgs__msg__Movement__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
