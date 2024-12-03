// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pizza_order_msgs:srv/OrderService.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__SRV__DETAIL__ORDER_SERVICE__TRAITS_HPP_
#define PIZZA_ORDER_MSGS__SRV__DETAIL__ORDER_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pizza_order_msgs/srv/detail/order_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'order_details'
#include "pizza_order_msgs/msg/detail/order_detail__traits.hpp"

namespace pizza_order_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const OrderService_Request & msg,
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

  // member: detail_id
  {
    out << "detail_id: ";
    rosidl_generator_traits::value_to_yaml(msg.detail_id, out);
    out << ", ";
  }

  // member: order_details
  {
    if (msg.order_details.size() == 0) {
      out << "order_details: []";
    } else {
      out << "order_details: [";
      size_t pending_items = msg.order_details.size();
      for (auto item : msg.order_details) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OrderService_Request & msg,
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

  // member: detail_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "detail_id: ";
    rosidl_generator_traits::value_to_yaml(msg.detail_id, out);
    out << "\n";
  }

  // member: order_details
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.order_details.size() == 0) {
      out << "order_details: []\n";
    } else {
      out << "order_details:\n";
      for (auto item : msg.order_details) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OrderService_Request & msg, bool use_flow_style = false)
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
  const pizza_order_msgs::srv::OrderService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  pizza_order_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pizza_order_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const pizza_order_msgs::srv::OrderService_Request & msg)
{
  return pizza_order_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<pizza_order_msgs::srv::OrderService_Request>()
{
  return "pizza_order_msgs::srv::OrderService_Request";
}

template<>
inline const char * name<pizza_order_msgs::srv::OrderService_Request>()
{
  return "pizza_order_msgs/srv/OrderService_Request";
}

template<>
struct has_fixed_size<pizza_order_msgs::srv::OrderService_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pizza_order_msgs::srv::OrderService_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pizza_order_msgs::srv::OrderService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace pizza_order_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const OrderService_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: order_result
  {
    out << "order_result: ";
    rosidl_generator_traits::value_to_yaml(msg.order_result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OrderService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: order_result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "order_result: ";
    rosidl_generator_traits::value_to_yaml(msg.order_result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OrderService_Response & msg, bool use_flow_style = false)
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
  const pizza_order_msgs::srv::OrderService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  pizza_order_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pizza_order_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const pizza_order_msgs::srv::OrderService_Response & msg)
{
  return pizza_order_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<pizza_order_msgs::srv::OrderService_Response>()
{
  return "pizza_order_msgs::srv::OrderService_Response";
}

template<>
inline const char * name<pizza_order_msgs::srv::OrderService_Response>()
{
  return "pizza_order_msgs/srv/OrderService_Response";
}

template<>
struct has_fixed_size<pizza_order_msgs::srv::OrderService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<pizza_order_msgs::srv::OrderService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<pizza_order_msgs::srv::OrderService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<pizza_order_msgs::srv::OrderService>()
{
  return "pizza_order_msgs::srv::OrderService";
}

template<>
inline const char * name<pizza_order_msgs::srv::OrderService>()
{
  return "pizza_order_msgs/srv/OrderService";
}

template<>
struct has_fixed_size<pizza_order_msgs::srv::OrderService>
  : std::integral_constant<
    bool,
    has_fixed_size<pizza_order_msgs::srv::OrderService_Request>::value &&
    has_fixed_size<pizza_order_msgs::srv::OrderService_Response>::value
  >
{
};

template<>
struct has_bounded_size<pizza_order_msgs::srv::OrderService>
  : std::integral_constant<
    bool,
    has_bounded_size<pizza_order_msgs::srv::OrderService_Request>::value &&
    has_bounded_size<pizza_order_msgs::srv::OrderService_Response>::value
  >
{
};

template<>
struct is_service<pizza_order_msgs::srv::OrderService>
  : std::true_type
{
};

template<>
struct is_service_request<pizza_order_msgs::srv::OrderService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<pizza_order_msgs::srv::OrderService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // PIZZA_ORDER_MSGS__SRV__DETAIL__ORDER_SERVICE__TRAITS_HPP_
