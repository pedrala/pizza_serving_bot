// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pizza_order_msgs:srv/GoalLoc.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__SRV__DETAIL__GOAL_LOC__STRUCT_H_
#define PIZZA_ORDER_MSGS__SRV__DETAIL__GOAL_LOC__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'status'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GoalLoc in the package pizza_order_msgs.
typedef struct pizza_order_msgs__srv__GoalLoc_Request
{
  int16_t order_id;
  int16_t table_number;
  rosidl_runtime_c__String status;
} pizza_order_msgs__srv__GoalLoc_Request;

// Struct for a sequence of pizza_order_msgs__srv__GoalLoc_Request.
typedef struct pizza_order_msgs__srv__GoalLoc_Request__Sequence
{
  pizza_order_msgs__srv__GoalLoc_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pizza_order_msgs__srv__GoalLoc_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/GoalLoc in the package pizza_order_msgs.
typedef struct pizza_order_msgs__srv__GoalLoc_Response
{
  bool send_result;
  float x;
  float y;
} pizza_order_msgs__srv__GoalLoc_Response;

// Struct for a sequence of pizza_order_msgs__srv__GoalLoc_Response.
typedef struct pizza_order_msgs__srv__GoalLoc_Response__Sequence
{
  pizza_order_msgs__srv__GoalLoc_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pizza_order_msgs__srv__GoalLoc_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PIZZA_ORDER_MSGS__SRV__DETAIL__GOAL_LOC__STRUCT_H_
