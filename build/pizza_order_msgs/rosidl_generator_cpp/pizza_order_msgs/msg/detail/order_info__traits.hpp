// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pizza_order_msgs:msg/OrderInfo.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_INFO__TRAITS_HPP_
#define PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pizza_order_msgs/msg/detail/order_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace pizza_order_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const OrderInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: order_id
  {
    out << "order_id: ";
    rosidl_generator_traits::value_to_yaml(msg.order_id, out);
    out << ", ";
  }

  // member: table_number
  {
    out << "table_number: ";
    rosidl_generator_traits::value_to_yaml(msg.table_number, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OrderInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: order_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "order_id: ";
    rosidl_generator_traits::value_to_yaml(msg.order_id, out);
    out << "\n";
  }

  // member: table_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "table_number: ";
    rosidl_generator_traits::value_to_yaml(msg.table_number, out);
    out << "\n";
  }

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OrderInfo & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace pizza_order_msgs

namespace rosidl_generator_traits
{

[[deprecated("use pizza_order_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const pizza_order_msgs::msg::OrderInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  pizza_order_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pizza_order_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pizza_order_msgs::msg::OrderInfo & msg)
{
  return pizza_order_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pizza_order_msgs::msg::OrderInfo>()
{
  return "pizza_order_msgs::msg::OrderInfo";
}

template<>
inline const char * name<pizza_order_msgs::msg::OrderInfo>()
{
  return "pizza_order_msgs/msg/OrderInfo";
}

template<>
struct has_fixed_size<pizza_order_msgs::msg::OrderInfo>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pizza_order_msgs::msg::OrderInfo>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pizza_order_msgs::msg::OrderInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_INFO__TRAITS_HPP_
