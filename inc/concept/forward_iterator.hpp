/** @file */
#ifndef __STL_CONCEPT_FORWARD_ITERATOR_HPP__
#define __STL_CONCEPT_FORWARD_ITERATOR_HPP__

#include "concept/derived_from.hpp"
#include "concept/input_iterator.hpp"
#include "concept/incrementable.hpp"
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
 * @struct stl_concept::ForwardIterator
 * @brief Refines <i>InputIterator</i> by adding equality comparison and the multi-pass guarantee.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * Let a and b be two deferenceable iterators of type I. <i>ForwardIterator</i> is satisfied only if:
 * <ul style="list-style-type:disc">
 *   <li>a == b implies ++a == ++b; and</li>
 *   <li>The expression ([](X x){++x;}(a), *a) is equivalent to *a, i.e., incrementing a copy of a has no effect on the
 *       result of dereferencing a.</li>
 * </ul>
 * This is known as the multi-pass guarantee.
 * </p>
 * @tparam It - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/ForwardIterator
 */
#ifdef DOXYGEN_WORKING
template <typename It> struct ForwardIterator : InputIterator<It>, Incrementable<It> {};
#else // DOXYGEN_WORKING
BOOST_concept(ForwardIterator, (It)) : InputIterator<It>, Incrementable<It>
{
    BOOST_CONCEPT_USAGE(ForwardIterator)
    {
        using _CategoryType = typename boost::iterator_category<It>::type;
        BOOST_CONCEPT_ASSERT((DerivedFrom<_CategoryType, std::forward_iterator_tag>));
    }
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_FORWARD_ITERATOR_HPP__
