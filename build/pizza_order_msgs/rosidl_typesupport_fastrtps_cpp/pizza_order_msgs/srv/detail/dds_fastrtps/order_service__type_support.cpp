// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from pizza_order_msgs:srv/OrderService.idl
// generated code does not contain a copyright notice
#include "pizza_order_msgs/srv/detail/order_service__rosidl_typesupport_fastrtps_cpp.hpp"
#include "pizza_order_msgs/srv/detail/order_service__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace pizza_order_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const pizza_order_msgs::msg::OrderDetail &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  pizza_order_msgs::msg::OrderDetail &);
size_t get_serialized_size(
  const pizza_order_msgs::msg::OrderDetail &,
  size_t current_alignment);
size_t
max_serialized_size_OrderDetail(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace pizza_order_msgs


namespace pizza_order_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pizza_order_msgs
cdr_serialize(
  const pizza_order_msgs::srv::OrderService_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: order_id
  cdr << ros_message.order_id;
  // Member: table_number
  cdr << ros_message.table_number;
  // Member: detail_id
  cdr << ros_message.detail_id;
  // Member: order_details
  {
    size_t size = ros_message.order_details.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      pizza_order_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.order_details[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pizza_order_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  pizza_order_msgs::srv::OrderService_Request & ros_message)
{
  // Member: order_id
  cdr >> ros_message.order_id;

  // Member: table_number
  cdr >> ros_message.table_number;

  // Member: detail_id
  cdr >> ros_message.detail_id;

  // Member: order_details
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.order_details.resize(size);
    for (size_t i = 0; i < size; i++) {
      pizza_order_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.order_details[i]);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pizza_order_msgs
get_serialized_size(
  const pizza_order_msgs::srv::OrderService_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: order_id
  {
    size_t item_size = sizeof(ros_message.order_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: table_number
  {
    size_t item_size = sizeof(ros_message.table_number);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: detail_id
  {
    size_t item_size = sizeof(ros_message.detail_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: order_details
  {
    size_t array_size = ros_message.order_details.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        pizza_order_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.order_details[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pizza_order_msgs
max_serialized_size_OrderService_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: order_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: table_number
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: detail_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: order_details
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        pizza_order_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_OrderDetail(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = pizza_order_msgs::srv::OrderService_Request;
    is_plain =
      (
      offsetof(DataType, order_details) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _OrderService_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const pizza_order_msgs::srv::OrderService_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _OrderService_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<pizza_order_msgs::srv::OrderService_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _OrderService_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const pizza_order_msgs::srv::OrderService_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _OrderService_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_OrderService_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _OrderService_Request__callbacks = {
  "pizza_order_msgs::srv",
  "OrderService_Request",
  _OrderService_Request__cdr_serialize,
  _OrderService_Request__cdr_deserialize,
  _OrderService_Request__get_serialized_size,
  _OrderService_Request__max_serialized_size
};

static rosidl_message_type_support_t _OrderService_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_OrderService_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace pizza_order_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_pizza_order_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<pizza_order_msgs::srv::OrderService_Request>()
{
  return &pizza_order_msgs::srv::typesupport_fastrtps_cpp::_OrderService_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, pizza_order_msgs, srv, OrderService_Request)() {
  return &pizza_order_msgs::srv::typesupport_fastrtps_cpp::_OrderService_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace pizza_order_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pizza_order_msgs
cdr_serialize(
  const pizza_order_msgs::srv::OrderService_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: order_result
  cdr << (ros_message.order_result ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pizza_order_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  pizza_order_msgs::srv::OrderService_Response & ros_message)
{
  // Member: order_result
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.order_result = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pizza_order_msgs
get_serialized_size(
  const pizza_order_msgs::srv::OrderService_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: order_result
  {
    size_t item_size = sizeof(ros_message.order_result);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pizza_order_msgs
max_serialized_size_OrderService_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: order_result
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = pizza_order_msgs::srv::OrderService_Response;
    is_plain =
      (
      offsetof(DataType, order_result) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _OrderService_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const pizza_order_msgs::srv::OrderService_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _OrderService_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<pizza_order_msgs::srv::OrderService_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _OrderService_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const pizza_order_msgs::srv::OrderService_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _OrderService_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_OrderService_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _OrderService_Response__callbacks = {
  "pizza_order_msgs::srv",
  "OrderService_Response",
  _OrderService_Response__cdr_serialize,
  _OrderService_Response__cdr_deserialize,
  _OrderService_Response__get_serialized_size,
  _OrderService_Response__max_serialized_size
};

static rosidl_message_type_support_t _OrderService_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_OrderService_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace pizza_order_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_pizza_order_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<pizza_order_msgs::srv::OrderService_Response>()
{
  return &pizza_order_msgs::srv::typesupport_fastrtps_cpp::_OrderService_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, pizza_order_msgs, srv, OrderService_Response)() {
  return &pizza_order_msgs::srv::typesupport_fastrtps_cpp::_OrderService_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace pizza_order_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _OrderService__callbacks = {
  "pizza_order_msgs::srv",
  "OrderService",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, pizza_order_msgs, srv, OrderService_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, pizza_order_msgs, srv, OrderService_Response)(),
};

static rosidl_service_type_support_t _OrderService__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_OrderService__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace pizza_order_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_pizza_order_msgs
const rosidl_service_type_support_t *
get_service_type_support_handle<pizza_order_msgs::srv::OrderService>()
{
  return &pizza_order_msgs::srv::typesupport_fastrtps_cpp::_OrderService__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, pizza_order_msgs, srv, OrderService)() {
  return &pizza_order_msgs::srv::typesupport_fastrtps_cpp::_OrderService__handle;
}

#ifdef __cplusplus
}
#endif
