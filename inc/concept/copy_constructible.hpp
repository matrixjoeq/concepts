/** @file */
#ifndef __STL_CONCEPT_COPY_CONSTRUCTIBLE_HPP__
#define __STL_CONCEPT_COPY_CONSTRUCTIBLE_HPP__

#include "concept/move_constructible.hpp"
#include <boost/type_traits/declval.hpp>
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

/**
 * @addtogroup basic_group Basic Requirements
 * @struct stl_concept::CopyConstructible
 * @brief Specifies that an instance of the type can be copy-constructed from an lvalue expression.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type T satisfies <i>CopyConstructible</i> if
 * <ul style="list-style-type:disc">
 *   <li>The type T satisfies <i>MoveConstructible</i>, and</li>
 * </ul>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>v, an lvalue expression of type T or const T or an rvalue expression of type const T</li>
 *   <li>u, an arbitrary identifier</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Post-conditions
 *   <tr><td>T u = v   <td> The value of u is equivalent to the value of v.<br/>The value of v is unchanged.
 *   <tr><td>T(v)      <td> The value of T(v) is equivalent to the value of v.<br/>The value of v is unchanged.
 * </table>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/CopyConstructible
 * @see https://en.cppreference.com/w/cpp/concepts/CopyConstructible
 */
#ifdef DOXYGEN_WORKING
template <typename T> struct CopyConstructible : MoveConstructible<T> {};
#else // DOXYGEN_WORKING
BOOST_concept(CopyConstructible, (T)) : MoveConstructible<T>
{
    BOOST_CONCEPT_USAGE(CopyConstructible)
    {
        lvalue_constraints();
        const_lvalue_constraints();
        const_rvalue_constraints();
    }

private:
    void lvalue_constraints()
    {
        T u = boost::declval<T&>();
        __detail::__unuse(u);
        __detail::__unuse(T(boost::declval<T&>()));
    }

    void const_lvalue_constraints()
    {
        T u = boost::declval<const T&>();
        __detail::__unuse(u);
        __detail::__unuse(T(boost::declval<const T&>()));
    }

    void const_rvalue_constraints()
    {
        T u = boost::declval<const T&&>();
        __detail::__unuse(u);
        __detail::__unuse(T(boost::declval<const T&&>()));
    }
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_COPY_CONSTRUCTIBLE_HPP__
