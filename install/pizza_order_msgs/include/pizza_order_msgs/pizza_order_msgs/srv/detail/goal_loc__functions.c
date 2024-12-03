// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pizza_order_msgs:srv/GoalLoc.idl
// generated code does not contain a copyright notice
#include "pizza_order_msgs/srv/detail/goal_loc__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `status`
#include "rosidl_runtime_c/string_functions.h"

bool
pizza_order_msgs__srv__GoalLoc_Request__init(pizza_order_msgs__srv__GoalLoc_Request * msg)
{
  if (!msg) {
    return false;
  }
  // order_id
  // table_number
  // status
  if (!rosidl_runtime_c__String__init(&msg->status)) {
    pizza_order_msgs__srv__GoalLoc_Request__fini(msg);
    return false;
  }
  return true;
}

void
pizza_order_msgs__srv__GoalLoc_Request__fini(pizza_order_msgs__srv__GoalLoc_Request * msg)
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
pizza_order_msgs__srv__GoalLoc_Request__are_equal(const pizza_order_msgs__srv__GoalLoc_Request * lhs, const pizza_order_msgs__srv__GoalLoc_Request * rhs)
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
pizza_order_msgs__srv__GoalLoc_Request__copy(
  const pizza_order_msgs__srv__GoalLoc_Request * input,
  pizza_order_msgs__srv__GoalLoc_Request * output)
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

