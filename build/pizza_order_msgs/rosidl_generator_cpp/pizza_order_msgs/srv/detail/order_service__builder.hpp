// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pizza_order_msgs:srv/OrderService.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__SRV__DETAIL__ORDER_SERVICE__BUILDER_HPP_
#define PIZZA_ORDER_MSGS__SRV__DETAIL__ORDER_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pizza_order_msgs/srv/detail/order_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pizza_order_msgs
{

namespace srv
{

namespace builder
{

class Init_OrderService_Request_order_details
{
public:
  explicit Init_OrderService_Request_order_details(::pizza_order_msgs::srv::OrderService_Request & msg)
  : msg_(msg)
  {}
  ::pizza_order_msgs::srv::OrderService_Request order_details(::pizza_order_msgs::srv::OrderService_Request::_order_details_type arg)
  {
    msg_.order_details = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pizza_order_msgs::srv::OrderService_Request msg_;
};

class Init_OrderService_Request_detail_id
{
public:
  explicit Init_OrderService_Request_detail_id(::pizza_order_msgs::srv::OrderService_Request & msg)
  : msg_(msg)
  {}
  Init_OrderService_Request_order_details detail_id(::pizza_order_msgs::srv::OrderService_Request::_detail_id_type arg)
  {
    msg_.detail_id = std::move(arg);
    return Init_OrderService_Request_order_details(msg_);
  }

private:
  ::pizza_order_msgs::srv::OrderService_Request msg_;
};

class Init_OrderService_Request_table_number
{
public:
  explicit Init_OrderService_Request_table_number(::pizza_order_msgs::srv::OrderService_Request & msg)
  : msg_(msg)
  {}
  Init_OrderService_Request_detail_id table_number(::pizza_order_msgs::srv::OrderService_Request::_table_number_type arg)
  {
    msg_.table_number = std::move(arg);
    return Init_OrderService_Request_detail_id(msg_);
  }

private:
  ::pizza_order_msgs::srv::OrderService_Request msg_;
};

class Init_OrderService_Request_order_id
{
public:
  Init_OrderService_Request_order_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OrderService_Request_table_number order_id(::pizza_order_msgs::srv::OrderService_Request::_order_id_type arg)
  {
    msg_.order_id = std::move(arg);
    return Init_OrderService_Request_table_number(msg_);
  }

private:
  ::pizza_order_msgs::srv::OrderService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::pizza_order_msgs::srv::OrderService_Request>()
{
  return pizza_order_msgs::srv::builder::Init_OrderService_Request_order_id();
}

}  // namespace pizza_order_msgs


namespace pizza_order_msgs
{

namespace srv
{

namespace builder
{

class Init_OrderService_Response_order_result
{
public:
  Init_OrderService_Response_order_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::pizza_order_msgs::srv::OrderService_Response order_result(::pizza_order_msgs::srv::OrderService_Response::_order_result_type arg)
  {
    msg_.order_result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pizza_order_msgs::srv::OrderService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::pizza_order_msgs::srv::OrderService_Response>()
{
  return pizza_order_msgs::srv::builder::Init_OrderService_Response_order_result();
}

}  // namespace pizza_order_msgs

#endif  // PIZZA_ORDER_MSGS__SRV__DETAIL__ORDER_SERVICE__BUILDER_HPP_
