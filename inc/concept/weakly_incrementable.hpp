/** @file */
#ifndef __STL_CONCEPT_WEAKLY_INCREMENTABLE_HPP__
#define __STL_CONCEPT_WEAKLY_INCREMENTABLE_HPP__

#include "concept/same.hpp"
#include <boost/concept/assert.hpp>
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
 * @addtogroup iterator_group Iterator Requirements
 * @struct WeaklyIncrementable
 * @brief Specifies the requirements on a type that can be incremented (with the pre- and post-increment operators).
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The increment operations need not be equality-preserving, and the type need not be <i>EqualityComparable</i>.<br/>
 * Let i be an object of type It. i is said to be incrementable if it is in the domain of both pre- and post-increment.
 * <i>WeaklyIncrementable</i> is satisfied only if:
 * <ul style="list-style-type:disc">
 *   <li>++i and i++ have the same domain</li>
 *   <li>If i is incrementable, then:</li>
 *     <ul style="list-style-type:disc">
 *       <li>++i and i++ both advance i to the next element, and</li>
 *       <li>++i refers to the same object as i</li>
 *     </ul>
 * </ul>
 * Unlike <i>WeaklyIncrementable</i> concept in Ranges TS, member type difference_type in iterator is not required to be
 * <i>SignedIntegral</i>.<br/>
 * Because output iterator may define void as difference_type, this requirment is moved to <i>InputIterator</i> concept.
 * <br/>
 * <i>Semiregular</i> concept requirement is also moved to <i>InputIterator</i> concept, because output iterator may not
 * be copyable or default constructible.
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
        BOOST_CONCEPT_ASSERT((Same<decltype(++iter_), It&>));
        __detail::__unuse(++iter_);
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