pizza_order_msgs__srv__GoalLoc_Request *
pizza_order_msgs__srv__GoalLoc_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pizza_order_msgs__srv__GoalLoc_Request * msg = (pizza_order_msgs__srv__GoalLoc_Request *)allocator.allocate(sizeof(pizza_order_msgs__srv__GoalLoc_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pizza_order_msgs__srv__GoalLoc_Request));
  bool success = pizza_order_msgs__srv__GoalLoc_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pizza_order_msgs__srv__GoalLoc_Request__destroy(pizza_order_msgs__srv__GoalLoc_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pizza_order_msgs__srv__GoalLoc_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pizza_order_msgs__srv__GoalLoc_Request__Sequence__init(pizza_order_msgs__srv__GoalLoc_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pizza_order_msgs__srv__GoalLoc_Request * data = NULL;

  if (size) {
    data = (pizza_order_msgs__srv__GoalLoc_Request *)allocator.zero_allocate(size, sizeof(pizza_order_msgs__srv__GoalLoc_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pizza_order_msgs__srv__GoalLoc_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pizza_order_msgs__srv__GoalLoc_Request__fini(&data[i - 1]);
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
pizza_order_msgs__srv__GoalLoc_Request__Sequence__fini(pizza_order_msgs__srv__GoalLoc_Request__Sequence * array)
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
      pizza_order_msgs__srv__GoalLoc_Request__fini(&array->data[i]);
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

pizza_order_msgs__srv__GoalLoc_Request__Sequence *
pizza_order_msgs__srv__GoalLoc_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pizza_order_msgs__srv__GoalLoc_Request__Sequence * array = (pizza_order_msgs__srv__GoalLoc_Request__Sequence *)allocator.allocate(sizeof(pizza_order_msgs__srv__GoalLoc_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pizza_order_msgs__srv__GoalLoc_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pizza_order_msgs__srv__GoalLoc_Request__Sequence__destroy(pizza_order_msgs__srv__GoalLoc_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pizza_order_msgs__srv__GoalLoc_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pizza_order_msgs__srv__GoalLoc_Request__Sequence__are_equal(const pizza_order_msgs__srv__GoalLoc_Request__Sequence * lhs, const pizza_order_msgs__srv__GoalLoc_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pizza_order_msgs__srv__GoalLoc_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pizza_order_msgs__srv__GoalLoc_Request__Sequence__copy(
  const pizza_order_msgs__srv__GoalLoc_Request__Sequence * input,
  pizza_order_msgs__srv__GoalLoc_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pizza_order_msgs__srv__GoalLoc_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pizza_order_msgs__srv__GoalLoc_Request * data =
      (pizza_order_msgs__srv__GoalLoc_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pizza_order_msgs__srv__GoalLoc_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pizza_order_msgs__srv__GoalLoc_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pizza_order_msgs__srv__GoalLoc_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
pizza_order_msgs__srv__GoalLoc_Response__init(pizza_order_msgs__srv__GoalLoc_Response * msg)
{
  if (!msg) {
    return false;
  }
  // send_result
  // x
  // y
  return true;
}

void
pizza_order_msgs__srv__GoalLoc_Response__fini(pizza_order_msgs__srv__GoalLoc_Response * msg)
{
  if (!msg) {
    return;
  }
  // send_result
  // x
  // y
}

bool
pizza_order_msgs__srv__GoalLoc_Response__are_equal(const pizza_order_msgs__srv__GoalLoc_Response * lhs, const pizza_order_msgs__srv__GoalLoc_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // send_result
  if (lhs->send_result != rhs->send_result) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  return true;
}

bool
pizza_order_msgs__srv__GoalLoc_Response__copy(
  const pizza_order_msgs__srv__GoalLoc_Response * input,
  pizza_order_msgs__srv__GoalLoc_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // send_result
  output->send_result = input->send_result;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  return true;
}

pizza_order_msgs__srv__GoalLoc_Response *
pizza_order_msgs__srv__GoalLoc_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pizza_order_msgs__srv__GoalLoc_Response * msg = (pizza_order_msgs__srv__GoalLoc_Response *)allocator.allocate(sizeof(pizza_order_msgs__srv__GoalLoc_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pizza_order_msgs__srv__GoalLoc_Response));
  bool success = pizza_order_msgs__srv__GoalLoc_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pizza_order_msgs__srv__GoalLoc_Response__destroy(pizza_order_msgs__srv__GoalLoc_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pizza_order_msgs__srv__GoalLoc_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pizza_order_msgs__srv__GoalLoc_Response__Sequence__init(pizza_order_msgs__srv__GoalLoc_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pizza_order_msgs__srv__GoalLoc_Response * data = NULL;

  if (size) {
    data = (pizza_order_msgs__srv__GoalLoc_Response *)allocator.zero_allocate(size, sizeof(pizza_order_msgs__srv__GoalLoc_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pizza_order_msgs__srv__GoalLoc_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pizza_order_msgs__srv__GoalLoc_Response__fini(&data[i - 1]);
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
pizza_order_msgs__srv__GoalLoc_Response__Sequence__fini(pizza_order_msgs__srv__GoalLoc_Response__Sequence * array)
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
      pizza_order_msgs__srv__GoalLoc_Response__fini(&array->data[i]);
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

pizza_order_msgs__srv__GoalLoc_Response__Sequence *
pizza_order_msgs__srv__GoalLoc_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pizza_order_msgs__srv__GoalLoc_Response__Sequence * array = (pizza_order_msgs__srv__GoalLoc_Response__Sequence *)allocator.allocate(sizeof(pizza_order_msgs__srv__GoalLoc_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pizza_order_msgs__srv__GoalLoc_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pizza_order_msgs__srv__GoalLoc_Response__Sequence__destroy(pizza_order_msgs__srv__GoalLoc_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pizza_order_msgs__srv__GoalLoc_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pizza_order_msgs__srv__GoalLoc_Response__Sequence__are_equal(const pizza_order_msgs__srv__GoalLoc_Response__Sequence * lhs, const pizza_order_msgs__srv__GoalLoc_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pizza_order_msgs__srv__GoalLoc_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pizza_order_msgs__srv__GoalLoc_Response__Sequence__copy(
  const pizza_order_msgs__srv__GoalLoc_Response__Sequence * input,
  pizza_order_msgs__srv__GoalLoc_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pizza_order_msgs__srv__GoalLoc_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pizza_order_msgs__srv__GoalLoc_Response * data =
      (pizza_order_msgs__srv__GoalLoc_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pizza_order_msgs__srv__GoalLoc_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pizza_order_msgs__srv__GoalLoc_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pizza_order_msgs__srv__GoalLoc_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
