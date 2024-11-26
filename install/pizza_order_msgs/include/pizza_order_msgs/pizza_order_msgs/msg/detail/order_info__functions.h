// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from pizza_order_msgs:msg/OrderInfo.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_INFO__FUNCTIONS_H_
#define PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_INFO__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "pizza_order_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "pizza_order_msgs/msg/detail/order_info__struct.h"

/// Initialize msg/OrderInfo message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * pizza_order_msgs__msg__OrderInfo
 * )) before or use
 * pizza_order_msgs__msg__OrderInfo__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_pizza_order_msgs
bool
pizza_order_msgs__msg__OrderInfo__init(pizza_order_msgs__msg__OrderInfo * msg);

/// Finalize msg/OrderInfo message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pizza_order_msgs
void
pizza_order_msgs__msg__OrderInfo__fini(pizza_order_msgs__msg__OrderInfo * msg);

/// Create msg/OrderInfo message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * pizza_order_msgs__msg__OrderInfo__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pizza_order_msgs
pizza_order_msgs__msg__OrderInfo *
pizza_order_msgs__msg__OrderInfo__create();

/// Destroy msg/OrderInfo message.
/**
 * It calls
 * pizza_order_msgs__msg__OrderInfo__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pizza_order_msgs
void
pizza_order_msgs__msg__OrderInfo__destroy(pizza_order_msgs__msg__OrderInfo * msg);

/// Check for msg/OrderInfo message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pizza_order_msgs
bool
pizza_order_msgs__msg__OrderInfo__are_equal(const pizza_order_msgs__msg__OrderInfo * lhs, const pizza_order_msgs__msg__OrderInfo * rhs);

/// Copy a msg/OrderInfo message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pizza_order_msgs
bool
pizza_order_msgs__msg__OrderInfo__copy(
  const pizza_order_msgs__msg__OrderInfo * input,
  pizza_order_msgs__msg__OrderInfo * output);

/// Initialize array of msg/OrderInfo messages.
/**
 * It allocates the memory for the number of elements and calls
 * pizza_order_msgs__msg__OrderInfo__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_pizza_order_msgs
bool
pizza_order_msgs__msg__OrderInfo__Sequence__init(pizza_order_msgs__msg__OrderInfo__Sequence * array, size_t size);

/// Finalize array of msg/OrderInfo messages.
/**
 * It calls
 * pizza_order_msgs__msg__OrderInfo__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pizza_order_msgs
void
pizza_order_msgs__msg__OrderInfo__Sequence__fini(pizza_order_msgs__msg__OrderInfo__Sequence * array);

/// Create array of msg/OrderInfo messages.
/**
 * It allocates the memory for the array and calls
 * pizza_order_msgs__msg__OrderInfo__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pizza_order_msgs
pizza_order_msgs__msg__OrderInfo__Sequence *
pizza_order_msgs__msg__OrderInfo__Sequence__create(size_t size);

/// Destroy array of msg/OrderInfo messages.
/**
 * It calls
 * pizza_order_msgs__msg__OrderInfo__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pizza_order_msgs
void
pizza_order_msgs__msg__OrderInfo__Sequence__destroy(pizza_order_msgs__msg__OrderInfo__Sequence * array);

/// Check for msg/OrderInfo message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pizza_order_msgs
bool
pizza_order_msgs__msg__OrderInfo__Sequence__are_equal(const pizza_order_msgs__msg__OrderInfo__Sequence * lhs, const pizza_order_msgs__msg__OrderInfo__Sequence * rhs);

/// Copy an array of msg/OrderInfo messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pizza_order_msgs
bool
pizza_order_msgs__msg__OrderInfo__Sequence__copy(
  const pizza_order_msgs__msg__OrderInfo__Sequence * input,
  pizza_order_msgs__msg__OrderInfo__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_INFO__FUNCTIONS_H_
