// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interface:srv/AddTwoInts.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__SRV__DETAIL__ADD_TWO_INTS__BUILDER_HPP_
#define INTERFACE__SRV__DETAIL__ADD_TWO_INTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interface/srv/detail/add_two_ints__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interface
{

namespace srv
{

namespace builder
{

class Init_AddTwoInts_Request_b
{
public:
  explicit Init_AddTwoInts_Request_b(::interface::srv::AddTwoInts_Request & msg)
  : msg_(msg)
  {}
  ::interface::srv::AddTwoInts_Request b(::interface::srv::AddTwoInts_Request::_b_type arg)
  {
    msg_.b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::srv::AddTwoInts_Request msg_;
};

class Init_AddTwoInts_Request_a
{
public:
  Init_AddTwoInts_Request_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AddTwoInts_Request_b a(::interface::srv::AddTwoInts_Request::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_AddTwoInts_Request_b(msg_);
  }

private:
  ::interface::srv::AddTwoInts_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interface::srv::AddTwoInts_Request>()
{
  return interface::srv::builder::Init_AddTwoInts_Request_a();
}

}  // namespace interface


namespace interface
{

namespace srv
{

namespace builder
{

class Init_AddTwoInts_Response_sum
{
public:
  Init_AddTwoInts_Response_sum()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interface::srv::AddTwoInts_Response sum(::interface::srv::AddTwoInts_Response::_sum_type arg)
  {
    msg_.sum = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::srv::AddTwoInts_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interface::srv::AddTwoInts_Response>()
{
  return interface::srv::builder::Init_AddTwoInts_Response_sum();
}

}  // namespace interface

#endif  // INTERFACE__SRV__DETAIL__ADD_TWO_INTS__BUILDER_HPP_
