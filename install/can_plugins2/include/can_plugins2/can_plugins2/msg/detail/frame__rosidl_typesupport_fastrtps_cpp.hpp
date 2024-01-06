// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from can_plugins2:msg/Frame.idl
// generated code does not contain a copyright notice

#ifndef CAN_PLUGINS2__MSG__DETAIL__FRAME__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define CAN_PLUGINS2__MSG__DETAIL__FRAME__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "can_plugins2/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "can_plugins2/msg/detail/frame__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace can_plugins2
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_can_plugins2
cdr_serialize(
  const can_plugins2::msg::Frame & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_can_plugins2
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  can_plugins2::msg::Frame & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_can_plugins2
get_serialized_size(
  const can_plugins2::msg::Frame & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_can_plugins2
max_serialized_size_Frame(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace can_plugins2

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_can_plugins2
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, can_plugins2, msg, Frame)();

#ifdef __cplusplus
}
#endif

#endif  // CAN_PLUGINS2__MSG__DETAIL__FRAME__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
