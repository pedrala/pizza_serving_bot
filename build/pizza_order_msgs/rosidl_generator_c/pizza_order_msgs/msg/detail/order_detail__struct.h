// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pizza_order_msgs:msg/OrderDetail.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_DETAIL__STRUCT_H_
#define PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_DETAIL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'item_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/OrderDetail in the package pizza_order_msgs.
typedef struct pizza_order_msgs__msg__OrderDetail
{
  int8_t item_id;
  rosidl_runtime_c__String item_name;
  int8_t quantity;
  float price;
} pizza_order_msgs__msg__OrderDetail;

// Struct for a sequence of pizza_order_msgs__msg__OrderDetail.
typedef struct pizza_order_msgs__msg__OrderDetail__Sequence
{
  pizza_order_msgs__msg__OrderDetail * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pizza_order_msgs__msg__OrderDetail__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_DETAIL__STRUCT_H_
