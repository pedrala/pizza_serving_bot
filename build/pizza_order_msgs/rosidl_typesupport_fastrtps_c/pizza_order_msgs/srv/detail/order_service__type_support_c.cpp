// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from pizza_order_msgs:srv/OrderService.idl
// generated code does not contain a copyright notice
#include "pizza_order_msgs/srv/detail/order_service__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "pizza_order_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "pizza_order_msgs/srv/detail/order_service__struct.h"
#include "pizza_order_msgs/srv/detail/order_service__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "pizza_order_msgs/msg/detail/order_detail__functions.h"  // order_details

// forward declare type support functions
size_t get_serialized_size_pizza_order_msgs__msg__OrderDetail(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_pizza_order_msgs__msg__OrderDetail(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pizza_order_msgs, msg, OrderDetail)();


using _OrderService_Request__ros_msg_type = pizza_order_msgs__srv__OrderService_Request;

static bool _OrderService_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _OrderService_Request__ros_msg_type * ros_message = static_cast<const _OrderService_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: order_id
  {
    cdr << ros_message->order_id;
  }

  // Field name: table_number
  {
    cdr << ros_message->table_number;
  }

  // Field name: detail_id
  {
    cdr << ros_message->detail_id;
  }

  // Field name: order_details
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, pizza_order_msgs, msg, OrderDetail
      )()->data);
    size_t size = ros_message->order_details.size;
    auto array_ptr = ros_message->order_details.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _OrderService_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _OrderService_Request__ros_msg_type * ros_message = static_cast<_OrderService_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: order_id
  {
    cdr >> ros_message->order_id;
  }

  // Field name: table_number
  {
    cdr >> ros_message->table_number;
  }

  // Field name: detail_id
  {
    cdr >> ros_message->detail_id;
  }

  // Field name: order_details
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, pizza_order_msgs, msg, OrderDetail
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->order_details.data) {
      pizza_order_msgs__msg__OrderDetail__Sequence__fini(&ros_message->order_details);
    }
    if (!pizza_order_msgs__msg__OrderDetail__Sequence__init(&ros_message->order_details, size)) {
      fprintf(stderr, "failed to create array for field 'order_details'");
      return false;
    }
    auto array_ptr = ros_message->order_details.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pizza_order_msgs
size_t get_serialized_size_pizza_order_msgs__srv__OrderService_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _OrderService_Request__ros_msg_type * ros_message = static_cast<const _OrderService_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name order_id
  {
    size_t item_size = sizeof(ros_message->order_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name table_number
  {
    size_t item_size = sizeof(ros_message->table_number);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name detail_id
  {
    size_t item_size = sizeof(ros_message->detail_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name order_details
  {
    size_t array_size = ros_message->order_details.size;
    auto array_ptr = ros_message->order_details.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_pizza_order_msgs__msg__OrderDetail(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _OrderService_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_pizza_order_msgs__srv__OrderService_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pizza_order_msgs
size_t max_serialized_size_pizza_order_msgs__srv__OrderService_Request(
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

  // member: order_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: table_number
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: detail_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: order_details
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
      size_t inner_size;
      inner_size =
        max_serialized_size_pizza_order_msgs__msg__OrderDetail(
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
    using DataType = pizza_order_msgs__srv__OrderService_Request;
    is_plain =
      (
      offsetof(DataType, order_details) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _OrderService_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_pizza_order_msgs__srv__OrderService_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_OrderService_Request = {
  "pizza_order_msgs::srv",
  "OrderService_Request",
  _OrderService_Request__cdr_serialize,
  _OrderService_Request__cdr_deserialize,
  _OrderService_Request__get_serialized_size,
  _OrderService_Request__max_serialized_size
};

static rosidl_message_type_support_t _OrderService_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_OrderService_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pizza_order_msgs, srv, OrderService_Request)() {
  return &_OrderService_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "pizza_order_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "pizza_order_msgs/srv/detail/order_service__struct.h"
// already included above
// #include "pizza_order_msgs/srv/detail/order_service__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _OrderService_Response__ros_msg_type = pizza_order_msgs__srv__OrderService_Response;

static bool _OrderService_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _OrderService_Response__ros_msg_type * ros_message = static_cast<const _OrderService_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: order_result
  {
    cdr << (ros_message->order_result ? true : false);
  }

  return true;
}

static bool _OrderService_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _OrderService_Response__ros_msg_type * ros_message = static_cast<_OrderService_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: order_result
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->order_result = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pizza_order_msgs
size_t get_serialized_size_pizza_order_msgs__srv__OrderService_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _OrderService_Response__ros_msg_type * ros_message = static_cast<const _OrderService_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name order_result
  {
    size_t item_size = sizeof(ros_message->order_result);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _OrderService_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_pizza_order_msgs__srv__OrderService_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pizza_order_msgs
size_t max_serialized_size_pizza_order_msgs__srv__OrderService_Response(
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

  // member: order_result
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
    using DataType = pizza_order_msgs__srv__OrderService_Response;
    is_plain =
      (
      offsetof(DataType, order_result) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _OrderService_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_pizza_order_msgs__srv__OrderService_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_OrderService_Response = {
  "pizza_order_msgs::srv",
  "OrderService_Response",
  _OrderService_Response__cdr_serialize,
  _OrderService_Response__cdr_deserialize,
  _OrderService_Response__get_serialized_size,
  _OrderService_Response__max_serialized_size
};

static rosidl_message_type_support_t _OrderService_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_OrderService_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pizza_order_msgs, srv, OrderService_Response)() {
  return &_OrderService_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "pizza_order_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "pizza_order_msgs/srv/order_service.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t OrderService__callbacks = {
  "pizza_order_msgs::srv",
  "OrderService",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pizza_order_msgs, srv, OrderService_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pizza_order_msgs, srv, OrderService_Response)(),
};

static rosidl_service_type_support_t OrderService__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &OrderService__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pizza_order_msgs, srv, OrderService)() {
  return &OrderService__handle;
}

#if defined(__cplusplus)
}
#endif
