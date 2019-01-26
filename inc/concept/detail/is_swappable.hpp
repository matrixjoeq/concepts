/** @file */
#ifndef __STL_CONCEPT_DETAIL_IS_SWAPPABLE_HPP__
#define __STL_CONCEPT_DETAIL_IS_SWAPPABLE_HPP__

#include <type_traits>
#include <utility>
#include "concept/detail/na_type.hpp"
#include "concept/detail/is_referenceable.hpp"

namespace stl_concept {
namespace __detail {

/// @cond DEV
template <class T, class U = T, bool NotVoid = !std::is_void<T>::value && !std::is_void<U>::value>
struct __swappable_with
{
    template <class LHS, class RHS>
    static auto __test(int) -> decltype(std::swap(std::declval<LHS>(), std::declval<RHS>()));

    template <class LHS, class RHS>
    static __na_type __test(...);

    using __swap1 = decltype((__test<T, U>(0)));
    using __swap2 = decltype((__test<U ,T>(0)));

    static constexpr bool value = (!std::is_same<__swap1, __na_type>::value
                                && !std::is_same<__swap2, __na_type>::value);
};

template <class T, class U>
struct __swappable_with<T, U, false> : std::integral_constant<bool, false> {};

/**
 * @struct __is_swappable_with
 * @brief Check if type T is swappable with type U.
 * @tparam T - first type
 * @tparam U - second type, default to T
 * @see https://en.cppreference.com/w/cpp/types/is_swappable
 */
template <class T, class U>
struct __is_swappable_with : std::integral_constant<bool, __swappable_with<T, U>::value> {};

/**
 * @struct __is_swappable
 * @brief Check if object value of type T is swappable.
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/types/is_swappable
 */
template <class T>
struct __is_swappable
    : std::conditional<
        __is_referenceable<T>::value,
        __is_swappable_with<
            typename std::add_lvalue_reference<T>::type,
            typename std::add_lvalue_reference<T>::type>,
        std::integral_constant<bool, false>
    >::type
{};
/// @endcond

} // namespace __detail
} // namespace stl_concept

#endif  // __STL_CONCEPT_DETAIL_IS_SWAPPABLE_HPP__
