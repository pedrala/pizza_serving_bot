// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pizza_order_msgs:msg/OrderInfo.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_INFO__STRUCT_H_
#define PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_INFO__STRUCT_H_

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

/// Struct defined in msg/OrderInfo in the package pizza_order_msgs.
typedef struct pizza_order_msgs__msg__OrderInfo
{
  int8_t order_id;
  int8_t table_number;
  rosidl_runtime_c__String status;
} pizza_order_msgs__msg__OrderInfo;

// Struct for a sequence of pizza_order_msgs__msg__OrderInfo.
typedef struct pizza_order_msgs__msg__OrderInfo__Sequence
{
  pizza_order_msgs__msg__OrderInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pizza_order_msgs__msg__OrderInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_INFO__STRUCT_H_
