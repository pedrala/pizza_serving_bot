// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pizza_order_msgs:srv/GoalLoc.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__SRV__DETAIL__GOAL_LOC__STRUCT_HPP_
#define PIZZA_ORDER_MSGS__SRV__DETAIL__GOAL_LOC__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__pizza_order_msgs__srv__GoalLoc_Request __attribute__((deprecated))
#else
# define DEPRECATED__pizza_order_msgs__srv__GoalLoc_Request __declspec(deprecated)
#endif

namespace pizza_order_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GoalLoc_Request_
{
  using Type = GoalLoc_Request_<ContainerAllocator>;

  explicit GoalLoc_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->order_id = 0;
      this->table_number = 0;
      this->status = "";
    }
  }

  explicit GoalLoc_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    pizza_order_msgs::srv::GoalLoc_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const pizza_order_msgs::srv::GoalLoc_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pizza_order_msgs::srv::GoalLoc_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pizza_order_msgs::srv::GoalLoc_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pizza_order_msgs::srv::GoalLoc_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pizza_order_msgs::srv::GoalLoc_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pizza_order_msgs::srv::GoalLoc_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pizza_order_msgs::srv::GoalLoc_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pizza_order_msgs::srv::GoalLoc_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pizza_order_msgs::srv::GoalLoc_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pizza_order_msgs__srv__GoalLoc_Request
    std::shared_ptr<pizza_order_msgs::srv::GoalLoc_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pizza_order_msgs__srv__GoalLoc_Request
    std::shared_ptr<pizza_order_msgs::srv::GoalLoc_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GoalLoc_Request_ & other) const
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
  bool operator!=(const GoalLoc_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GoalLoc_Request_

// alias to use template instance with default allocator
using GoalLoc_Request =
  pizza_order_msgs::srv::GoalLoc_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace pizza_order_msgs


#ifndef _WIN32
# define DEPRECATED__pizza_order_msgs__srv__GoalLoc_Response __attribute__((deprecated))
#else
# define DEPRECATED__pizza_order_msgs__srv__GoalLoc_Response __declspec(deprecated)
#endif

namespace pizza_order_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GoalLoc_Response_
{
  using Type = GoalLoc_Response_<ContainerAllocator>;

  explicit GoalLoc_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->send_result = false;
      this->x = 0.0f;
      this->y = 0.0f;
    }
  }

  explicit GoalLoc_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->send_result = false;
      this->x = 0.0f;
      this->y = 0.0f;
    }
  }

  // field types and members
  using _send_result_type =
    bool;
  _send_result_type send_result;
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;

  // setters for named parameter idiom
  Type & set__send_result(
    const bool & _arg)
  {
    this->send_result = _arg;
    return *this;
  }
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pizza_order_msgs::srv::GoalLoc_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const pizza_order_msgs::srv::GoalLoc_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pizza_order_msgs::srv::GoalLoc_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pizza_order_msgs::srv::GoalLoc_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pizza_order_msgs::srv::GoalLoc_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pizza_order_msgs::srv::GoalLoc_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pizza_order_msgs::srv::GoalLoc_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pizza_order_msgs::srv::GoalLoc_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pizza_order_msgs::srv::GoalLoc_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pizza_order_msgs::srv::GoalLoc_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pizza_order_msgs__srv__GoalLoc_Response
    std::shared_ptr<pizza_order_msgs::srv::GoalLoc_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pizza_order_msgs__srv__GoalLoc_Response
    std::shared_ptr<pizza_order_msgs::srv::GoalLoc_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GoalLoc_Response_ & other) const
  {
    if (this->send_result != other.send_result) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const GoalLoc_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GoalLoc_Response_

// alias to use template instance with default allocator
using GoalLoc_Response =
  pizza_order_msgs::srv::GoalLoc_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace pizza_order_msgs

namespace pizza_order_msgs
{

namespace srv
{

struct GoalLoc
{
  using Request = pizza_order_msgs::srv::GoalLoc_Request;
  using Response = pizza_order_msgs::srv::GoalLoc_Response;
};

}  // namespace srv

}  // namespace pizza_order_msgs

#endif  // PIZZA_ORDER_MSGS__SRV__DETAIL__GOAL_LOC__STRUCT_HPP_
