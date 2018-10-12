/** @file */
#ifndef __STL_CONCEPT_EQUALITY_COMPARABLE_HPP__
#define __STL_CONCEPT_EQUALITY_COMPARABLE_HPP__

#include "concept/weakly_equality_comparable_with.hpp"
#include <boost/concept/detail/concept_def.hpp>

#if (defined _MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4197) // topmost volatile ignored
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // object 'class' can never be instantiated - user-defined constructor required
#endif

namespace stl_concept {

/**
 * @addtogroup library_wide_group Library-wide Requirements
 * @struct EqualityComparable
 * @brief Specifies that an instance of the type must work with == operator and the result should have standard semantics.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type T satisfies <i>EqualityComparable</i> if<br/>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>a, b, and c, expressions of type T or const T</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Return type                   <th>Requirements
 *   <tr><td>a == b    <td>implicitly convertible to bool<td>Establishes an equivalence relation, that is, it satisfies
 *                                                           the following properties:
 *                                                           <ul style="list-style-type:disc">
 *                                                             <li>For all values of a, a == a yields true.</li>
 *                                                             <li>If a == b, then b == a</li>
 *                                                             <li>If a == b and b == c, then a == c</li>
 *                                                           </ul>
 * </table>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/EqualityComparable
 * @see https://en.cppreference.com/w/cpp/concepts/EqualityComparable
 */
#ifdef DOXYGEN_WORKING
template <typename T> struct EqualityComparable : WeaklyEqualityComparableWith<T, T> {};
#else // DOXYGEN_WORKING
BOOST_concept(EqualityComparable, (T)) : WeaklyEqualityComparableWith<T, T> {};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_EQUALITY_COMPARABLE_HPP__
