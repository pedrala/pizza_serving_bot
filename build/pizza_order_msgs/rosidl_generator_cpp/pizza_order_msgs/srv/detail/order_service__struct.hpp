// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pizza_order_msgs:srv/OrderService.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__SRV__DETAIL__ORDER_SERVICE__STRUCT_HPP_
#define PIZZA_ORDER_MSGS__SRV__DETAIL__ORDER_SERVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'order_details'
#include "pizza_order_msgs/msg/detail/order_detail__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pizza_order_msgs__srv__OrderService_Request __attribute__((deprecated))
#else
# define DEPRECATED__pizza_order_msgs__srv__OrderService_Request __declspec(deprecated)
#endif

namespace pizza_order_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct OrderService_Request_
{
  using Type = OrderService_Request_<ContainerAllocator>;

  explicit OrderService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->order_id = 0;
      this->table_number = 0;
      this->detail_id = 0;
    }
  }

  explicit OrderService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->order_id = 0;
      this->table_number = 0;
      this->detail_id = 0;
    }
  }

  // field types and members
  using _order_id_type =
    int8_t;
  _order_id_type order_id;
  using _table_number_type =
    int8_t;
  _table_number_type table_number;
  using _detail_id_type =
    int8_t;
  _detail_id_type detail_id;
  using _order_details_type =
    std::vector<pizza_order_msgs::msg::OrderDetail_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<pizza_order_msgs::msg::OrderDetail_<ContainerAllocator>>>;
  _order_details_type order_details;

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
  Type & set__detail_id(
    const int8_t & _arg)
  {
    this->detail_id = _arg;
    return *this;
  }
  Type & set__order_details(
    const std::vector<pizza_order_msgs::msg::OrderDetail_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<pizza_order_msgs::msg::OrderDetail_<ContainerAllocator>>> & _arg)
  {
    this->order_details = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pizza_order_msgs::srv::OrderService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const pizza_order_msgs::srv::OrderService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pizza_order_msgs::srv::OrderService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pizza_order_msgs::srv::OrderService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pizza_order_msgs::srv::OrderService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pizza_order_msgs::srv::OrderService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pizza_order_msgs::srv::OrderService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pizza_order_msgs::srv::OrderService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pizza_order_msgs::srv::OrderService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pizza_order_msgs::srv::OrderService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pizza_order_msgs__srv__OrderService_Request
    std::shared_ptr<pizza_order_msgs::srv::OrderService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pizza_order_msgs__srv__OrderService_Request
    std::shared_ptr<pizza_order_msgs::srv::OrderService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OrderService_Request_ & other) const
  {
    if (this->order_id != other.order_id) {
      return false;
    }
    if (this->table_number != other.table_number) {
      return false;
    }
    if (this->detail_id != other.detail_id) {
      return false;
    }
    if (this->order_details != other.order_details) {
      return false;
    }
    return true;
  }
  bool operator!=(const OrderService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OrderService_Request_

// alias to use template instance with default allocator
using OrderService_Request =
  pizza_order_msgs::srv::OrderService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace pizza_order_msgs


#ifndef _WIN32
# define DEPRECATED__pizza_order_msgs__srv__OrderService_Response __attribute__((deprecated))
#else
# define DEPRECATED__pizza_order_msgs__srv__OrderService_Response __declspec(deprecated)
#endif

namespace pizza_order_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct OrderService_Response_
{
  using Type = OrderService_Response_<ContainerAllocator>;

  explicit OrderService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->order_result = false;
    }
  }

  explicit OrderService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->order_result = false;
    }
  }

  // field types and members
  using _order_result_type =
    bool;
  _order_result_type order_result;

  // setters for named parameter idiom
  Type & set__order_result(
    const bool & _arg)
  {
    this->order_result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pizza_order_msgs::srv::OrderService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const pizza_order_msgs::srv::OrderService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pizza_order_msgs::srv::OrderService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pizza_order_msgs::srv::OrderService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pizza_order_msgs::srv::OrderService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pizza_order_msgs::srv::OrderService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pizza_order_msgs::srv::OrderService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pizza_order_msgs::srv::OrderService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pizza_order_msgs::srv::OrderService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pizza_order_msgs::srv::OrderService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pizza_order_msgs__srv__OrderService_Response
    std::shared_ptr<pizza_order_msgs::srv::OrderService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pizza_order_msgs__srv__OrderService_Response
    std::shared_ptr<pizza_order_msgs::srv::OrderService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OrderService_Response_ & other) const
  {
    if (this->order_result != other.order_result) {
      return false;
    }
    return true;
  }
  bool operator!=(const OrderService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OrderService_Response_

// alias to use template instance with default allocator
using OrderService_Response =
  pizza_order_msgs::srv::OrderService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace pizza_order_msgs

namespace pizza_order_msgs
{

namespace srv
{

struct OrderService
{
  using Request = pizza_order_msgs::srv::OrderService_Request;
  using Response = pizza_order_msgs::srv::OrderService_Response;
};

}  // namespace srv

}  // namespace pizza_order_msgs

#endif  // PIZZA_ORDER_MSGS__SRV__DETAIL__ORDER_SERVICE__STRUCT_HPP_
