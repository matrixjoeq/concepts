/** @file */
#ifndef __STL_CONCEPT_DETAIL_UNUSE_HPP__
#define __STL_CONCEPT_DETAIL_UNUSE_HPP__

namespace stl_concept {
namespace __detail {

/// @cond DEV
/**
 * @brief Ignore unused object.
 * @tparam T - object type
 */
template <class T>
inline void __unuse(T&&) {}

/**
 * @brief Ignore unused type.
 * @tparam T - object type
 */
template <class T>
struct __Unuse {};
/// @endcond

} // namespace __detail
} // namespace stl_concept

#endif // __STL_CONCEPT_DETAIL_UNUSE_HPP__
