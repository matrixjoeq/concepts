/** @file */
#ifndef __STL_CONCEPT_DETAIL_REFERENCEABLE_HPP__
#define __STL_CONCEPT_DETAIL_REFERENCEABLE_HPP__

#include <boost/type_traits/remove_cv_ref.hpp>
#include <boost/concept/usage.hpp>
#include <boost/concept/detail/concept_def.hpp>
#include "concept/detail/unuse.hpp"

#if (defined _MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4197) // topmost volatile ignored
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // object 'class' can never be instantiated - user-defined constructor required
#endif

namespace stl_concept {
namespace __detail {

/// @cond DEV
/**
 * @struct stl_concept::__detail::__Referenceable
 * @brief Specifies that an instance of the type can be referenced.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type T satisfies <i>__Referenceable</i> if
 * Given
 * <ul style="list-style-type:disc">
 *   <li>t, an lvalue expression of type T</li>
 *   <li>r, an lvalue reference of type T</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Return type<th>Return value<th>Post-conditions
 *   <tr><td>r = t     <td>T&         <td>t           <td>The value of r is equivalent to the value of t.<br/>
 *                                                        The value of t is unchanged.
 * </table>
 * </p>
 * @tparam T - type to be checked
 */
#ifdef DOXYGEN_WORKING
template <typename T> struct __Referenceable {};
#else // DOXYGEN_WORKING
BOOST_concept(__Referenceable, (T))
{
    BOOST_CONCEPT_USAGE(__Referenceable)
    {
        _Tp& r = t_;
        __detail::__unuse(r);
    }

private:
    using _Tp = typename boost::remove_cv_ref<T>::type;
    _Tp t_;
};
#endif // DOXYGEN_WORKING
/// @endcond

template <class T> struct __Referenceable<T[]> {};
template <class T, size_t N> struct __Referenceable<T[N]> {};
template <class R, class... Args> struct __Referenceable<R(Args...)> {};

} // namespace __detail
} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_DETAIL_REFERENCEABLE_HPP__
