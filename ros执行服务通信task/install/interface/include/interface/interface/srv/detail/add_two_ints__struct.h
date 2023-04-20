// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interface:srv/AddTwoInts.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__SRV__DETAIL__ADD_TWO_INTS__STRUCT_H_
#define INTERFACE__SRV__DETAIL__ADD_TWO_INTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/AddTwoInts in the package interface.
typedef struct interface__srv__AddTwoInts_Request
{
  /// 第一个加数
  int64_t a;
  /// 第二个加数
  int64_t b;
} interface__srv__AddTwoInts_Request;

// Struct for a sequence of interface__srv__AddTwoInts_Request.
typedef struct interface__srv__AddTwoInts_Request__Sequence
{
  interface__srv__AddTwoInts_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interface__srv__AddTwoInts_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/AddTwoInts in the package interface.
typedef struct interface__srv__AddTwoInts_Response
{
  /// 求和结果
  int64_t sum;
} interface__srv__AddTwoInts_Response;

// Struct for a sequence of interface__srv__AddTwoInts_Response.
typedef struct interface__srv__AddTwoInts_Response__Sequence
{
  interface__srv__AddTwoInts_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interface__srv__AddTwoInts_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACE__SRV__DETAIL__ADD_TWO_INTS__STRUCT_H_
