/** @file */
#ifndef __STL_CONCEPT_DESTRUCTIBLE_HPP__
#define __STL_CONCEPT_DESTRUCTIBLE_HPP__

#include <boost/concept/usage.hpp>
#include <boost/concept/detail/concept_def.hpp>

#if (defined _MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4197) // topmost volatile ignored
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // object 'class' can never be instantiated - user-defined constructor required
#endif

namespace stl_concept {

/**
 * @addtogroup core_group Core Language Concepts
 * @struct Destructible
 * @brief Specifies that an instance of the type can be destructed.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type T satisfies <i>Destructible</i> if<br/>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>u, a expression of type T</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Post-conditions
 *   <tr><td>u.~T()    <td>All resources owned by u are reclaimed, no exceptions are thrown.
 * </table>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/Destructible
 * @see https://en.cppreference.com/w/cpp/concepts/Destructible
 */
#ifdef DOXYGEN_WORKING
template <typename T> struct Destructible {};
#else // DOXYGEN_WORKING
BOOST_concept(Destructible, (T))
{
    BOOST_CONCEPT_USAGE(Destructible)
    {
        // ~T() is called in ~Destructible()
    }
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_DESTRUCTIBLE_HPP__
