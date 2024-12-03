// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pizza_order_msgs:msg/CallManager.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__MSG__DETAIL__CALL_MANAGER__STRUCT_HPP_
#define PIZZA_ORDER_MSGS__MSG__DETAIL__CALL_MANAGER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__pizza_order_msgs__msg__CallManager __attribute__((deprecated))
#else
# define DEPRECATED__pizza_order_msgs__msg__CallManager __declspec(deprecated)
#endif

namespace pizza_order_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CallManager_
{
  using Type = CallManager_<ContainerAllocator>;

  explicit CallManager_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->table_number = 0;
    }
  }

  explicit CallManager_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->table_number = 0;
    }
  }

  // field types and members
  using _table_number_type =
    int8_t;
  _table_number_type table_number;

  // setters for named parameter idiom
  Type & set__table_number(
    const int8_t & _arg)
  {
    this->table_number = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pizza_order_msgs::msg::CallManager_<ContainerAllocator> *;
  using ConstRawPtr =
    const pizza_order_msgs::msg::CallManager_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pizza_order_msgs::msg::CallManager_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pizza_order_msgs::msg::CallManager_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pizza_order_msgs::msg::CallManager_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pizza_order_msgs::msg::CallManager_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pizza_order_msgs::msg::CallManager_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pizza_order_msgs::msg::CallManager_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pizza_order_msgs::msg::CallManager_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pizza_order_msgs::msg::CallManager_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pizza_order_msgs__msg__CallManager
    std::shared_ptr<pizza_order_msgs::msg::CallManager_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pizza_order_msgs__msg__CallManager
    std::shared_ptr<pizza_order_msgs::msg::CallManager_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CallManager_ & other) const
  {
    if (this->table_number != other.table_number) {
      return false;
    }
    return true;
  }
  bool operator!=(const CallManager_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CallManager_

// alias to use template instance with default allocator
using CallManager =
  pizza_order_msgs::msg::CallManager_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pizza_order_msgs

#endif  // PIZZA_ORDER_MSGS__MSG__DETAIL__CALL_MANAGER__STRUCT_HPP_
