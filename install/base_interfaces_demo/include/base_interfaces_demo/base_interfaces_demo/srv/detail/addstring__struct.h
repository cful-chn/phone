// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from base_interfaces_demo:srv/Addstring.idl
// generated code does not contain a copyright notice

#ifndef BASE_INTERFACES_DEMO__SRV__DETAIL__ADDSTRING__STRUCT_H_
#define BASE_INTERFACES_DEMO__SRV__DETAIL__ADDSTRING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Addstring in the package base_interfaces_demo.
typedef struct base_interfaces_demo__srv__Addstring_Request
{
  /// 请求的字符串数据
  rosidl_runtime_c__String data;
} base_interfaces_demo__srv__Addstring_Request;

// Struct for a sequence of base_interfaces_demo__srv__Addstring_Request.
typedef struct base_interfaces_demo__srv__Addstring_Request__Sequence
{
  base_interfaces_demo__srv__Addstring_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} base_interfaces_demo__srv__Addstring_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Addstring in the package base_interfaces_demo.
typedef struct base_interfaces_demo__srv__Addstring_Response
{
  /// 响应的字符串数据
  rosidl_runtime_c__String result;
} base_interfaces_demo__srv__Addstring_Response;

// Struct for a sequence of base_interfaces_demo__srv__Addstring_Response.
typedef struct base_interfaces_demo__srv__Addstring_Response__Sequence
{
  base_interfaces_demo__srv__Addstring_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} base_interfaces_demo__srv__Addstring_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BASE_INTERFACES_DEMO__SRV__DETAIL__ADDSTRING__STRUCT_H_
