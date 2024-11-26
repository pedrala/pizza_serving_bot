// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pizza_order_msgs:msg/OrderDetail.idl
// generated code does not contain a copyright notice

#ifndef PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_DETAIL__STRUCT_HPP_
#define PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_DETAIL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__pizza_order_msgs__msg__OrderDetail __attribute__((deprecated))
#else
# define DEPRECATED__pizza_order_msgs__msg__OrderDetail __declspec(deprecated)
#endif

namespace pizza_order_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OrderDetail_
{
  using Type = OrderDetail_<ContainerAllocator>;

  explicit OrderDetail_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->detail_id = 0l;
      this->item_id = 0;
      this->item_name = "";
      this->quantity = 0;
      this->price = 0.0f;
    }
  }

  explicit OrderDetail_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : item_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->detail_id = 0l;
      this->item_id = 0;
      this->item_name = "";
      this->quantity = 0;
      this->price = 0.0f;
    }
  }

  // field types and members
  using _detail_id_type =
    int32_t;
  _detail_id_type detail_id;
  using _item_id_type =
    int8_t;
  _item_id_type item_id;
  using _item_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _item_name_type item_name;
  using _quantity_type =
    int8_t;
  _quantity_type quantity;
  using _price_type =
    float;
  _price_type price;

  // setters for named parameter idiom
  Type & set__detail_id(
    const int32_t & _arg)
  {
    this->detail_id = _arg;
    return *this;
  }
  Type & set__item_id(
    const int8_t & _arg)
  {
    this->item_id = _arg;
    return *this;
  }
  Type & set__item_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->item_name = _arg;
    return *this;
  }
  Type & set__quantity(
    const int8_t & _arg)
  {
    this->quantity = _arg;
    return *this;
  }
  Type & set__price(
    const float & _arg)
  {
    this->price = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pizza_order_msgs::msg::OrderDetail_<ContainerAllocator> *;
  using ConstRawPtr =
    const pizza_order_msgs::msg::OrderDetail_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pizza_order_msgs::msg::OrderDetail_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pizza_order_msgs::msg::OrderDetail_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pizza_order_msgs::msg::OrderDetail_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pizza_order_msgs::msg::OrderDetail_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pizza_order_msgs::msg::OrderDetail_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pizza_order_msgs::msg::OrderDetail_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pizza_order_msgs::msg::OrderDetail_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pizza_order_msgs::msg::OrderDetail_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pizza_order_msgs__msg__OrderDetail
    std::shared_ptr<pizza_order_msgs::msg::OrderDetail_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pizza_order_msgs__msg__OrderDetail
    std::shared_ptr<pizza_order_msgs::msg::OrderDetail_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OrderDetail_ & other) const
  {
    if (this->detail_id != other.detail_id) {
      return false;
    }
    if (this->item_id != other.item_id) {
      return false;
    }
    if (this->item_name != other.item_name) {
      return false;
    }
    if (this->quantity != other.quantity) {
      return false;
    }
    if (this->price != other.price) {
      return false;
    }
    return true;
  }
  bool operator!=(const OrderDetail_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OrderDetail_

// alias to use template instance with default allocator
using OrderDetail =
  pizza_order_msgs::msg::OrderDetail_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pizza_order_msgs

#endif  // PIZZA_ORDER_MSGS__MSG__DETAIL__ORDER_DETAIL__STRUCT_HPP_
