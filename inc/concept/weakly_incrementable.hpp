/** @file */
#ifndef __STL_CONCEPT_WEAKLY_INCREMENTABLE_HPP__
#define __STL_CONCEPT_WEAKLY_INCREMENTABLE_HPP__

#include <boost/concept/usage.hpp>
#include <boost/concept/detail/concept_def.hpp>
#include "concept/detail/require_same_type.hpp"
#include "concept/detail/unuse.hpp"

#if (defined _MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4197) // topmost volatile ignored
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // object 'class' can never be instantiated - user-defined constructor required
#endif

namespace stl_concept {

/**
 * @addtogroup iterator_group Iterator Requirements
 * @class stl_concept::WeaklyIncrementable
 * @brief Specifies the requirements on a type that can be incremented (with the pre- and post-increment operators).
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The increment operations need not be equality-preserving, and the type need not be <i>EqualityComparable</i>.<br/>
 * Let i be an object of type It. i is said to be incrementable if it is in the domain of both pre- and post-increment.
 * <i>WeaklyIncrementable</i> is satisfied only if:
 * <ul style="list-style-type:disc">
 *   <li>The type It satisfies <i>CopyConstructible</i>, and</li>
 *   <li>The type It satisfies <i>CopyAssignable</i>, and</li>
 *   <li>The type It satisfies <i>Destructible</i>, and</li>
 *   <li>lvalues of type It satisfy <i>Swappable</i>, and</li>
 *   <li>std::iterator_traits<It> has member typedefs value_type, difference_type, reference, pointer, and
 *       iterator_category , and</li>
 * </ul>
 * </p>
 * @tparam It - iterator type to be checked
 * @see https://en.cppreference.com/w/cpp/experimental/ranges/iterator/WeaklyIncrementable
 */
#ifdef DOXYGEN_WORKING
template <typename It> struct WeaklyIncrementable {};
#else // DOXYGEN_WORKING
BOOST_concept(WeaklyIncrementable, (It))
{
    BOOST_CONCEPT_USAGE(WeaklyIncrementable)
    {
        // unlike WeaklyIncrementable concept in Ranges TS
        // member type difference_type in iterator is not required to be signed integral
        // because output iterators may define void as difference_type
        // this requirment is moved to InputIterator concept
        __detail::__require_same_type<decltype(++iter_), It&>();
        __detail::__unuse(iter_++);
    }

private:
    It iter_;
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept


#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_WEAKLY_INCREMENTABLE_HPP__
