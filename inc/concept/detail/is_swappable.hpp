/** @file */
#ifndef __STL_CONCEPT_DETAIL_IS_SWAPPABLE_HPP__
#define __STL_CONCEPT_DETAIL_IS_SWAPPABLE_HPP__

// for swap
#if __cplusplus < 201103L
#include <algorithm>
#else // __cplusplus < 201103L
#include <utility>
#endif // __cplusplus < 201103L

#include <boost/type_traits/add_lvalue_reference.hpp>
#include <boost/type_traits/conditional.hpp>
#include <boost/type_traits/declval.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/is_void.hpp>

#include "concept/detail/na_type.hpp"
#include "concept/detail/is_referenceable.hpp"

namespace stl_concept {
namespace __detail {

/// @cond DEV
template <class T, class U = T, bool NotVoid = !boost::is_void<T>::value && !boost::is_void<U>::value>
struct __swappable_with
{
    template <class LHS, class RHS>
    static auto __test(int) -> decltype(std::swap(boost::declval<LHS>(), boost::declval<RHS>()));

    template <class LHS, class RHS>
    static __na_type __test(...);

    using __swap1 = decltype((__test<T, U>(0)));
    using __swap2 = decltype((__test<U ,T>(0)));

    static constexpr bool value = !boost::is_same<__swap1, __na_type>::value
                               && !boost::is_same<__swap2, __na_type>::value;
};

template <class T, class U>
struct __swappable_with<T, U, false> : boost::integral_constant<bool, false> {};

/**
 * @struct stl_concept::__detail::__is_swappable_with
 * @brief Check if type T is swappable with type U.
 * @tparam T - first type
 * @tparam U - second type, default to T
 * @see https://en.cppreference.com/w/cpp/types/is_swappable
 */
template <class T, class U>
struct __is_swappable_with : boost::integral_constant<bool, __swappable_with<T, U>::value> {};

/**
 * @struct stl_concept::__detail::__is_swappable
 * @brief Check if object value of type T is swappable.
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/types/is_swappable
 */
template <class T>
struct __is_swappable
    : boost::conditional<
        __is_referenceable<T>::value,
        __is_swappable_with<
            typename boost::add_lvalue_reference<T>::type,
            typename boost::add_lvalue_reference<T>::type>,
        boost::integral_constant<bool, false>
    >::type
{};
/// @endcond

} // namespace __detail
} // namespace stl_concept

#endif  // __STL_CONCEPT_DETAIL_IS_SWAPPABLE_HPP__
