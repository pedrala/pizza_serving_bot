// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pizza_order_msgs:msg/OrderDetail.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pizza_order_msgs/msg/detail/order_detail__rosidl_typesupport_introspection_c.h"
#include "pizza_order_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pizza_order_msgs/msg/detail/order_detail__functions.h"
#include "pizza_order_msgs/msg/detail/order_detail__struct.h"


// Include directives for member types
// Member `item_name`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void pizza_order_msgs__msg__OrderDetail__rosidl_typesupport_introspection_c__OrderDetail_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pizza_order_msgs__msg__OrderDetail__init(message_memory);
}

void pizza_order_msgs__msg__OrderDetail__rosidl_typesupport_introspection_c__OrderDetail_fini_function(void * message_memory)
{
  pizza_order_msgs__msg__OrderDetail__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember pizza_order_msgs__msg__OrderDetail__rosidl_typesupport_introspection_c__OrderDetail_message_member_array[4] = {
  {
    "item_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pizza_order_msgs__msg__OrderDetail, item_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "item_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pizza_order_msgs__msg__OrderDetail, item_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "quantity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pizza_order_msgs__msg__OrderDetail, quantity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "price",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pizza_order_msgs__msg__OrderDetail, price),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pizza_order_msgs__msg__OrderDetail__rosidl_typesupport_introspection_c__OrderDetail_message_members = {
  "pizza_order_msgs__msg",  // message namespace
  "OrderDetail",  // message name
  4,  // number of fields
  sizeof(pizza_order_msgs__msg__OrderDetail),
  pizza_order_msgs__msg__OrderDetail__rosidl_typesupport_introspection_c__OrderDetail_message_member_array,  // message members
  pizza_order_msgs__msg__OrderDetail__rosidl_typesupport_introspection_c__OrderDetail_init_function,  // function to initialize message memory (memory has to be allocated)
  pizza_order_msgs__msg__OrderDetail__rosidl_typesupport_introspection_c__OrderDetail_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pizza_order_msgs__msg__OrderDetail__rosidl_typesupport_introspection_c__OrderDetail_message_type_support_handle = {
  0,
  &pizza_order_msgs__msg__OrderDetail__rosidl_typesupport_introspection_c__OrderDetail_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pizza_order_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pizza_order_msgs, msg, OrderDetail)() {
  if (!pizza_order_msgs__msg__OrderDetail__rosidl_typesupport_introspection_c__OrderDetail_message_type_support_handle.typesupport_identifier) {
    pizza_order_msgs__msg__OrderDetail__rosidl_typesupport_introspection_c__OrderDetail_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pizza_order_msgs__msg__OrderDetail__rosidl_typesupport_introspection_c__OrderDetail_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
