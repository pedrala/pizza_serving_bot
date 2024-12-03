// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pizza_order_msgs:srv/GoalLoc.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__SRV__DETAIL__GOAL_LOC__BUILDER_HPP_
#define PIZZA_ORDER_MSGS__SRV__DETAIL__GOAL_LOC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pizza_order_msgs/srv/detail/goal_loc__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pizza_order_msgs
{

namespace srv
{

namespace builder
{

class Init_GoalLoc_Request_status
{
public:
  explicit Init_GoalLoc_Request_status(::pizza_order_msgs::srv::GoalLoc_Request & msg)
  : msg_(msg)
  {}
  ::pizza_order_msgs::srv::GoalLoc_Request status(::pizza_order_msgs::srv::GoalLoc_Request::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pizza_order_msgs::srv::GoalLoc_Request msg_;
};

class Init_GoalLoc_Request_table_number
{
public:
  explicit Init_GoalLoc_Request_table_number(::pizza_order_msgs::srv::GoalLoc_Request & msg)
  : msg_(msg)
  {}
  Init_GoalLoc_Request_status table_number(::pizza_order_msgs::srv::GoalLoc_Request::_table_number_type arg)
  {
    msg_.table_number = std::move(arg);
    return Init_GoalLoc_Request_status(msg_);
  }

private:
  ::pizza_order_msgs::srv::GoalLoc_Request msg_;
};

class Init_GoalLoc_Request_order_id
{
public:
  Init_GoalLoc_Request_order_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoalLoc_Request_table_number order_id(::pizza_order_msgs::srv::GoalLoc_Request::_order_id_type arg)
  {
    msg_.order_id = std::move(arg);
    return Init_GoalLoc_Request_table_number(msg_);
  }

private:
  ::pizza_order_msgs::srv::GoalLoc_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::pizza_order_msgs::srv::GoalLoc_Request>()
{
  return pizza_order_msgs::srv::builder::Init_GoalLoc_Request_order_id();
}

}  // namespace pizza_order_msgs


namespace pizza_order_msgs
{

namespace srv
{

namespace builder
{

class Init_GoalLoc_Response_y
{
public:
  explicit Init_GoalLoc_Response_y(::pizza_order_msgs::srv::GoalLoc_Response & msg)
  : msg_(msg)
  {}
  ::pizza_order_msgs::srv::GoalLoc_Response y(::pizza_order_msgs::srv::GoalLoc_Response::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pizza_order_msgs::srv::GoalLoc_Response msg_;
};

class Init_GoalLoc_Response_x
{
public:
  explicit Init_GoalLoc_Response_x(::pizza_order_msgs::srv::GoalLoc_Response & msg)
  : msg_(msg)
  {}
  Init_GoalLoc_Response_y x(::pizza_order_msgs::srv::GoalLoc_Response::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_GoalLoc_Response_y(msg_);
  }

private:
  ::pizza_order_msgs::srv::GoalLoc_Response msg_;
};

class Init_GoalLoc_Response_send_result
{
public:
  Init_GoalLoc_Response_send_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoalLoc_Response_x send_result(::pizza_order_msgs::srv::GoalLoc_Response::_send_result_type arg)
  {
    msg_.send_result = std::move(arg);
    return Init_GoalLoc_Response_x(msg_);
  }

private:
  ::pizza_order_msgs::srv::GoalLoc_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::pizza_order_msgs::srv::GoalLoc_Response>()
{
  return pizza_order_msgs::srv::builder::Init_GoalLoc_Response_send_result();
}

}  // namespace pizza_order_msgs

#endif  // PIZZA_ORDER_MSGS__SRV__DETAIL__GOAL_LOC__BUILDER_HPP_
