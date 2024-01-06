// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from can_plugins2:msg/Frame.idl
// generated code does not contain a copyright notice

#ifndef CAN_PLUGINS2__MSG__DETAIL__FRAME__STRUCT_HPP_
#define CAN_PLUGINS2__MSG__DETAIL__FRAME__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__can_plugins2__msg__Frame __attribute__((deprecated))
#else
# define DEPRECATED__can_plugins2__msg__Frame __declspec(deprecated)
#endif

namespace can_plugins2
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Frame_
{
  using Type = Frame_<ContainerAllocator>;

  explicit Frame_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ul;
      this->is_rtr = false;
      this->is_extended = false;
      this->is_error = false;
      this->dlc = 0;
      std::fill<typename std::array<uint8_t, 8>::iterator, uint8_t>(this->data.begin(), this->data.end(), 0);
    }
  }

  explicit Frame_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    data(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ul;
      this->is_rtr = false;
      this->is_extended = false;
      this->is_error = false;
      this->dlc = 0;
      std::fill<typename std::array<uint8_t, 8>::iterator, uint8_t>(this->data.begin(), this->data.end(), 0);
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _id_type =
    uint32_t;
  _id_type id;
  using _is_rtr_type =
    bool;
  _is_rtr_type is_rtr;
  using _is_extended_type =
    bool;
  _is_extended_type is_extended;
  using _is_error_type =
    bool;
  _is_error_type is_error;
  using _dlc_type =
    uint8_t;
  _dlc_type dlc;
  using _data_type =
    std::array<uint8_t, 8>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__id(
    const uint32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__is_rtr(
    const bool & _arg)
  {
    this->is_rtr = _arg;
    return *this;
  }
  Type & set__is_extended(
    const bool & _arg)
  {
    this->is_extended = _arg;
    return *this;
  }
  Type & set__is_error(
    const bool & _arg)
  {
    this->is_error = _arg;
    return *this;
  }
  Type & set__dlc(
    const uint8_t & _arg)
  {
    this->dlc = _arg;
    return *this;
  }
  Type & set__data(
    const std::array<uint8_t, 8> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    can_plugins2::msg::Frame_<ContainerAllocator> *;
  using ConstRawPtr =
    const can_plugins2::msg::Frame_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<can_plugins2::msg::Frame_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<can_plugins2::msg::Frame_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      can_plugins2::msg::Frame_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<can_plugins2::msg::Frame_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      can_plugins2::msg::Frame_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<can_plugins2::msg::Frame_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<can_plugins2::msg::Frame_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<can_plugins2::msg::Frame_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__can_plugins2__msg__Frame
    std::shared_ptr<can_plugins2::msg::Frame_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__can_plugins2__msg__Frame
    std::shared_ptr<can_plugins2::msg::Frame_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Frame_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    if (this->is_rtr != other.is_rtr) {
      return false;
    }
    if (this->is_extended != other.is_extended) {
      return false;
    }
    if (this->is_error != other.is_error) {
      return false;
    }
    if (this->dlc != other.dlc) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const Frame_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Frame_

// alias to use template instance with default allocator
using Frame =
  can_plugins2::msg::Frame_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace can_plugins2

#endif  // CAN_PLUGINS2__MSG__DETAIL__FRAME__STRUCT_HPP_
