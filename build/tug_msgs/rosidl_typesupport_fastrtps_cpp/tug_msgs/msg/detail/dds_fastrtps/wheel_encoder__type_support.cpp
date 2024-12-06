// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from tug_msgs:msg/WheelEncoder.idl
// generated code does not contain a copyright notice
#include "tug_msgs/msg/detail/wheel_encoder__rosidl_typesupport_fastrtps_cpp.hpp"
#include "tug_msgs/msg/detail/wheel_encoder__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace tug_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tug_msgs
cdr_serialize(
  const tug_msgs::msg::WheelEncoder & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: left_counter
  cdr << ros_message.left_counter;
  // Member: right_counter
  cdr << ros_message.right_counter;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tug_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  tug_msgs::msg::WheelEncoder & ros_message)
{
  // Member: left_counter
  cdr >> ros_message.left_counter;

  // Member: right_counter
  cdr >> ros_message.right_counter;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tug_msgs
get_serialized_size(
  const tug_msgs::msg::WheelEncoder & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: left_counter
  {
    size_t item_size = sizeof(ros_message.left_counter);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_counter
  {
    size_t item_size = sizeof(ros_message.right_counter);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tug_msgs
max_serialized_size_WheelEncoder(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: left_counter
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: right_counter
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = tug_msgs::msg::WheelEncoder;
    is_plain =
      (
      offsetof(DataType, right_counter) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _WheelEncoder__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const tug_msgs::msg::WheelEncoder *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _WheelEncoder__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<tug_msgs::msg::WheelEncoder *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _WheelEncoder__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const tug_msgs::msg::WheelEncoder *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _WheelEncoder__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_WheelEncoder(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _WheelEncoder__callbacks = {
  "tug_msgs::msg",
  "WheelEncoder",
  _WheelEncoder__cdr_serialize,
  _WheelEncoder__cdr_deserialize,
  _WheelEncoder__get_serialized_size,
  _WheelEncoder__max_serialized_size
};

static rosidl_message_type_support_t _WheelEncoder__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_WheelEncoder__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace tug_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_tug_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<tug_msgs::msg::WheelEncoder>()
{
  return &tug_msgs::msg::typesupport_fastrtps_cpp::_WheelEncoder__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tug_msgs, msg, WheelEncoder)() {
  return &tug_msgs::msg::typesupport_fastrtps_cpp::_WheelEncoder__handle;
}

#ifdef __cplusplus
}
#endif
