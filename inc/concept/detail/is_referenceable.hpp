/** @file */
#ifndef __STL_CONCEPT_DETAIL_IS_REFERENCEABLE_HPP__
#define __STL_CONCEPT_DETAIL_IS_REFERENCEABLE_HPP__

#include <boost/type_traits/detail/yes_no_type.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <boost/type_traits/is_same.hpp>

namespace stl_concept {
namespace __detail {

/// @cond DEV
struct __is_referenceable_impl
{
    template <class T> static T& __test(int);
    template <class T> static boost::type_traits::no_type __test(...);
};

/**
 * @struct __is_referenceable
 * @brief Check if type T is referenceable.
 * @tparam T - type to be checked
 */
template <class T>
struct __is_referenceable : boost::integral_constant<bool,
    !boost::is_same<decltype(__is_referenceable_impl::__test<T>(0)), boost::type_traits::no_type>::value> {};
/// @endcond

} // namespace __detail
} // namespace stl_concept

#endif  // __STL_CONCEPT_DETAIL_IS_REFERENCEABLE_HPP__
