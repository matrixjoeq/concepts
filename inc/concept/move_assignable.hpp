
#ifndef __STL_CONCEPT_MOVE_ASSIGNABLE_HPP__
#define __STL_CONCEPT_MOVE_ASSIGNABLE_HPP__

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
 * @class stl_concept::MoveAssignable
 * @brief Specifies that an instance of the type can be assigned from an rvalue argument.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type T satisfies <i>MoveAssignable</i> if<br/>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>t, a modifiable lvalue expression of type T</li>
 *   <li>rv, an rvalue expression of type T</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Return type<th>Return value<th>Post-conditions
 *   <tr><td>t = rv    <td>T&         <td>t           <td>If t and rv do not refer to the same object, the value of t is
 *                                                        equivalent to the value of rv before the assignment.<br/>
 *                                                        The new value of rv is unspecified.
 * </table>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/MoveAssignable
 * @see https://en.cppreference.com/w/cpp/concepts/Movable
 */
BOOST_concept(MoveAssignable, (T))
{
    BOOST_CONCEPT_USAGE(MoveAssignable)
    {
        t_ = boost::declval<T>();
    }

private:
    T t_;
};

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_MOVE_ASSIGNABLE_HPP__
