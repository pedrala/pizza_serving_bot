// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pizza_order_msgs:srv/GoalLoc.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__SRV__DETAIL__GOAL_LOC__TRAITS_HPP_
#define PIZZA_ORDER_MSGS__SRV__DETAIL__GOAL_LOC__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pizza_order_msgs/srv/detail/goal_loc__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace pizza_order_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GoalLoc_Request & msg,
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
  const GoalLoc_Request & msg,
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

inline std::string to_yaml(const GoalLoc_Request & msg, bool use_flow_style = false)
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
  const pizza_order_msgs::srv::GoalLoc_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  pizza_order_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pizza_order_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const pizza_order_msgs::srv::GoalLoc_Request & msg)
{
  return pizza_order_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<pizza_order_msgs::srv::GoalLoc_Request>()
{
  return "pizza_order_msgs::srv::GoalLoc_Request";
}

template<>
inline const char * name<pizza_order_msgs::srv::GoalLoc_Request>()
{
  return "pizza_order_msgs/srv/GoalLoc_Request";
}

template<>
struct has_fixed_size<pizza_order_msgs::srv::GoalLoc_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pizza_order_msgs::srv::GoalLoc_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pizza_order_msgs::srv::GoalLoc_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace pizza_order_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GoalLoc_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: send_result
  {
    out << "send_result: ";
    rosidl_generator_traits::value_to_yaml(msg.send_result, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GoalLoc_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: send_result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "send_result: ";
    rosidl_generator_traits::value_to_yaml(msg.send_result, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GoalLoc_Response & msg, bool use_flow_style = false)
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
  const pizza_order_msgs::srv::GoalLoc_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  pizza_order_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pizza_order_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const pizza_order_msgs::srv::GoalLoc_Response & msg)
{
  return pizza_order_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<pizza_order_msgs::srv::GoalLoc_Response>()
{
  return "pizza_order_msgs::srv::GoalLoc_Response";
}

template<>
inline const char * name<pizza_order_msgs::srv::GoalLoc_Response>()
{
  return "pizza_order_msgs/srv/GoalLoc_Response";
}

template<>
struct has_fixed_size<pizza_order_msgs::srv::GoalLoc_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<pizza_order_msgs::srv::GoalLoc_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<pizza_order_msgs::srv::GoalLoc_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<pizza_order_msgs::srv::GoalLoc>()
{
  return "pizza_order_msgs::srv::GoalLoc";
}

template<>
inline const char * name<pizza_order_msgs::srv::GoalLoc>()
{
  return "pizza_order_msgs/srv/GoalLoc";
}

template<>
struct has_fixed_size<pizza_order_msgs::srv::GoalLoc>
  : std::integral_constant<
    bool,
    has_fixed_size<pizza_order_msgs::srv::GoalLoc_Request>::value &&
    has_fixed_size<pizza_order_msgs::srv::GoalLoc_Response>::value
  >
{
};

template<>
struct has_bounded_size<pizza_order_msgs::srv::GoalLoc>
  : std::integral_constant<
    bool,
    has_bounded_size<pizza_order_msgs::srv::GoalLoc_Request>::value &&
    has_bounded_size<pizza_order_msgs::srv::GoalLoc_Response>::value
  >
{
};

template<>
struct is_service<pizza_order_msgs::srv::GoalLoc>
  : std::true_type
{
};

template<>
struct is_service_request<pizza_order_msgs::srv::GoalLoc_Request>
  : std::true_type
{
};

template<>
struct is_service_response<pizza_order_msgs::srv::GoalLoc_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // PIZZA_ORDER_MSGS__SRV__DETAIL__GOAL_LOC__TRAITS_HPP_
