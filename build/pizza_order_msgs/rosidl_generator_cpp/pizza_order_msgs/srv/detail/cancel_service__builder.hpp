// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pizza_order_msgs:srv/CancelService.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__SRV__DETAIL__CANCEL_SERVICE__BUILDER_HPP_
#define PIZZA_ORDER_MSGS__SRV__DETAIL__CANCEL_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pizza_order_msgs/srv/detail/cancel_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pizza_order_msgs
{

namespace srv
{

namespace builder
{

class Init_CancelService_Request_table_number
{
public:
  explicit Init_CancelService_Request_table_number(::pizza_order_msgs::srv::CancelService_Request & msg)
  : msg_(msg)
  {}
  ::pizza_order_msgs::srv::CancelService_Request table_number(::pizza_order_msgs::srv::CancelService_Request::_table_number_type arg)
  {
    msg_.table_number = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pizza_order_msgs::srv::CancelService_Request msg_;
};

class Init_CancelService_Request_order_id
{
public:
  Init_CancelService_Request_order_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CancelService_Request_table_number order_id(::pizza_order_msgs::srv::CancelService_Request::_order_id_type arg)
  {
    msg_.order_id = std::move(arg);
    return Init_CancelService_Request_table_number(msg_);
  }

private:
  ::pizza_order_msgs::srv::CancelService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::pizza_order_msgs::srv::CancelService_Request>()
{
  return pizza_order_msgs::srv::builder::Init_CancelService_Request_order_id();
}

}  // namespace pizza_order_msgs


namespace pizza_order_msgs
{

namespace srv
{

namespace builder
{

class Init_CancelService_Response_cancel_result
{
public:
  Init_CancelService_Response_cancel_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::pizza_order_msgs::srv::CancelService_Response cancel_result(::pizza_order_msgs::srv::CancelService_Response::_cancel_result_type arg)
  {
    msg_.cancel_result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pizza_order_msgs::srv::CancelService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::pizza_order_msgs::srv::CancelService_Response>()
{
  return pizza_order_msgs::srv::builder::Init_CancelService_Response_cancel_result();
}

}  // namespace pizza_order_msgs

#endif  // PIZZA_ORDER_MSGS__SRV__DETAIL__CANCEL_SERVICE__BUILDER_HPP_
