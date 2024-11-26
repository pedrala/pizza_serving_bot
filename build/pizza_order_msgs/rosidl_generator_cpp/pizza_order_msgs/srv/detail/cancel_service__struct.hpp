// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pizza_order_msgs:srv/CancelService.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__SRV__DETAIL__CANCEL_SERVICE__STRUCT_HPP_
#define PIZZA_ORDER_MSGS__SRV__DETAIL__CANCEL_SERVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__pizza_order_msgs__srv__CancelService_Request __attribute__((deprecated))
#else
# define DEPRECATED__pizza_order_msgs__srv__CancelService_Request __declspec(deprecated)
#endif

namespace pizza_order_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CancelService_Request_
{
  using Type = CancelService_Request_<ContainerAllocator>;

  explicit CancelService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->order_id = 0;
      this->table_number = 0;
    }
  }

  explicit CancelService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->order_id = 0;
      this->table_number = 0;
    }
  }

  // field types and members
  using _order_id_type =
    int8_t;
  _order_id_type order_id;
  using _table_number_type =
    int8_t;
  _table_number_type table_number;

  // setters for named parameter idiom
  Type & set__order_id(
    const int8_t & _arg)
  {
    this->order_id = _arg;
    return *this;
  }
  Type & set__table_number(
    const int8_t & _arg)
  {
    this->table_number = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pizza_order_msgs::srv::CancelService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const pizza_order_msgs::srv::CancelService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pizza_order_msgs::srv::CancelService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pizza_order_msgs::srv::CancelService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pizza_order_msgs::srv::CancelService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pizza_order_msgs::srv::CancelService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pizza_order_msgs::srv::CancelService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pizza_order_msgs::srv::CancelService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pizza_order_msgs::srv::CancelService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pizza_order_msgs::srv::CancelService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pizza_order_msgs__srv__CancelService_Request
    std::shared_ptr<pizza_order_msgs::srv::CancelService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pizza_order_msgs__srv__CancelService_Request
    std::shared_ptr<pizza_order_msgs::srv::CancelService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CancelService_Request_ & other) const
  {
    if (this->order_id != other.order_id) {
      return false;
    }
    if (this->table_number != other.table_number) {
      return false;
    }
    return true;
  }
  bool operator!=(const CancelService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CancelService_Request_

// alias to use template instance with default allocator
using CancelService_Request =
  pizza_order_msgs::srv::CancelService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace pizza_order_msgs


#ifndef _WIN32
# define DEPRECATED__pizza_order_msgs__srv__CancelService_Response __attribute__((deprecated))
#else
# define DEPRECATED__pizza_order_msgs__srv__CancelService_Response __declspec(deprecated)
#endif

namespace pizza_order_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CancelService_Response_
{
  using Type = CancelService_Response_<ContainerAllocator>;

  explicit CancelService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cancel_result = false;
    }
  }

  explicit CancelService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cancel_result = false;
    }
  }

  // field types and members
  using _cancel_result_type =
    bool;
  _cancel_result_type cancel_result;

  // setters for named parameter idiom
  Type & set__cancel_result(
    const bool & _arg)
  {
    this->cancel_result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pizza_order_msgs::srv::CancelService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const pizza_order_msgs::srv::CancelService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pizza_order_msgs::srv::CancelService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pizza_order_msgs::srv::CancelService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pizza_order_msgs::srv::CancelService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pizza_order_msgs::srv::CancelService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pizza_order_msgs::srv::CancelService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pizza_order_msgs::srv::CancelService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pizza_order_msgs::srv::CancelService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pizza_order_msgs::srv::CancelService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pizza_order_msgs__srv__CancelService_Response
    std::shared_ptr<pizza_order_msgs::srv::CancelService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pizza_order_msgs__srv__CancelService_Response
    std::shared_ptr<pizza_order_msgs::srv::CancelService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CancelService_Response_ & other) const
  {
    if (this->cancel_result != other.cancel_result) {
      return false;
    }
    return true;
  }
  bool operator!=(const CancelService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CancelService_Response_

// alias to use template instance with default allocator
using CancelService_Response =
  pizza_order_msgs::srv::CancelService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace pizza_order_msgs

namespace pizza_order_msgs
{

namespace srv
{

struct CancelService
{
  using Request = pizza_order_msgs::srv::CancelService_Request;
  using Response = pizza_order_msgs::srv::CancelService_Response;
};

}  // namespace srv

}  // namespace pizza_order_msgs

#endif  // PIZZA_ORDER_MSGS__SRV__DETAIL__CANCEL_SERVICE__STRUCT_HPP_
