/** @file */
#ifndef __STL_CONCEPT_DETAIL_HAS_MEMBER_RESULT_TYPE_HPP__
#define __STL_CONCEPT_DETAIL_HAS_MEMBER_RESULT_TYPE_HPP__

#include <boost/type_traits/integral_constant.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>
#include "concept/detail/na_type.hpp"

namespace stl_concept {
namespace __detail {
namespace {

template <class T>
struct __has_member_result_type_impl
{
    template <class C, typename C::result_type* = nullptr>
    static boost::type_traits::yes_type test(int);

    template <class C>
    static boost::type_traits::no_type test(...);

    static constexpr bool value = (sizeof(test<T>(0)) == sizeof(boost::type_traits::yes_type));
};

} // namespace

/// @cond DEV
/**
 * @struct stl_concept::__detail::__has_member_result_type
 * @brief Check if type T has member type named result_type.
 *
 * This is useful for dealing with standard functional types like std::function, std::bind, std::mem_fn, etc..
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/utility/functional/function
 * @see https://en.cppreference.com/w/cpp/utility/functional/mem_fn
 * @see https://en.cppreference.com/w/cpp/utility/functional/bind
 * @see https://en.cppreference.com/w/cpp/utility/functional/reference_wrapper
 */
template <class T>
struct __has_member_result_type : boost::integral_constant<bool, __has_member_result_type_impl<T>::value> {};
/// @endcond

} // namespace __detail
} // namespace stl_concept

#endif  // __STL_CONCEPT_DETAIL_HAS_MEMBER_RESULT_TYPE_HPP__
