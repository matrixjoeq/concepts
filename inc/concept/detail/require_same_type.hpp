
#ifndef __STL_CONCEPT_DETAIL_REQUIRE_SAME_TYPE_HPP__
#define __STL_CONCEPT_DETAIL_REQUIRE_SAME_TYPE_HPP__

namespace stl_concept {
namespace __detail {

template <class T, class U>
struct __require_same_type;

template <class T>
struct __require_same_type<T, T> {};

} // namespace __detail
} // namespace stl_concept

#endif  // __STL_CONCEPT_DETAIL_REQUIRE_SAME_TYPE_HPP__
