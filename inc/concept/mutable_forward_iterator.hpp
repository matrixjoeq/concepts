/** @file */
#ifndef __STL_CONCEPT_MUTABLE_FORWARD_ITERATOR_HPP__
#define __STL_CONCEPT_MUTABLE_FORWARD_ITERATOR_HPP__

#include "concept/same.hpp"
#include "concept/derived_from.hpp"
#include "concept/forward_iterator.hpp"
#include "concept/output_iterator.hpp"
#include <iterator>
#include <boost/iterator/iterator_traits.hpp>
#include <boost/concept/assert.hpp>
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
 * @addtogroup iterator_group Iterator Requirements
 * @struct MutableForwardIterator
 * @brief A <i>MutableForwardIterator</i> is a <i>ForwardIterator</i> that additionally satisfies the
 * <i>OutputIterator</i> requirements.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type It satisfies <i>MutableForwardIterator</i> if
 * <ul style="list-style-type:disc">
 *   <li>The type It satisfies <i>ForwardIterator</i></li>
 *   <li>The type It satisfies <i>OutputIterator</i></li>
 *   <li>The type boost::iterator_reference<It>::type must be exactly T&, where T is the type denoted by
 *       boost::iterator_value<It>::type</li>
 *   <li></li>
 * </ul>
 * </p>
 * @tparam It - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/ForwardIterator
 */
#ifdef DOXYGEN_WORKING
template <typename It> struct MutableForwardIterator
    : ForwardIterator<It>, OutputIterator<It, typename boost::iterator_value<It>::type> {};
#else // DOXYGEN_WORKING
BOOST_concept(MutableForwardIterator, (It))
    : ForwardIterator<It>, OutputIterator<It, typename boost::iterator_value<It>::type>
{
    BOOST_CONCEPT_USAGE(MutableForwardIterator)
    {
        using _ValueType = typename boost::iterator_value<It>::type;
        using _ReferenceType = typename boost::iterator_reference<It>::type;
        BOOST_CONCEPT_ASSERT((Same<_ReferenceType, _ValueType&>));
    }
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_MUTABLE_FORWARD_ITERATOR_HPP__
