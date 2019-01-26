/** @file */
#ifndef __STL_CONCEPT_BIDIRECTIONAL_ITERATOR_HPP__
#define __STL_CONCEPT_BIDIRECTIONAL_ITERATOR_HPP__

#include "concept/same.hpp"
#include "concept/convertible_to.hpp"
#include "concept/derived_from.hpp"
#include "concept/forward_iterator.hpp"
#include <boost/concept/assert.hpp>
#include <boost/concept/usage.hpp>
#include <boost/concept/detail/concept_def.hpp>
#include "concept/detail/iterator_traits.hpp"
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
 * @struct BidirectionalIterator
 * @brief A <i>BidirectionalIterator</i> is a <i>ForwardIterator</i> that can be moved in both directions (i.e.
 * incremented and decremented).
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type It satisfies <i>BidirectionalIterator</i> if
 * <ul style="list-style-type:disc">
 *   <li>The type It satisfies <i>ForwardIterator</i></li>
 * </ul>
 * And, given
 * <ul style="list-style-type:disc">
 *   <li>a and b, iterators of type It</li>
 *   <li>reference, the type denoted by boost::iterator_reference<It>::type</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Return type             <th>Equivalent expression                 <th>Notes
 *   <tr><td>--a       <td>It&                     <td>                                      <td>Preconditions:
 *                                                                                               <ul style="list-style-type:disc">
 *                                                                                                 <li>a is decrementable (there exists such b that a == ++b)</li>
 *                                                                                               </ul>
 *                                                                                               Postcondition:
 *                                                                                               <ul style="list-style-type:disc">
 *                                                                                                 <li>a is dereferenceable</li>
 *                                                                                                 <li>--(++a) == a</li>
 *                                                                                                 <li>If --a == --b then a == b</li>
 *                                                                                                 <li>&a == &--a</li>
 *                                                                                               </ul>
 *   <tr><td>a--       <td>convertible to const It&<td>It temp = a;<br/>--a;<br/>return temp;<td>
 *   <tr><td>*a--      <td>reference               <td>                                      <td>
 * </table>
 * </p>
 * @tparam It - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/BidirectionalIterator
 * @see https://en.cppreference.com/w/cpp/experimental/ranges/iterator/BidirectionalIterator
 */
#ifdef DOXYGEN_WORKING
template <typename It>
struct BidirectionalIterator
    : ForwardIterator<It> {};
#else // DOXYGEN_WORKING
BOOST_concept(BidirectionalIterator, (It))
    : ForwardIterator<It>
{
    BOOST_CONCEPT_USAGE(BidirectionalIterator)
    {
        using __ReferenceType = __detail::__iterator_reference_t<It>;
        using __CategoryType = __detail::__iterator_category_t<It>;
        BOOST_CONCEPT_ASSERT((DerivedFrom<__CategoryType, std::bidirectional_iterator_tag>));
        BOOST_CONCEPT_ASSERT((Same<decltype(--iter_), It&>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(iter_--), const It&>));
        BOOST_CONCEPT_ASSERT((Same<decltype(*iter_--), __ReferenceType>));
        __detail::__unuse(--iter_);
        __detail::__unuse(iter_--);
        __detail::__unuse(*iter_--);
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

#endif  // __STL_CONCEPT_BIDIRECTIONAL_ITERATOR_HPP__
