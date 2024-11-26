// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pizza_order_msgs:srv/OrderService.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__SRV__DETAIL__ORDER_SERVICE__STRUCT_H_
#define PIZZA_ORDER_MSGS__SRV__DETAIL__ORDER_SERVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'order_details'
#include "pizza_order_msgs/msg/detail/order_detail__struct.h"

/// Struct defined in srv/OrderService in the package pizza_order_msgs.
typedef struct pizza_order_msgs__srv__OrderService_Request
{
  int8_t order_id;
  int8_t table_number;
  int8_t detail_id;
  /// 주문 세부 항목들을 포함하는 배열
  pizza_order_msgs__msg__OrderDetail__Sequence order_details;
} pizza_order_msgs__srv__OrderService_Request;

// Struct for a sequence of pizza_order_msgs__srv__OrderService_Request.
typedef struct pizza_order_msgs__srv__OrderService_Request__Sequence
{
  pizza_order_msgs__srv__OrderService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pizza_order_msgs__srv__OrderService_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/OrderService in the package pizza_order_msgs.
typedef struct pizza_order_msgs__srv__OrderService_Response
{
  bool order_result;
} pizza_order_msgs__srv__OrderService_Response;

// Struct for a sequence of pizza_order_msgs__srv__OrderService_Response.
typedef struct pizza_order_msgs__srv__OrderService_Response__Sequence
{
  pizza_order_msgs__srv__OrderService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pizza_order_msgs__srv__OrderService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PIZZA_ORDER_MSGS__SRV__DETAIL__ORDER_SERVICE__STRUCT_H_
