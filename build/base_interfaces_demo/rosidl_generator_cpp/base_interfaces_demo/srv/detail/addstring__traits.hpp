// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from base_interfaces_demo:srv/Addstring.idl
// generated code does not contain a copyright notice

#ifndef BASE_INTERFACES_DEMO__SRV__DETAIL__ADDSTRING__TRAITS_HPP_
#define BASE_INTERFACES_DEMO__SRV__DETAIL__ADDSTRING__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "base_interfaces_demo/srv/detail/addstring__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace base_interfaces_demo
{

namespace srv
{

inline void to_flow_style_yaml(
  const Addstring_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: data
  {
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Addstring_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Addstring_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace base_interfaces_demo

namespace rosidl_generator_traits
{

[[deprecated("use base_interfaces_demo::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const base_interfaces_demo::srv::Addstring_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  base_interfaces_demo::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use base_interfaces_demo::srv::to_yaml() instead")]]
inline std::string to_yaml(const base_interfaces_demo::srv::Addstring_Request & msg)
{
  return base_interfaces_demo::srv::to_yaml(msg);
}

template<>
inline const char * data_type<base_interfaces_demo::srv::Addstring_Request>()
{
  return "base_interfaces_demo::srv::Addstring_Request";
}

template<>
inline const char * name<base_interfaces_demo::srv::Addstring_Request>()
{
  return "base_interfaces_demo/srv/Addstring_Request";
}

template<>
struct has_fixed_size<base_interfaces_demo::srv::Addstring_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<base_interfaces_demo::srv::Addstring_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<base_interfaces_demo::srv::Addstring_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace base_interfaces_demo
{

namespace srv
{

inline void to_flow_style_yaml(
  const Addstring_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Addstring_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Addstring_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace base_interfaces_demo

namespace rosidl_generator_traits
{

[[deprecated("use base_interfaces_demo::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const base_interfaces_demo::srv::Addstring_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  base_interfaces_demo::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use base_interfaces_demo::srv::to_yaml() instead")]]
inline std::string to_yaml(const base_interfaces_demo::srv::Addstring_Response & msg)
{
  return base_interfaces_demo::srv::to_yaml(msg);
}

template<>
inline const char * data_type<base_interfaces_demo::srv::Addstring_Response>()
{
  return "base_interfaces_demo::srv::Addstring_Response";
}

template<>
inline const char * name<base_interfaces_demo::srv::Addstring_Response>()
{
  return "base_interfaces_demo/srv/Addstring_Response";
}

template<>
struct has_fixed_size<base_interfaces_demo::srv::Addstring_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<base_interfaces_demo::srv::Addstring_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<base_interfaces_demo::srv::Addstring_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<base_interfaces_demo::srv::Addstring>()
{
  return "base_interfaces_demo::srv::Addstring";
}

template<>
inline const char * name<base_interfaces_demo::srv::Addstring>()
{
  return "base_interfaces_demo/srv/Addstring";
}

template<>
struct has_fixed_size<base_interfaces_demo::srv::Addstring>
  : std::integral_constant<
    bool,
    has_fixed_size<base_interfaces_demo::srv::Addstring_Request>::value &&
    has_fixed_size<base_interfaces_demo::srv::Addstring_Response>::value
  >
{
};

template<>
struct has_bounded_size<base_interfaces_demo::srv::Addstring>
  : std::integral_constant<
    bool,
    has_bounded_size<base_interfaces_demo::srv::Addstring_Request>::value &&
    has_bounded_size<base_interfaces_demo::srv::Addstring_Response>::value
  >
{
};

template<>
struct is_service<base_interfaces_demo::srv::Addstring>
  : std::true_type
{
};

template<>
struct is_service_request<base_interfaces_demo::srv::Addstring_Request>
  : std::true_type
{
};

template<>
struct is_service_response<base_interfaces_demo::srv::Addstring_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // BASE_INTERFACES_DEMO__SRV__DETAIL__ADDSTRING__TRAITS_HPP_
