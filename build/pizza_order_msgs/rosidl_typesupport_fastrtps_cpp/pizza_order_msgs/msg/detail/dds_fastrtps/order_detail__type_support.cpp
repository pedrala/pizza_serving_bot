// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from pizza_order_msgs:msg/OrderDetail.idl
// generated code does not contain a copyright notice
#include "pizza_order_msgs/msg/detail/order_detail__rosidl_typesupport_fastrtps_cpp.hpp"
#include "pizza_order_msgs/msg/detail/order_detail__struct.hpp"

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

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pizza_order_msgs
cdr_serialize(
  const pizza_order_msgs::msg::OrderDetail & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: detail_id
  cdr << ros_message.detail_id;
  // Member: item_id
  cdr << ros_message.item_id;
  // Member: item_name
  cdr << ros_message.item_name;
  // Member: quantity
  cdr << ros_message.quantity;
  // Member: price
  cdr << ros_message.price;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pizza_order_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  pizza_order_msgs::msg::OrderDetail & ros_message)
{
  // Member: detail_id
  cdr >> ros_message.detail_id;

  // Member: item_id
  cdr >> ros_message.item_id;

  // Member: item_name
  cdr >> ros_message.item_name;

  // Member: quantity
  cdr >> ros_message.quantity;

  // Member: price
  cdr >> ros_message.price;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pizza_order_msgs
get_serialized_size(
  const pizza_order_msgs::msg::OrderDetail & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: detail_id
  {
    size_t item_size = sizeof(ros_message.detail_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: item_id
  {
    size_t item_size = sizeof(ros_message.item_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: item_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.item_name.size() + 1);
  // Member: quantity
  {
    size_t item_size = sizeof(ros_message.quantity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: price
  {
    size_t item_size = sizeof(ros_message.price);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pizza_order_msgs
max_serialized_size_OrderDetail(
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


  // Member: detail_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: item_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: item_name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: quantity
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: price
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = pizza_order_msgs::msg::OrderDetail;
    is_plain =
      (
      offsetof(DataType, price) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _OrderDetail__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const pizza_order_msgs::msg::OrderDetail *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _OrderDetail__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<pizza_order_msgs::msg::OrderDetail *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _OrderDetail__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const pizza_order_msgs::msg::OrderDetail *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _OrderDetail__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_OrderDetail(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _OrderDetail__callbacks = {
  "pizza_order_msgs::msg",
  "OrderDetail",
  _OrderDetail__cdr_serialize,
  _OrderDetail__cdr_deserialize,
  _OrderDetail__get_serialized_size,
  _OrderDetail__max_serialized_size
};

static rosidl_message_type_support_t _OrderDetail__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_OrderDetail__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace pizza_order_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_pizza_order_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<pizza_order_msgs::msg::OrderDetail>()
{
  return &pizza_order_msgs::msg::typesupport_fastrtps_cpp::_OrderDetail__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, pizza_order_msgs, msg, OrderDetail)() {
  return &pizza_order_msgs::msg::typesupport_fastrtps_cpp::_OrderDetail__handle;
}

#ifdef __cplusplus
}
#endif
