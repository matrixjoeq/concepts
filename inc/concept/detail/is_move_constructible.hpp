/** @file */
#ifndef __STL_CONCEPT_DETAIL_IS_MOVE_CONSTRUCTIBLE_HPP__
#define __STL_CONCEPT_DETAIL_IS_MOVE_CONSTRUCTIBLE_HPP__

#include <type_traits>

namespace stl_concept {
namespace __detail {

/// @cond DEV
/**
 * @struct __is_move_constructible
 * @brief Check if type T is move constructible
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/types/is_move_constructible
 */
template <class T>
struct __is_move_constructible
    : std::is_constructible<
        T,
        typename std::add_rvalue_reference<T>::type
    >
{};
/// @endcond

} // namespace __detail
} // namespace stl_concept

#endif  // __STL_CONCEPT_DETAIL_IS_MOVE_CONSTRUCTIBLE_HPP__
