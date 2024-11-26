// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pizza_order_msgs:msg/OrderDetail.idl
// generated code does not contain a copyright notice
#include "pizza_order_msgs/msg/detail/order_detail__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `item_name`
#include "rosidl_runtime_c/string_functions.h"

bool
pizza_order_msgs__msg__OrderDetail__init(pizza_order_msgs__msg__OrderDetail * msg)
{
  if (!msg) {
    return false;
  }
  // detail_id
  // item_id
  // item_name
  if (!rosidl_runtime_c__String__init(&msg->item_name)) {
    pizza_order_msgs__msg__OrderDetail__fini(msg);
    return false;
  }
  // quantity
  // price
  return true;
}

void
pizza_order_msgs__msg__OrderDetail__fini(pizza_order_msgs__msg__OrderDetail * msg)
{
  if (!msg) {
    return;
  }
  // detail_id
  // item_id
  // item_name
  rosidl_runtime_c__String__fini(&msg->item_name);
  // quantity
  // price
}

bool
pizza_order_msgs__msg__OrderDetail__are_equal(const pizza_order_msgs__msg__OrderDetail * lhs, const pizza_order_msgs__msg__OrderDetail * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // detail_id
  if (lhs->detail_id != rhs->detail_id) {
    return false;
  }
  // item_id
  if (lhs->item_id != rhs->item_id) {
    return false;
  }
  // item_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->item_name), &(rhs->item_name)))
  {
    return false;
  }
  // quantity
  if (lhs->quantity != rhs->quantity) {
    return false;
  }
  // price
  if (lhs->price != rhs->price) {
    return false;
  }
  return true;
}

bool
pizza_order_msgs__msg__OrderDetail__copy(
  const pizza_order_msgs__msg__OrderDetail * input,
  pizza_order_msgs__msg__OrderDetail * output)
{
  if (!input || !output) {
    return false;
  }
  // detail_id
  output->detail_id = input->detail_id;
  // item_id
  output->item_id = input->item_id;
  // item_name
  if (!rosidl_runtime_c__String__copy(
      &(input->item_name), &(output->item_name)))
  {
    return false;
  }
  // quantity
  output->quantity = input->quantity;
  // price
  output->price = input->price;
  return true;
}

pizza_order_msgs__msg__OrderDetail *
pizza_order_msgs__msg__OrderDetail__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pizza_order_msgs__msg__OrderDetail * msg = (pizza_order_msgs__msg__OrderDetail *)allocator.allocate(sizeof(pizza_order_msgs__msg__OrderDetail), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pizza_order_msgs__msg__OrderDetail));
  bool success = pizza_order_msgs__msg__OrderDetail__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pizza_order_msgs__msg__OrderDetail__destroy(pizza_order_msgs__msg__OrderDetail * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pizza_order_msgs__msg__OrderDetail__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pizza_order_msgs__msg__OrderDetail__Sequence__init(pizza_order_msgs__msg__OrderDetail__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pizza_order_msgs__msg__OrderDetail * data = NULL;

  if (size) {
    data = (pizza_order_msgs__msg__OrderDetail *)allocator.zero_allocate(size, sizeof(pizza_order_msgs__msg__OrderDetail), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pizza_order_msgs__msg__OrderDetail__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pizza_order_msgs__msg__OrderDetail__fini(&data[i - 1]);
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
pizza_order_msgs__msg__OrderDetail__Sequence__fini(pizza_order_msgs__msg__OrderDetail__Sequence * array)
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
      pizza_order_msgs__msg__OrderDetail__fini(&array->data[i]);
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

pizza_order_msgs__msg__OrderDetail__Sequence *
pizza_order_msgs__msg__OrderDetail__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pizza_order_msgs__msg__OrderDetail__Sequence * array = (pizza_order_msgs__msg__OrderDetail__Sequence *)allocator.allocate(sizeof(pizza_order_msgs__msg__OrderDetail__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pizza_order_msgs__msg__OrderDetail__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pizza_order_msgs__msg__OrderDetail__Sequence__destroy(pizza_order_msgs__msg__OrderDetail__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pizza_order_msgs__msg__OrderDetail__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pizza_order_msgs__msg__OrderDetail__Sequence__are_equal(const pizza_order_msgs__msg__OrderDetail__Sequence * lhs, const pizza_order_msgs__msg__OrderDetail__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pizza_order_msgs__msg__OrderDetail__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pizza_order_msgs__msg__OrderDetail__Sequence__copy(
  const pizza_order_msgs__msg__OrderDetail__Sequence * input,
  pizza_order_msgs__msg__OrderDetail__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pizza_order_msgs__msg__OrderDetail);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pizza_order_msgs__msg__OrderDetail * data =
      (pizza_order_msgs__msg__OrderDetail *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pizza_order_msgs__msg__OrderDetail__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pizza_order_msgs__msg__OrderDetail__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pizza_order_msgs__msg__OrderDetail__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
