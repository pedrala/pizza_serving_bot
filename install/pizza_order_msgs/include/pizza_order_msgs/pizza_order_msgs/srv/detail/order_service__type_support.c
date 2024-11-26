// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pizza_order_msgs:srv/OrderService.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pizza_order_msgs/srv/detail/order_service__rosidl_typesupport_introspection_c.h"
#include "pizza_order_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pizza_order_msgs/srv/detail/order_service__functions.h"
#include "pizza_order_msgs/srv/detail/order_service__struct.h"


// Include directives for member types
// Member `order_details`
#include "pizza_order_msgs/msg/order_detail.h"
// Member `order_details`
#include "pizza_order_msgs/msg/detail/order_detail__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__OrderService_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pizza_order_msgs__srv__OrderService_Request__init(message_memory);
}

void pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__OrderService_Request_fini_function(void * message_memory)
{
  pizza_order_msgs__srv__OrderService_Request__fini(message_memory);
}

size_t pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__size_function__OrderService_Request__order_details(
  const void * untyped_member)
{
  const pizza_order_msgs__msg__OrderDetail__Sequence * member =
    (const pizza_order_msgs__msg__OrderDetail__Sequence *)(untyped_member);
  return member->size;
}

const void * pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__get_const_function__OrderService_Request__order_details(
  const void * untyped_member, size_t index)
{
  const pizza_order_msgs__msg__OrderDetail__Sequence * member =
    (const pizza_order_msgs__msg__OrderDetail__Sequence *)(untyped_member);
  return &member->data[index];
}

void * pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__get_function__OrderService_Request__order_details(
  void * untyped_member, size_t index)
{
  pizza_order_msgs__msg__OrderDetail__Sequence * member =
    (pizza_order_msgs__msg__OrderDetail__Sequence *)(untyped_member);
  return &member->data[index];
}

void pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__fetch_function__OrderService_Request__order_details(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const pizza_order_msgs__msg__OrderDetail * item =
    ((const pizza_order_msgs__msg__OrderDetail *)
    pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__get_const_function__OrderService_Request__order_details(untyped_member, index));
  pizza_order_msgs__msg__OrderDetail * value =
    (pizza_order_msgs__msg__OrderDetail *)(untyped_value);
  *value = *item;
}

void pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__assign_function__OrderService_Request__order_details(
  void * untyped_member, size_t index, const void * untyped_value)
{
  pizza_order_msgs__msg__OrderDetail * item =
    ((pizza_order_msgs__msg__OrderDetail *)
    pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__get_function__OrderService_Request__order_details(untyped_member, index));
  const pizza_order_msgs__msg__OrderDetail * value =
    (const pizza_order_msgs__msg__OrderDetail *)(untyped_value);
  *item = *value;
}

