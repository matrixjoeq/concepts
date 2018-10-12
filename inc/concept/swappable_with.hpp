/** @file */
#ifndef __STL_CONCEPT_SWAPPABLE_WITH_HPP__
#define __STL_CONCEPT_SWAPPABLE_WITH_HPP__

// for swap
#if __cplusplus < 201103L
#include <algorithm>
#else // __cplusplus < 201103L
#include <utility>
#endif // __cplusplus < 201103L

#include "concept/referenceable.hpp"
#include <boost/type_traits/declval.hpp>
#include <boost/type_traits/remove_cv_ref.hpp>
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
 * @struct stl_concept::SwappableWith
 * @brief Specifies that lvalues of type T and type U are swappable.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type T and type U satisfies <i>SwappableWith</i> if<br/>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>t1 and t2, distinct equal objects of type std::remove_cvref_t<T></li>
 * </ul>
 * <i>SwappableWith</i> is satisfied only if, after evaluating either swap(a1, b1) or swap(b1, a1),
 * a1 is equal to b2 and b1 is equal to a2.
 * </p>
 * @tparam T - first type to be checked
 * @tparam U - second type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/Swappable
 * @see https://en.cppreference.com/w/cpp/concepts/Swappable
 */
#ifdef DOXYGEN_WORKING
template <typename T, typename U> struct SwappableWith {};
#else // DOXYGEN_WORKING
BOOST_concept(SwappableWith, (T)(U))
{
    BOOST_CONCEPT_USAGE(SwappableWith)
    {
        using std::swap;

        BOOST_CONCEPT_ASSERT((Referenceable<T>));
        BOOST_CONCEPT_ASSERT((Referenceable<U>));
        swap(boost::declval<T&>(), boost::declval<T&>());
        swap(boost::declval<U&>(), boost::declval<U&>());
        swap(boost::declval<T&>(), boost::declval<U&>());
        swap(boost::declval<U&>(), boost::declval<T&>());
    }
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_SWAPPABLE_WITH_HPP__
