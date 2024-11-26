// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pizza_order_msgs:msg/OrderInfo.idl
// generated code does not contain a copyright notice
#include "pizza_order_msgs/msg/detail/order_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `status`
#include "rosidl_runtime_c/string_functions.h"

bool
pizza_order_msgs__msg__OrderInfo__init(pizza_order_msgs__msg__OrderInfo * msg)
{
  if (!msg) {
    return false;
  }
  // order_id
  // table_number
  // status
  if (!rosidl_runtime_c__String__init(&msg->status)) {
    pizza_order_msgs__msg__OrderInfo__fini(msg);
    return false;
  }
  return true;
}

void
pizza_order_msgs__msg__OrderInfo__fini(pizza_order_msgs__msg__OrderInfo * msg)
{
  if (!msg) {
    return;
  }
  // order_id
  // table_number
  // status
  rosidl_runtime_c__String__fini(&msg->status);
}

bool
pizza_order_msgs__msg__OrderInfo__are_equal(const pizza_order_msgs__msg__OrderInfo * lhs, const pizza_order_msgs__msg__OrderInfo * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // order_id
  if (lhs->order_id != rhs->order_id) {
    return false;
  }
  // table_number
  if (lhs->table_number != rhs->table_number) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  return true;
}

bool
pizza_order_msgs__msg__OrderInfo__copy(
  const pizza_order_msgs__msg__OrderInfo * input,
  pizza_order_msgs__msg__OrderInfo * output)
{
  if (!input || !output) {
    return false;
  }
  // order_id
  output->order_id = input->order_id;
  // table_number
  output->table_number = input->table_number;
  // status
  if (!rosidl_runtime_c__String__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  return true;
}

pizza_order_msgs__msg__OrderInfo *
pizza_order_msgs__msg__OrderInfo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pizza_order_msgs__msg__OrderInfo * msg = (pizza_order_msgs__msg__OrderInfo *)allocator.allocate(sizeof(pizza_order_msgs__msg__OrderInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pizza_order_msgs__msg__OrderInfo));
  bool success = pizza_order_msgs__msg__OrderInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pizza_order_msgs__msg__OrderInfo__destroy(pizza_order_msgs__msg__OrderInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pizza_order_msgs__msg__OrderInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pizza_order_msgs__msg__OrderInfo__Sequence__init(pizza_order_msgs__msg__OrderInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pizza_order_msgs__msg__OrderInfo * data = NULL;

  if (size) {
    data = (pizza_order_msgs__msg__OrderInfo *)allocator.zero_allocate(size, sizeof(pizza_order_msgs__msg__OrderInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pizza_order_msgs__msg__OrderInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pizza_order_msgs__msg__OrderInfo__fini(&data[i - 1]);
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
pizza_order_msgs__msg__OrderInfo__Sequence__fini(pizza_order_msgs__msg__OrderInfo__Sequence * array)
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
      pizza_order_msgs__msg__OrderInfo__fini(&array->data[i]);
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

pizza_order_msgs__msg__OrderInfo__Sequence *
pizza_order_msgs__msg__OrderInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pizza_order_msgs__msg__OrderInfo__Sequence * array = (pizza_order_msgs__msg__OrderInfo__Sequence *)allocator.allocate(sizeof(pizza_order_msgs__msg__OrderInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pizza_order_msgs__msg__OrderInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pizza_order_msgs__msg__OrderInfo__Sequence__destroy(pizza_order_msgs__msg__OrderInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pizza_order_msgs__msg__OrderInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pizza_order_msgs__msg__OrderInfo__Sequence__are_equal(const pizza_order_msgs__msg__OrderInfo__Sequence * lhs, const pizza_order_msgs__msg__OrderInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pizza_order_msgs__msg__OrderInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pizza_order_msgs__msg__OrderInfo__Sequence__copy(
  const pizza_order_msgs__msg__OrderInfo__Sequence * input,
  pizza_order_msgs__msg__OrderInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pizza_order_msgs__msg__OrderInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pizza_order_msgs__msg__OrderInfo * data =
      (pizza_order_msgs__msg__OrderInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pizza_order_msgs__msg__OrderInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pizza_order_msgs__msg__OrderInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pizza_order_msgs__msg__OrderInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
