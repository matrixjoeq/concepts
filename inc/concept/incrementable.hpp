/** @file */
#ifndef __STL_CONCEPT_INCREMENTABLE_HPP__
#define __STL_CONCEPT_INCREMENTABLE_HPP__

#include "concept/same.hpp"
#include "concept/weakly_incrementable.hpp"
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
 * @struct Incrementable
 * @brief Specifies the requirements on a type that can be incremented (with the pre- and post-increment operators).
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The increment operations (including those required by <i>WeaklyIncrementable</i>) are required to be
 * equality-preserving, and the type is required to be <i>EqualityComparable</i>.<br/>
 * Let a and b be incrementable objects of type I. <i>Incrementable</i> is satisfied only if:
 * <ul style="list-style-type:disc">
 *   <li>If bool(a == b) then bool(a++ == b)</li>
 *   <li>If bool(a == b) then bool(void(a++), a) == ++b)</li>
 * </ul>
 * Unlike <i>Incrementable</i> concept in Ranges TS, post-increment operator return type is It in C++ named requirements,
 * not It&&.
 * </p>
 * @tparam It - iterator type to be checked
 * @see https://en.cppreference.com/w/cpp/experimental/ranges/iterator/Incrementable
 */
#ifdef DOXYGEN_WORKING
template <typename It> struct Incrementable : WeaklyIncrementable<It> {};
#else // DOXYGEN_WORKING
BOOST_concept(Incrementable, (It)) : WeaklyIncrementable<It>
{
    BOOST_CONCEPT_USAGE(Incrementable)
    {
        BOOST_CONCEPT_ASSERT((Same<decltype(iter_++), It>));
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

#endif  // __STL_CONCEPT_INCREMENTABLE_HPP__
