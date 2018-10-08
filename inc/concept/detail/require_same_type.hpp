/** @file */
#ifndef __STL_CONCEPT_DETAIL_REQUIRE_SAME_TYPE_HPP__
#define __STL_CONCEPT_DETAIL_REQUIRE_SAME_TYPE_HPP__

namespace stl_concept {
namespace __detail {

/// @cond DEV
/**
 * @struct stl_concept::__detail::__require_same_type
 * @brief Specifies type T and U are the same.
 * @tparam T - first type
 * @tparam U - second type
 */
template <class T, class U>
struct __require_same_type;
/// @endcond

template <class T>
struct __require_same_type<T, T> {};

} // namespace __detail
} // namespace stl_concept

#endif  // __STL_CONCEPT_DETAIL_REQUIRE_SAME_TYPE_HPP__
