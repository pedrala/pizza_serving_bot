// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pizza_order_msgs:msg/OrderInfo.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_INFO__BUILDER_HPP_
#define PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pizza_order_msgs/msg/detail/order_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pizza_order_msgs
{

namespace msg
{

namespace builder
{

class Init_OrderInfo_status
{
public:
  explicit Init_OrderInfo_status(::pizza_order_msgs::msg::OrderInfo & msg)
  : msg_(msg)
  {}
  ::pizza_order_msgs::msg::OrderInfo status(::pizza_order_msgs::msg::OrderInfo::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pizza_order_msgs::msg::OrderInfo msg_;
};

class Init_OrderInfo_table_number
{
public:
  explicit Init_OrderInfo_table_number(::pizza_order_msgs::msg::OrderInfo & msg)
  : msg_(msg)
  {}
  Init_OrderInfo_status table_number(::pizza_order_msgs::msg::OrderInfo::_table_number_type arg)
  {
    msg_.table_number = std::move(arg);
    return Init_OrderInfo_status(msg_);
  }

private:
  ::pizza_order_msgs::msg::OrderInfo msg_;
};

class Init_OrderInfo_order_id
{
public:
  Init_OrderInfo_order_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OrderInfo_table_number order_id(::pizza_order_msgs::msg::OrderInfo::_order_id_type arg)
  {
    msg_.order_id = std::move(arg);
    return Init_OrderInfo_table_number(msg_);
  }

private:
  ::pizza_order_msgs::msg::OrderInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pizza_order_msgs::msg::OrderInfo>()
{
  return pizza_order_msgs::msg::builder::Init_OrderInfo_order_id();
}

}  // namespace pizza_order_msgs

#endif  // PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_INFO__BUILDER_HPP_
