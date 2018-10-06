
#ifndef __STL_CONCEPT_MOVE_CONSTRUCTIBLE_HPP__
#define __STL_CONCEPT_MOVE_CONSTRUCTIBLE_HPP__

#include <boost/type_traits/declval.hpp>
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
 * @class stl_concept::MoveConstructible
 * @brief Specifies that an instance of the type can be constructed from an rvalue argument.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type T satisfies <i>MoveConstructible</i> if<br/>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>rv, an rvalue expression of type T</li>
 *   <li>u, an arbitrary identifier</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Post-conditions
 *   <tr><td>T u = rv  <td>The value of u is equivalent to the value of rv before the initialization.<br/>
 *                         The new value of rv is unspecified.
 *   <tr><td>T(rv)     <td>The value of T(rv) is equivalent to the value of rv before the initialization.<br/>
 *                         The new value of rv is unspecified.
 * </table>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/MoveConstructible
 * @see https://en.cppreference.com/w/cpp/concepts/MoveConstructible
 */
BOOST_concept(MoveConstructible, (T))
{
    BOOST_CONCEPT_USAGE(MoveConstructible)
    {
        T u = boost::declval<T>(); // boost::declval works even before c++11
        __detail::__unuse(u);
        __detail::__unuse(T(boost::declval<T>()));
    }
};

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_MOVE_CONSTRUCTIBLE_HPP__
