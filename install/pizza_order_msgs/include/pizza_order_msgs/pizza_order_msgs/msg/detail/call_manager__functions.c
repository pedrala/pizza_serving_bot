// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pizza_order_msgs:msg/CallManager.idl
// generated code does not contain a copyright notice
#include "pizza_order_msgs/msg/detail/call_manager__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
pizza_order_msgs__msg__CallManager__init(pizza_order_msgs__msg__CallManager * msg)
{
  if (!msg) {
    return false;
  }
  // table_number
  return true;
}

void
pizza_order_msgs__msg__CallManager__fini(pizza_order_msgs__msg__CallManager * msg)
{
  if (!msg) {
    return;
  }
  // table_number
}

bool
pizza_order_msgs__msg__CallManager__are_equal(const pizza_order_msgs__msg__CallManager * lhs, const pizza_order_msgs__msg__CallManager * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // table_number
  if (lhs->table_number != rhs->table_number) {
    return false;
  }
  return true;
}

bool
pizza_order_msgs__msg__CallManager__copy(
  const pizza_order_msgs__msg__CallManager * input,
  pizza_order_msgs__msg__CallManager * output)
{
  if (!input || !output) {
    return false;
  }
  // table_number
  output->table_number = input->table_number;
  return true;
}

pizza_order_msgs__msg__CallManager *
pizza_order_msgs__msg__CallManager__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pizza_order_msgs__msg__CallManager * msg = (pizza_order_msgs__msg__CallManager *)allocator.allocate(sizeof(pizza_order_msgs__msg__CallManager), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pizza_order_msgs__msg__CallManager));
  bool success = pizza_order_msgs__msg__CallManager__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pizza_order_msgs__msg__CallManager__destroy(pizza_order_msgs__msg__CallManager * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pizza_order_msgs__msg__CallManager__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pizza_order_msgs__msg__CallManager__Sequence__init(pizza_order_msgs__msg__CallManager__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pizza_order_msgs__msg__CallManager * data = NULL;

  if (size) {
    data = (pizza_order_msgs__msg__CallManager *)allocator.zero_allocate(size, sizeof(pizza_order_msgs__msg__CallManager), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pizza_order_msgs__msg__CallManager__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pizza_order_msgs__msg__CallManager__fini(&data[i - 1]);
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
pizza_order_msgs__msg__CallManager__Sequence__fini(pizza_order_msgs__msg__CallManager__Sequence * array)
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
      pizza_order_msgs__msg__CallManager__fini(&array->data[i]);
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

pizza_order_msgs__msg__CallManager__Sequence *
pizza_order_msgs__msg__CallManager__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pizza_order_msgs__msg__CallManager__Sequence * array = (pizza_order_msgs__msg__CallManager__Sequence *)allocator.allocate(sizeof(pizza_order_msgs__msg__CallManager__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pizza_order_msgs__msg__CallManager__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pizza_order_msgs__msg__CallManager__Sequence__destroy(pizza_order_msgs__msg__CallManager__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pizza_order_msgs__msg__CallManager__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pizza_order_msgs__msg__CallManager__Sequence__are_equal(const pizza_order_msgs__msg__CallManager__Sequence * lhs, const pizza_order_msgs__msg__CallManager__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pizza_order_msgs__msg__CallManager__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pizza_order_msgs__msg__CallManager__Sequence__copy(
  const pizza_order_msgs__msg__CallManager__Sequence * input,
  pizza_order_msgs__msg__CallManager__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pizza_order_msgs__msg__CallManager);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pizza_order_msgs__msg__CallManager * data =
      (pizza_order_msgs__msg__CallManager *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pizza_order_msgs__msg__CallManager__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pizza_order_msgs__msg__CallManager__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pizza_order_msgs__msg__CallManager__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
