
#ifndef __STL_CONCEPT_COPY_CONSTRUCTIBLE_HPP__
#define __STL_CONCEPT_COPY_CONSTRUCTIBLE_HPP__

#include "concept/move_constructible.hpp"
#include <boost/concept/usage.hpp>
#include <boost/concept/detail/concept_def.hpp>

#include "concept/detail/unuse.hpp"

#if (defined _MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // object 'class' can never be instantiated - user-defined constructor required
#endif

namespace stl_concept {

/**
 * @addtogroup basic_group Basic Requirements
 * @class stl_concept::CopyConstructible
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
BOOST_concept(CopyConstructible, (T)) : MoveConstructible<T>
{
    BOOST_CONCEPT_USAGE(CopyConstructible)
    {
        _Tp u(v_);
        __detail::__unuse(_Tp(v_));
        const_lvalue_constraints(u);
        const_rvalue_constraints();
    }

private:
    using _Tp = boost::remove_const_t<T>;
    _Tp v_;

    void const_lvalue_constraints(const _Tp& x)
    {
        _Tp u(x);
        __detail::__unuse(_Tp(x));
        __detail::__unuse(u);
    }

    void const_rvalue_constraints()
    {
        _Tp u(boost::declval<const _Tp>());
        __detail::__unuse(_Tp(boost::declval<const _Tp>()));
        __detail::__unuse(u);
    }
};

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_COPY_CONSTRUCTIBLE_HPP__
