/** @file */
#ifndef __STL_CONCEPT_MUTABLE_BIDIRECTIONAL_ITERATOR_HPP__
#define __STL_CONCEPT_MUTABLE_BIDIRECTIONAL_ITERATOR_HPP__

#include "concept/bidirectional_iterator.hpp"
#include "concept/output_iterator.hpp"
#include <iterator>
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
 * @struct MutableBidirectionalIterator
 * @brief A <i>MutableBidirectionalIterator</i> is a <i>BidirectionalIterator</i> that additionally satisfies the
 * <i>OutputIterator</i> requirements.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type It satisfies <i>MutableBidirectionalIterator</i> if
 * <ul style="list-style-type:disc">
 *   <li>The type It satisfies <i>BidirectionalIterator</i></li>
 *   <li>The type It satisfies <i>OutputIterator</i></li>
 * </ul>
 * </p>
 * @tparam It - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/BidirectionalIterator
 */
#ifdef DOXYGEN_WORKING
template <typename It>
struct MutableBidirectionalIterator
    : BidirectionalIterator<It>
    , OutputIterator<It, typename std::iterator_traits<It>::value_type> {};
#else // DOXYGEN_WORKING
BOOST_concept(MutableBidirectionalIterator, (It))
    : BidirectionalIterator<It>
    , OutputIterator<It, __detail::__iterator_value_t<It>> {};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_MUTABLE_BIDIRECTIONAL_ITERATOR_HPP__
