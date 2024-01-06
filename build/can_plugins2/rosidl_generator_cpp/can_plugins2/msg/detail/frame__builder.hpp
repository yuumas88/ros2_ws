// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from can_plugins2:msg/Frame.idl
// generated code does not contain a copyright notice

#ifndef CAN_PLUGINS2__MSG__DETAIL__FRAME__BUILDER_HPP_
#define CAN_PLUGINS2__MSG__DETAIL__FRAME__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "can_plugins2/msg/detail/frame__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace can_plugins2
{

namespace msg
{

namespace builder
{

class Init_Frame_data
{
public:
  explicit Init_Frame_data(::can_plugins2::msg::Frame & msg)
  : msg_(msg)
  {}
  ::can_plugins2::msg::Frame data(::can_plugins2::msg::Frame::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::can_plugins2::msg::Frame msg_;
};

class Init_Frame_dlc
{
public:
  explicit Init_Frame_dlc(::can_plugins2::msg::Frame & msg)
  : msg_(msg)
  {}
  Init_Frame_data dlc(::can_plugins2::msg::Frame::_dlc_type arg)
  {
    msg_.dlc = std::move(arg);
    return Init_Frame_data(msg_);
  }

private:
  ::can_plugins2::msg::Frame msg_;
};

class Init_Frame_is_error
{
public:
  explicit Init_Frame_is_error(::can_plugins2::msg::Frame & msg)
  : msg_(msg)
  {}
  Init_Frame_dlc is_error(::can_plugins2::msg::Frame::_is_error_type arg)
  {
    msg_.is_error = std::move(arg);
    return Init_Frame_dlc(msg_);
  }

private:
  ::can_plugins2::msg::Frame msg_;
};

class Init_Frame_is_extended
{
public:
  explicit Init_Frame_is_extended(::can_plugins2::msg::Frame & msg)
  : msg_(msg)
  {}
  Init_Frame_is_error is_extended(::can_plugins2::msg::Frame::_is_extended_type arg)
  {
    msg_.is_extended = std::move(arg);
    return Init_Frame_is_error(msg_);
  }

private:
  ::can_plugins2::msg::Frame msg_;
};

class Init_Frame_is_rtr
{
public:
  explicit Init_Frame_is_rtr(::can_plugins2::msg::Frame & msg)
  : msg_(msg)
  {}
  Init_Frame_is_extended is_rtr(::can_plugins2::msg::Frame::_is_rtr_type arg)
  {
    msg_.is_rtr = std::move(arg);
    return Init_Frame_is_extended(msg_);
  }

private:
  ::can_plugins2::msg::Frame msg_;
};

class Init_Frame_id
{
public:
  explicit Init_Frame_id(::can_plugins2::msg::Frame & msg)
  : msg_(msg)
  {}
  Init_Frame_is_rtr id(::can_plugins2::msg::Frame::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Frame_is_rtr(msg_);
  }

private:
  ::can_plugins2::msg::Frame msg_;
};

class Init_Frame_header
{
public:
  Init_Frame_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Frame_id header(::can_plugins2::msg::Frame::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Frame_id(msg_);
  }

private:
  ::can_plugins2::msg::Frame msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::can_plugins2::msg::Frame>()
{
  return can_plugins2::msg::builder::Init_Frame_header();
}

}  // namespace can_plugins2

#endif  // CAN_PLUGINS2__MSG__DETAIL__FRAME__BUILDER_HPP_
