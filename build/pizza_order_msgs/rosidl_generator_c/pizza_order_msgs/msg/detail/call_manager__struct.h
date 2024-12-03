// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pizza_order_msgs:msg/CallManager.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__MSG__DETAIL__CALL_MANAGER__STRUCT_H_
#define PIZZA_ORDER_MSGS__MSG__DETAIL__CALL_MANAGER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/CallManager in the package pizza_order_msgs.
typedef struct pizza_order_msgs__msg__CallManager
{
  int8_t table_number;
} pizza_order_msgs__msg__CallManager;

// Struct for a sequence of pizza_order_msgs__msg__CallManager.
typedef struct pizza_order_msgs__msg__CallManager__Sequence
{
  pizza_order_msgs__msg__CallManager * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pizza_order_msgs__msg__CallManager__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PIZZA_ORDER_MSGS__MSG__DETAIL__CALL_MANAGER__STRUCT_H_
