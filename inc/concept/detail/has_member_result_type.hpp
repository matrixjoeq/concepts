
#ifndef __STL_CONCEPT_DETAIL_HAS_MEMBER_RESULT_TYPE_HPP__
#define __STL_CONCEPT_DETAIL_HAS_MEMBER_RESULT_TYPE_HPP__

#include <boost/type_traits/integral_constant.hpp>
#include "concept/detail/na_type.hpp"

namespace stl_concept {
namespace __detail {

template <class T, typename = typename T::result_type>
struct __has_member_result_type : boost::integral_constant<bool, true> {};

template <class T, typename = __na_type>
struct __has_member_result_type : boost::integral_constant<bool, false> {};

} // namespace __detail
} // namespace stl_concept

#endif  // __STL_CONCEPT_DETAIL_HAS_MEMBER_RESULT_TYPE_HPP__
