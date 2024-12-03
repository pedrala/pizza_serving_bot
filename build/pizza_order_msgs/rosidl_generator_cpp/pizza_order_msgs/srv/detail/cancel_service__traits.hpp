// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pizza_order_msgs:srv/CancelService.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__SRV__DETAIL__CANCEL_SERVICE__TRAITS_HPP_
#define PIZZA_ORDER_MSGS__SRV__DETAIL__CANCEL_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pizza_order_msgs/srv/detail/cancel_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace pizza_order_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const CancelService_Request & msg,
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CancelService_Request & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CancelService_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace pizza_order_msgs

namespace rosidl_generator_traits
{

[[deprecated("use pizza_order_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const pizza_order_msgs::srv::CancelService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  pizza_order_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pizza_order_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const pizza_order_msgs::srv::CancelService_Request & msg)
{
  return pizza_order_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<pizza_order_msgs::srv::CancelService_Request>()
{
  return "pizza_order_msgs::srv::CancelService_Request";
}

template<>
inline const char * name<pizza_order_msgs::srv::CancelService_Request>()
{
  return "pizza_order_msgs/srv/CancelService_Request";
}

template<>
struct has_fixed_size<pizza_order_msgs::srv::CancelService_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<pizza_order_msgs::srv::CancelService_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<pizza_order_msgs::srv::CancelService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace pizza_order_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const CancelService_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: cancel_result
  {
    out << "cancel_result: ";
    rosidl_generator_traits::value_to_yaml(msg.cancel_result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CancelService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cancel_result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cancel_result: ";
    rosidl_generator_traits::value_to_yaml(msg.cancel_result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CancelService_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace pizza_order_msgs

namespace rosidl_generator_traits
{

[[deprecated("use pizza_order_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const pizza_order_msgs::srv::CancelService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  pizza_order_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pizza_order_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const pizza_order_msgs::srv::CancelService_Response & msg)
{
  return pizza_order_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<pizza_order_msgs::srv::CancelService_Response>()
{
  return "pizza_order_msgs::srv::CancelService_Response";
}

template<>
inline const char * name<pizza_order_msgs::srv::CancelService_Response>()
{
  return "pizza_order_msgs/srv/CancelService_Response";
}

template<>
struct has_fixed_size<pizza_order_msgs::srv::CancelService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<pizza_order_msgs::srv::CancelService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<pizza_order_msgs::srv::CancelService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<pizza_order_msgs::srv::CancelService>()
{
  return "pizza_order_msgs::srv::CancelService";
}

template<>
inline const char * name<pizza_order_msgs::srv::CancelService>()
{
  return "pizza_order_msgs/srv/CancelService";
}

template<>
struct has_fixed_size<pizza_order_msgs::srv::CancelService>
  : std::integral_constant<
    bool,
    has_fixed_size<pizza_order_msgs::srv::CancelService_Request>::value &&
    has_fixed_size<pizza_order_msgs::srv::CancelService_Response>::value
  >
{
};

template<>
struct has_bounded_size<pizza_order_msgs::srv::CancelService>
  : std::integral_constant<
    bool,
    has_bounded_size<pizza_order_msgs::srv::CancelService_Request>::value &&
    has_bounded_size<pizza_order_msgs::srv::CancelService_Response>::value
  >
{
};

template<>
struct is_service<pizza_order_msgs::srv::CancelService>
  : std::true_type
{
};

template<>
struct is_service_request<pizza_order_msgs::srv::CancelService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<pizza_order_msgs::srv::CancelService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // PIZZA_ORDER_MSGS__SRV__DETAIL__CANCEL_SERVICE__TRAITS_HPP_
