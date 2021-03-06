/** @file */
#ifndef __STL_CONCEPT_ITERATOR_HPP__
#define __STL_CONCEPT_ITERATOR_HPP__

#include "concept/copy_constructible.hpp"
#include "concept/copy_assignable.hpp"
#include "concept/destructible.hpp"
#include "concept/swappable.hpp"
#include "concept/dereferenceable.hpp"
#include "concept/weakly_incrementable.hpp"
#include <boost/concept/usage.hpp>
#include <boost/concept/detail/concept_def.hpp>
#include "concept/detail/unuse.hpp"
#include "concept/detail/iterator_traits.hpp"

#if (defined _MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4197) // topmost volatile ignored
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // object 'class' can never be instantiated - user-defined constructor required
#endif

namespace stl_concept {

/**
 * @addtogroup iterator_group Iterator Requirements
 * @struct Iterator
 * @brief Specifies that an instance of the type can be used to identify and traverse the elements of a container.
 *
 * <p>
 * <i>Iterator</i> is the base set of requirements used by other iterator types: <i>InputIterator</i>,
 * <i>OutputIterator</i>, <i>ForwardIterator</i>, <i>BidirectionalIterator</i>, and <i>RandomAccessIterator</i>.
 * <i>Iterator</i>s can be thought of as an abstraction of pointers.
 * </p><p>
 * <b>Requirements</b>
 * </p><p>
 * The type It satisfies <i>Iterator</i> if<br/>
 * <ul style="list-style-type:disc">
 *   <li>The type It satisfies <i>CopyConstructible</i>, and</li>
 *   <li>The type It satisfies <i>CopyAssignable</i>, and</li>
 *   <li>The type It satisfies <i>Destructible</i>, and</li>
 *   <li>lvalues of type It satisfy <i>Swappable</i>, and</li>
 *   <li>std::iterator_traits<It> has member typedefs value_type, difference_type, reference, pointer, and
 *       iterator_category , and</li>
 * </ul>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>r, an lvalue of type It.</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Return Type<th>Precondition
 *   <tr><td>*r        <td>unspecified<td>r is dereferenceable
 *   <tr><td>++r       <td>It&        <td>r is incrementable (the behavior of the expression ++r is defined)
 * </table>
 * </p>
 * @tparam It - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/Iterator
 */
#ifdef DOXYGEN_WORKING
template <typename It>
struct Iterator
    : CopyConstructible<It>
    , CopyAssignable<It>
    , Destructible<It>
    , Swappable<It>
    , Dereferenceable<It>
    , WeaklyIncrementable<It> {};
#else // DOXYGEN_WORKING
BOOST_concept(Iterator, (It))
    : CopyConstructible<It>
    , CopyAssignable<It>
    , Destructible<It>
    , Swappable<It>
    , Dereferenceable<It>
    , WeaklyIncrementable<It>
{
private:
    using __ValueType = __detail::__iterator_value_t<It>;
    using __DifferenceType = __detail::__iterator_difference_t<It>;
    using __ReferenceType = __detail::__iterator_reference_t<It>;
    using __PointerType = __detail::__iterator_pointer_t<It>;
    using __CategoryType = __detail::__iterator_category_t<It>;
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_ITERATOR_HPP__
