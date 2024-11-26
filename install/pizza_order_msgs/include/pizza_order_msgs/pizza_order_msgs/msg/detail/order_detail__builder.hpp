// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pizza_order_msgs:msg/OrderDetail.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_DETAIL__BUILDER_HPP_
#define PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_DETAIL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pizza_order_msgs/msg/detail/order_detail__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pizza_order_msgs
{

namespace msg
{

namespace builder
{

class Init_OrderDetail_price
{
public:
  explicit Init_OrderDetail_price(::pizza_order_msgs::msg::OrderDetail & msg)
  : msg_(msg)
  {}
  ::pizza_order_msgs::msg::OrderDetail price(::pizza_order_msgs::msg::OrderDetail::_price_type arg)
  {
    msg_.price = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pizza_order_msgs::msg::OrderDetail msg_;
};

class Init_OrderDetail_quantity
{
public:
  explicit Init_OrderDetail_quantity(::pizza_order_msgs::msg::OrderDetail & msg)
  : msg_(msg)
  {}
  Init_OrderDetail_price quantity(::pizza_order_msgs::msg::OrderDetail::_quantity_type arg)
  {
    msg_.quantity = std::move(arg);
    return Init_OrderDetail_price(msg_);
  }

private:
  ::pizza_order_msgs::msg::OrderDetail msg_;
};

class Init_OrderDetail_item_name
{
public:
  explicit Init_OrderDetail_item_name(::pizza_order_msgs::msg::OrderDetail & msg)
  : msg_(msg)
  {}
  Init_OrderDetail_quantity item_name(::pizza_order_msgs::msg::OrderDetail::_item_name_type arg)
  {
    msg_.item_name = std::move(arg);
    return Init_OrderDetail_quantity(msg_);
  }

private:
  ::pizza_order_msgs::msg::OrderDetail msg_;
};

class Init_OrderDetail_item_id
{
public:
  Init_OrderDetail_item_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OrderDetail_item_name item_id(::pizza_order_msgs::msg::OrderDetail::_item_id_type arg)
  {
    msg_.item_id = std::move(arg);
    return Init_OrderDetail_item_name(msg_);
  }

private:
  ::pizza_order_msgs::msg::OrderDetail msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pizza_order_msgs::msg::OrderDetail>()
{
  return pizza_order_msgs::msg::builder::Init_OrderDetail_item_id();
}

}  // namespace pizza_order_msgs

#endif  // PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_DETAIL__BUILDER_HPP_
