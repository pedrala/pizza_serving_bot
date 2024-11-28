// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pizza_order_msgs:msg/OrderInfo.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_INFO__STRUCT_HPP_
#define PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__pizza_order_msgs__msg__OrderInfo __attribute__((deprecated))
#else
# define DEPRECATED__pizza_order_msgs__msg__OrderInfo __declspec(deprecated)
#endif

namespace pizza_order_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OrderInfo_
{
  using Type = OrderInfo_<ContainerAllocator>;

  explicit OrderInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->order_id = 0;
      this->table_number = 0;
      this->status = "";
    }
  }

  explicit OrderInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->order_id = 0;
      this->table_number = 0;
      this->status = "";
    }
  }

  // field types and members
  using _order_id_type =
    int16_t;
  _order_id_type order_id;
  using _table_number_type =
    int16_t;
  _table_number_type table_number;
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__order_id(
    const int16_t & _arg)
  {
    this->order_id = _arg;
    return *this;
  }
  Type & set__table_number(
    const int16_t & _arg)
  {
    this->table_number = _arg;
    return *this;
  }
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pizza_order_msgs::msg::OrderInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const pizza_order_msgs::msg::OrderInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pizza_order_msgs::msg::OrderInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pizza_order_msgs::msg::OrderInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pizza_order_msgs::msg::OrderInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pizza_order_msgs::msg::OrderInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pizza_order_msgs::msg::OrderInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pizza_order_msgs::msg::OrderInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pizza_order_msgs::msg::OrderInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pizza_order_msgs::msg::OrderInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pizza_order_msgs__msg__OrderInfo
    std::shared_ptr<pizza_order_msgs::msg::OrderInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pizza_order_msgs__msg__OrderInfo
    std::shared_ptr<pizza_order_msgs::msg::OrderInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OrderInfo_ & other) const
  {
    if (this->order_id != other.order_id) {
      return false;
    }
    if (this->table_number != other.table_number) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const OrderInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OrderInfo_

// alias to use template instance with default allocator
using OrderInfo =
  pizza_order_msgs::msg::OrderInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pizza_order_msgs

#endif  // PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_INFO__STRUCT_HPP_
