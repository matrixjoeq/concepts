/** @file */
#ifndef __STL_CONCEPT_DETAIL_IS_REFERENCEABLE_HPP__
#define __STL_CONCEPT_DETAIL_IS_REFERENCEABLE_HPP__

#include <type_traits>

namespace stl_concept {
namespace __detail {

/// @cond DEV
struct __is_referenceable_impl
{
    template <class T> static T& __test(int);
    template <class T> static std::false_type __test(...);
};

/**
 * @struct __is_referenceable
 * @brief Check if type T is referenceable.
 * @tparam T - type to be checked
 */
template <class T>
struct __is_referenceable
    : std::integral_constant<
        bool,
        !std::is_same<
            decltype(__is_referenceable_impl::__test<T>(0)),
            std::true_type
        >::value
    >
{};
/// @endcond

} // namespace __detail
} // namespace stl_concept

#endif  // __STL_CONCEPT_DETAIL_IS_REFERENCEABLE_HPP__
