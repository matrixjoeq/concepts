/** @file */
#ifndef __STL_CONCEPT_SWAPPABLE_HPP__
#define __STL_CONCEPT_SWAPPABLE_HPP__

// for swap
#if __cplusplus < 201103L
#include <algorithm>
#else // __cplusplus < 201103L
#include <utility>
#endif // __cplusplus < 201103L

#include "concept/swappable_with.hpp"
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
 * @addtogroup library_wide_group Library-wide Requirements
 * @struct stl_concept::Swappable
 * @brief Specifies that lvalues of type T are swappable.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type T satisfies <i>Swappable</i> if<br/>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>a1, a2, b1 and b2, distinct objects of type T such that a1 is equal to a2 and b1 is equal to b2</li>
 * </ul>
 * <i>Swappable</i> is satisfied only if, after evaluating either swap(a1, b1) or swap(b1, a1),
 * a1 is equal to b2 and b1 is equal to a2.
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/Swappable
 * @see https://en.cppreference.com/w/cpp/concepts/Swappable
 */
#ifdef DOXYGEN_WORKING
template <typename T> struct Swappable : SwappableWith<T, T> {};
#else // DOXYGEN_WORKING
BOOST_concept(Swappable, (T)) : SwappableWith<T, T> {};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_SWAPPABLE_HPP__