bool pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__resize_function__OrderService_Request__order_details(
  void * untyped_member, size_t size)
{
  pizza_order_msgs__msg__OrderDetail__Sequence * member =
    (pizza_order_msgs__msg__OrderDetail__Sequence *)(untyped_member);
  pizza_order_msgs__msg__OrderDetail__Sequence__fini(member);
  return pizza_order_msgs__msg__OrderDetail__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__OrderService_Request_message_member_array[4] = {
  {
    "order_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pizza_order_msgs__srv__OrderService_Request, order_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "table_number",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pizza_order_msgs__srv__OrderService_Request, table_number),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "detail_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pizza_order_msgs__srv__OrderService_Request, detail_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "order_details",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pizza_order_msgs__srv__OrderService_Request, order_details),  // bytes offset in struct
    NULL,  // default value
    pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__size_function__OrderService_Request__order_details,  // size() function pointer
    pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__get_const_function__OrderService_Request__order_details,  // get_const(index) function pointer
    pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__get_function__OrderService_Request__order_details,  // get(index) function pointer
    pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__fetch_function__OrderService_Request__order_details,  // fetch(index, &value) function pointer
    pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__assign_function__OrderService_Request__order_details,  // assign(index, value) function pointer
    pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__resize_function__OrderService_Request__order_details  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__OrderService_Request_message_members = {
  "pizza_order_msgs__srv",  // message namespace
  "OrderService_Request",  // message name
  4,  // number of fields
  sizeof(pizza_order_msgs__srv__OrderService_Request),
  pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__OrderService_Request_message_member_array,  // message members
  pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__OrderService_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__OrderService_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__OrderService_Request_message_type_support_handle = {
  0,
  &pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__OrderService_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pizza_order_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pizza_order_msgs, srv, OrderService_Request)() {
  pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__OrderService_Request_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pizza_order_msgs, msg, OrderDetail)();
  if (!pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__OrderService_Request_message_type_support_handle.typesupport_identifier) {
    pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__OrderService_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pizza_order_msgs__srv__OrderService_Request__rosidl_typesupport_introspection_c__OrderService_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "pizza_order_msgs/srv/detail/order_service__rosidl_typesupport_introspection_c.h"
// already included above
// #include "pizza_order_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "pizza_order_msgs/srv/detail/order_service__functions.h"
// already included above
// #include "pizza_order_msgs/srv/detail/order_service__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void pizza_order_msgs__srv__OrderService_Response__rosidl_typesupport_introspection_c__OrderService_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pizza_order_msgs__srv__OrderService_Response__init(message_memory);
}

void pizza_order_msgs__srv__OrderService_Response__rosidl_typesupport_introspection_c__OrderService_Response_fini_function(void * message_memory)
{
  pizza_order_msgs__srv__OrderService_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember pizza_order_msgs__srv__OrderService_Response__rosidl_typesupport_introspection_c__OrderService_Response_message_member_array[1] = {
  {
    "order_result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pizza_order_msgs__srv__OrderService_Response, order_result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pizza_order_msgs__srv__OrderService_Response__rosidl_typesupport_introspection_c__OrderService_Response_message_members = {
  "pizza_order_msgs__srv",  // message namespace
  "OrderService_Response",  // message name
  1,  // number of fields
  sizeof(pizza_order_msgs__srv__OrderService_Response),
  pizza_order_msgs__srv__OrderService_Response__rosidl_typesupport_introspection_c__OrderService_Response_message_member_array,  // message members
  pizza_order_msgs__srv__OrderService_Response__rosidl_typesupport_introspection_c__OrderService_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  pizza_order_msgs__srv__OrderService_Response__rosidl_typesupport_introspection_c__OrderService_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pizza_order_msgs__srv__OrderService_Response__rosidl_typesupport_introspection_c__OrderService_Response_message_type_support_handle = {
  0,
  &pizza_order_msgs__srv__OrderService_Response__rosidl_typesupport_introspection_c__OrderService_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pizza_order_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pizza_order_msgs, srv, OrderService_Response)() {
  if (!pizza_order_msgs__srv__OrderService_Response__rosidl_typesupport_introspection_c__OrderService_Response_message_type_support_handle.typesupport_identifier) {
    pizza_order_msgs__srv__OrderService_Response__rosidl_typesupport_introspection_c__OrderService_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pizza_order_msgs__srv__OrderService_Response__rosidl_typesupport_introspection_c__OrderService_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "pizza_order_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "pizza_order_msgs/srv/detail/order_service__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers pizza_order_msgs__srv__detail__order_service__rosidl_typesupport_introspection_c__OrderService_service_members = {
  "pizza_order_msgs__srv",  // service namespace
  "OrderService",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // pizza_order_msgs__srv__detail__order_service__rosidl_typesupport_introspection_c__OrderService_Request_message_type_support_handle,
  NULL  // response message
  // pizza_order_msgs__srv__detail__order_service__rosidl_typesupport_introspection_c__OrderService_Response_message_type_support_handle
};

static rosidl_service_type_support_t pizza_order_msgs__srv__detail__order_service__rosidl_typesupport_introspection_c__OrderService_service_type_support_handle = {
  0,
  &pizza_order_msgs__srv__detail__order_service__rosidl_typesupport_introspection_c__OrderService_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pizza_order_msgs, srv, OrderService_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pizza_order_msgs, srv, OrderService_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pizza_order_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pizza_order_msgs, srv, OrderService)() {
  if (!pizza_order_msgs__srv__detail__order_service__rosidl_typesupport_introspection_c__OrderService_service_type_support_handle.typesupport_identifier) {
    pizza_order_msgs__srv__detail__order_service__rosidl_typesupport_introspection_c__OrderService_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)pizza_order_msgs__srv__detail__order_service__rosidl_typesupport_introspection_c__OrderService_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pizza_order_msgs, srv, OrderService_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pizza_order_msgs, srv, OrderService_Response)()->data;
  }

  return &pizza_order_msgs__srv__detail__order_service__rosidl_typesupport_introspection_c__OrderService_service_type_support_handle;
}
