// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from can_plugins2:msg/Frame.idl
// generated code does not contain a copyright notice

#ifndef CAN_PLUGINS2__MSG__DETAIL__FRAME__TRAITS_HPP_
#define CAN_PLUGINS2__MSG__DETAIL__FRAME__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "can_plugins2/msg/detail/frame__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace can_plugins2
{

namespace msg
{

inline void to_flow_style_yaml(
  const Frame & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: is_rtr
  {
    out << "is_rtr: ";
    rosidl_generator_traits::value_to_yaml(msg.is_rtr, out);
    out << ", ";
  }

  // member: is_extended
  {
    out << "is_extended: ";
    rosidl_generator_traits::value_to_yaml(msg.is_extended, out);
    out << ", ";
  }

  // member: is_error
  {
    out << "is_error: ";
    rosidl_generator_traits::value_to_yaml(msg.is_error, out);
    out << ", ";
  }

  // member: dlc
  {
    out << "dlc: ";
    rosidl_generator_traits::value_to_yaml(msg.dlc, out);
    out << ", ";
  }

  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Frame & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: is_rtr
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_rtr: ";
    rosidl_generator_traits::value_to_yaml(msg.is_rtr, out);
    out << "\n";
  }

  // member: is_extended
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_extended: ";
    rosidl_generator_traits::value_to_yaml(msg.is_extended, out);
    out << "\n";
  }

  // member: is_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_error: ";
    rosidl_generator_traits::value_to_yaml(msg.is_error, out);
    out << "\n";
  }

  // member: dlc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dlc: ";
    rosidl_generator_traits::value_to_yaml(msg.dlc, out);
    out << "\n";
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Frame & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace can_plugins2

namespace rosidl_generator_traits
{

[[deprecated("use can_plugins2::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const can_plugins2::msg::Frame & msg,
  std::ostream & out, size_t indentation = 0)
{
  can_plugins2::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use can_plugins2::msg::to_yaml() instead")]]
inline std::string to_yaml(const can_plugins2::msg::Frame & msg)
{
  return can_plugins2::msg::to_yaml(msg);
}

template<>
inline const char * data_type<can_plugins2::msg::Frame>()
{
  return "can_plugins2::msg::Frame";
}

template<>
inline const char * name<can_plugins2::msg::Frame>()
{
  return "can_plugins2/msg/Frame";
}

template<>
struct has_fixed_size<can_plugins2::msg::Frame>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<can_plugins2::msg::Frame>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<can_plugins2::msg::Frame>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CAN_PLUGINS2__MSG__DETAIL__FRAME__TRAITS_HPP_
