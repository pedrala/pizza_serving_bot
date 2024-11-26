// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pizza_order_msgs:msg/CallManager.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__MSG__DETAIL__CALL_MANAGER__TRAITS_HPP_
#define PIZZA_ORDER_MSGS__MSG__DETAIL__CALL_MANAGER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pizza_order_msgs/msg/detail/call_manager__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace pizza_order_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CallManager & msg,
  std::ostream & out)
{
  out << "{";
  // member: table_number
  {
    out << "table_number: ";
    rosidl_generator_traits::value_to_yaml(msg.table_number, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CallManager & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: table_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "table_number: ";
    rosidl_generator_traits::value_to_yaml(msg.table_number, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CallManager & msg, bool use_flow_style = false)
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
  const pizza_order_msgs::msg::CallManager & msg,
  std::ostream & out, size_t indentation = 0)
{
  pizza_order_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pizza_order_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pizza_order_msgs::msg::CallManager & msg)
{
  return pizza_order_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pizza_order_msgs::msg::CallManager>()
{
  return "pizza_order_msgs::msg::CallManager";
}

template<>
inline const char * name<pizza_order_msgs::msg::CallManager>()
{
  return "pizza_order_msgs/msg/CallManager";
}

template<>
struct has_fixed_size<pizza_order_msgs::msg::CallManager>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<pizza_order_msgs::msg::CallManager>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<pizza_order_msgs::msg::CallManager>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PIZZA_ORDER_MSGS__MSG__DETAIL__CALL_MANAGER__TRAITS_HPP_
