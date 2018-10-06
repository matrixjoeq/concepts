
#ifndef __STL_CONCEPT_ITERATOR_HPP__
#define __STL_CONCEPT_ITERATOR_HPP__

#include "concept/copy_constructible.hpp"
#include "concept/copy_assignable.hpp"
#include "concept/destructible.hpp"
#include "concept/swappable.hpp"
#include <boost/iterator/iterator_traits.hpp>
#include <boost/concept/usage.hpp>
#include <boost/concept/detail/concept_def.hpp>
#include "concept/detail/require_expr_convertible_to.hpp"
#include "concept/detail/require_same_type.hpp"

#if (defined _MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // object 'class' can never be instantiated - user-defined constructor required
#endif

namespace stl_concept {

/**
 * @addtogroup iterator_group Iterator Requirements
 * @class stl_concept::Iterator
 * @brief Describes types that can be used to identify and traverse the elements of a container.
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
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/Iterator
 */
BOOST_concept(Iterator, (It))
    : CopyConstructible<It>
    , CopyAssignable<It>
    , Destructible<It>
    , Swappable<It>
{
private:
    typedef typename boost::iterator_value<It>::type value_type;
    typedef typename boost::iterator_difference<It>::type difference_type;
    typedef typename boost::iterator_reference<It>::type reference_type;
    typedef typename boost::iterator_pointer<It>::type pointer_type;
    typedef typename boost::iterator_category<It>::type iterator_category;

    It r_;

public:
    BOOST_CONCEPT_USAGE(Iterator)
    {
        __detail::__require_expr_convertible_to<value_type>(*r_);
        __detail::__require_same_type<decltype(++r_), It&>();
    }
};

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_ITERATOR_HPP__