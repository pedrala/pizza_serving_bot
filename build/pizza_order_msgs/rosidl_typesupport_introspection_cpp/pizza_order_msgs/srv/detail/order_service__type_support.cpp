// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from pizza_order_msgs:srv/OrderService.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "pizza_order_msgs/srv/detail/order_service__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace pizza_order_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void OrderService_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) pizza_order_msgs::srv::OrderService_Request(_init);
}

void OrderService_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<pizza_order_msgs::srv::OrderService_Request *>(message_memory);
  typed_message->~OrderService_Request();
}

size_t size_function__OrderService_Request__order_details(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<pizza_order_msgs::msg::OrderDetail> *>(untyped_member);
  return member->size();
}

const void * get_const_function__OrderService_Request__order_details(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<pizza_order_msgs::msg::OrderDetail> *>(untyped_member);
  return &member[index];
}

void * get_function__OrderService_Request__order_details(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<pizza_order_msgs::msg::OrderDetail> *>(untyped_member);
  return &member[index];
}

void fetch_function__OrderService_Request__order_details(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const pizza_order_msgs::msg::OrderDetail *>(
    get_const_function__OrderService_Request__order_details(untyped_member, index));
  auto & value = *reinterpret_cast<pizza_order_msgs::msg::OrderDetail *>(untyped_value);
  value = item;
}

void assign_function__OrderService_Request__order_details(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<pizza_order_msgs::msg::OrderDetail *>(
    get_function__OrderService_Request__order_details(untyped_member, index));
  const auto & value = *reinterpret_cast<const pizza_order_msgs::msg::OrderDetail *>(untyped_value);
  item = value;
}

void resize_function__OrderService_Request__order_details(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<pizza_order_msgs::msg::OrderDetail> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember OrderService_Request_message_member_array[4] = {
  {
    "order_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pizza_order_msgs::srv::OrderService_Request, order_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "table_number",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pizza_order_msgs::srv::OrderService_Request, table_number),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "detail_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pizza_order_msgs::srv::OrderService_Request, detail_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "order_details",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<pizza_order_msgs::msg::OrderDetail>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pizza_order_msgs::srv::OrderService_Request, order_details),  // bytes offset in struct
    nullptr,  // default value
    size_function__OrderService_Request__order_details,  // size() function pointer
    get_const_function__OrderService_Request__order_details,  // get_const(index) function pointer
    get_function__OrderService_Request__order_details,  // get(index) function pointer
    fetch_function__OrderService_Request__order_details,  // fetch(index, &value) function pointer
    assign_function__OrderService_Request__order_details,  // assign(index, value) function pointer
    resize_function__OrderService_Request__order_details  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers OrderService_Request_message_members = {
  "pizza_order_msgs::srv",  // message namespace
  "OrderService_Request",  // message name
  4,  // number of fields
  sizeof(pizza_order_msgs::srv::OrderService_Request),
  OrderService_Request_message_member_array,  // message members
  OrderService_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  OrderService_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t OrderService_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &OrderService_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace pizza_order_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<pizza_order_msgs::srv::OrderService_Request>()
{
  return &::pizza_order_msgs::srv::rosidl_typesupport_introspection_cpp::OrderService_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, pizza_order_msgs, srv, OrderService_Request)() {
  return &::pizza_order_msgs::srv::rosidl_typesupport_introspection_cpp::OrderService_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "pizza_order_msgs/srv/detail/order_service__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace pizza_order_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void OrderService_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) pizza_order_msgs::srv::OrderService_Response(_init);
}

void OrderService_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<pizza_order_msgs::srv::OrderService_Response *>(message_memory);
  typed_message->~OrderService_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember OrderService_Response_message_member_array[1] = {
  {
    "order_result",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pizza_order_msgs::srv::OrderService_Response, order_result),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers OrderService_Response_message_members = {
  "pizza_order_msgs::srv",  // message namespace
  "OrderService_Response",  // message name
  1,  // number of fields
  sizeof(pizza_order_msgs::srv::OrderService_Response),
  OrderService_Response_message_member_array,  // message members
  OrderService_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  OrderService_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t OrderService_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &OrderService_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace pizza_order_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<pizza_order_msgs::srv::OrderService_Response>()
{
  return &::pizza_order_msgs::srv::rosidl_typesupport_introspection_cpp::OrderService_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, pizza_order_msgs, srv, OrderService_Response)() {
  return &::pizza_order_msgs::srv::rosidl_typesupport_introspection_cpp::OrderService_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "pizza_order_msgs/srv/detail/order_service__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace pizza_order_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers OrderService_service_members = {
  "pizza_order_msgs::srv",  // service namespace
  "OrderService",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<pizza_order_msgs::srv::OrderService>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t OrderService_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &OrderService_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace pizza_order_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<pizza_order_msgs::srv::OrderService>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::pizza_order_msgs::srv::rosidl_typesupport_introspection_cpp::OrderService_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::pizza_order_msgs::srv::OrderService_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::pizza_order_msgs::srv::OrderService_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, pizza_order_msgs, srv, OrderService)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<pizza_order_msgs::srv::OrderService>();
}

#ifdef __cplusplus
}
#endif
