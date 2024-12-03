// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pizza_order_msgs:msg/CallManager.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__MSG__DETAIL__CALL_MANAGER__BUILDER_HPP_
#define PIZZA_ORDER_MSGS__MSG__DETAIL__CALL_MANAGER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pizza_order_msgs/msg/detail/call_manager__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pizza_order_msgs
{

namespace msg
{

namespace builder
{

class Init_CallManager_table_number
{
public:
  Init_CallManager_table_number()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::pizza_order_msgs::msg::CallManager table_number(::pizza_order_msgs::msg::CallManager::_table_number_type arg)
  {
    msg_.table_number = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pizza_order_msgs::msg::CallManager msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pizza_order_msgs::msg::CallManager>()
{
  return pizza_order_msgs::msg::builder::Init_CallManager_table_number();
}

}  // namespace pizza_order_msgs

#endif  // PIZZA_ORDER_MSGS__MSG__DETAIL__CALL_MANAGER__BUILDER_HPP_
