// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pizza_order_msgs:msg/OrderDetail.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_DETAIL__TRAITS_HPP_
#define PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_DETAIL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pizza_order_msgs/msg/detail/order_detail__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace pizza_order_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const OrderDetail & msg,
  std::ostream & out)
{
  out << "{";
  // member: detail_id
  {
    out << "detail_id: ";
    rosidl_generator_traits::value_to_yaml(msg.detail_id, out);
    out << ", ";
  }

  // member: item_id
  {
    out << "item_id: ";
    rosidl_generator_traits::value_to_yaml(msg.item_id, out);
    out << ", ";
  }

  // member: item_name
  {
    out << "item_name: ";
    rosidl_generator_traits::value_to_yaml(msg.item_name, out);
    out << ", ";
  }

  // member: quantity
  {
    out << "quantity: ";
    rosidl_generator_traits::value_to_yaml(msg.quantity, out);
    out << ", ";
  }

  // member: price
  {
    out << "price: ";
    rosidl_generator_traits::value_to_yaml(msg.price, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OrderDetail & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: detail_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "detail_id: ";
    rosidl_generator_traits::value_to_yaml(msg.detail_id, out);
    out << "\n";
  }

  // member: item_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "item_id: ";
    rosidl_generator_traits::value_to_yaml(msg.item_id, out);
    out << "\n";
  }

  // member: item_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "item_name: ";
    rosidl_generator_traits::value_to_yaml(msg.item_name, out);
    out << "\n";
  }

  // member: quantity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "quantity: ";
    rosidl_generator_traits::value_to_yaml(msg.quantity, out);
    out << "\n";
  }

  // member: price
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "price: ";
    rosidl_generator_traits::value_to_yaml(msg.price, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OrderDetail & msg, bool use_flow_style = false)
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
  const pizza_order_msgs::msg::OrderDetail & msg,
  std::ostream & out, size_t indentation = 0)
{
  pizza_order_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pizza_order_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pizza_order_msgs::msg::OrderDetail & msg)
{
  return pizza_order_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pizza_order_msgs::msg::OrderDetail>()
{
  return "pizza_order_msgs::msg::OrderDetail";
}

template<>
inline const char * name<pizza_order_msgs::msg::OrderDetail>()
{
  return "pizza_order_msgs/msg/OrderDetail";
}

template<>
struct has_fixed_size<pizza_order_msgs::msg::OrderDetail>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pizza_order_msgs::msg::OrderDetail>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pizza_order_msgs::msg::OrderDetail>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_DETAIL__TRAITS_HPP_
