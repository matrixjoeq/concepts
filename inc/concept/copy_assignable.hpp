
#ifndef __STL_CONCEPT_COPY_ASSIGNABLE_HPP__
#define __STL_CONCEPT_COPY_ASSIGNABLE_HPP__

#include "concept/move_assignable.hpp"
#include <boost/type_traits/declval.hpp>
#include <boost/concept/usage.hpp>
#include <boost/concept/detail/concept_def.hpp>

#if (defined _MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // object 'class' can never be instantiated - user-defined constructor required
#endif

namespace stl_concept {

/**
 * @addtogroup basic_group Basic Requirements
 * @class stl_concept::CopyAssignable
 * @brief Specifies that an instance of the type can be copy-assigned from an lvalue expression.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type T satisfies <i>CopyAssignable</i> if
 * <ul style="list-style-type:disc">
 *   <li>The type T satisfies <i>MoveAssignable</i>, and</li>
 * </ul>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>t, a modifiable lvalue expression of type T</li>
 *   <li>v, an lvalue expression of type T or const T or an rvalue expression of type const T</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Return type<th>Return value<th>Post-conditions
 *   <tr><td>t = v     <td>T&         <td>t           <td>The value of t is equivalent to the value of v.<br/>
 *                                                        The value of v is unchanged.
 * </table>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/CopyAssignable
 * @see https://en.cppreference.com/w/cpp/concepts/Copyable
 */
BOOST_concept(CopyAssignable, (T)) : MoveAssignable<T>
{
    BOOST_CONCEPT_USAGE(CopyAssignable)
    {
        t_ = v_;
        const_lvalue_constraints(v_);
        const_rvalue_constraints();
    }

private:
    void const_lvalue_constraints(const T& x)
    {
        t_ = x;
    }

    void const_rvalue_constraints()
    {
        t_ = boost::declval<const T>();
    }

    T t_;
    T v_;
};

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_COPY_ASSIGNABLE_HPP__
