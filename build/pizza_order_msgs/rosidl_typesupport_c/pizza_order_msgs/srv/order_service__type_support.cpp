// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from pizza_order_msgs:srv/OrderService.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "pizza_order_msgs/srv/detail/order_service__struct.h"
#include "pizza_order_msgs/srv/detail/order_service__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace pizza_order_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _OrderService_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _OrderService_Request_type_support_ids_t;

static const _OrderService_Request_type_support_ids_t _OrderService_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _OrderService_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _OrderService_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _OrderService_Request_type_support_symbol_names_t _OrderService_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pizza_order_msgs, srv, OrderService_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pizza_order_msgs, srv, OrderService_Request)),
  }
};

typedef struct _OrderService_Request_type_support_data_t
{
  void * data[2];
} _OrderService_Request_type_support_data_t;

static _OrderService_Request_type_support_data_t _OrderService_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _OrderService_Request_message_typesupport_map = {
  2,
  "pizza_order_msgs",
  &_OrderService_Request_message_typesupport_ids.typesupport_identifier[0],
  &_OrderService_Request_message_typesupport_symbol_names.symbol_name[0],
  &_OrderService_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t OrderService_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_OrderService_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace pizza_order_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, pizza_order_msgs, srv, OrderService_Request)() {
  return &::pizza_order_msgs::srv::rosidl_typesupport_c::OrderService_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "pizza_order_msgs/srv/detail/order_service__struct.h"
// already included above
// #include "pizza_order_msgs/srv/detail/order_service__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace pizza_order_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _OrderService_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _OrderService_Response_type_support_ids_t;

static const _OrderService_Response_type_support_ids_t _OrderService_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _OrderService_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _OrderService_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _OrderService_Response_type_support_symbol_names_t _OrderService_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pizza_order_msgs, srv, OrderService_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pizza_order_msgs, srv, OrderService_Response)),
  }
};

typedef struct _OrderService_Response_type_support_data_t
{
  void * data[2];
} _OrderService_Response_type_support_data_t;

static _OrderService_Response_type_support_data_t _OrderService_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _OrderService_Response_message_typesupport_map = {
  2,
  "pizza_order_msgs",
  &_OrderService_Response_message_typesupport_ids.typesupport_identifier[0],
  &_OrderService_Response_message_typesupport_symbol_names.symbol_name[0],
  &_OrderService_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t OrderService_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_OrderService_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace pizza_order_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, pizza_order_msgs, srv, OrderService_Response)() {
  return &::pizza_order_msgs::srv::rosidl_typesupport_c::OrderService_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "pizza_order_msgs/srv/detail/order_service__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace pizza_order_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _OrderService_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _OrderService_type_support_ids_t;

static const _OrderService_type_support_ids_t _OrderService_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _OrderService_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _OrderService_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _OrderService_type_support_symbol_names_t _OrderService_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pizza_order_msgs, srv, OrderService)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pizza_order_msgs, srv, OrderService)),
  }
};

typedef struct _OrderService_type_support_data_t
{
  void * data[2];
} _OrderService_type_support_data_t;

static _OrderService_type_support_data_t _OrderService_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _OrderService_service_typesupport_map = {
  2,
  "pizza_order_msgs",
  &_OrderService_service_typesupport_ids.typesupport_identifier[0],
  &_OrderService_service_typesupport_symbol_names.symbol_name[0],
  &_OrderService_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t OrderService_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_OrderService_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace pizza_order_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, pizza_order_msgs, srv, OrderService)() {
  return &::pizza_order_msgs::srv::rosidl_typesupport_c::OrderService_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
