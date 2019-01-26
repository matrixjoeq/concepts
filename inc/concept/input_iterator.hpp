/** @file */
#ifndef __STL_CONCEPT_INPUT_ITERATOR_HPP__
#define __STL_CONCEPT_INPUT_ITERATOR_HPP__

#include "concept/derived_from.hpp"
#include "concept/convertible_to.hpp"
#include "concept/signed_integral.hpp"
#include "concept/equality_comparable.hpp"
#include "concept/iterator.hpp"
#include <boost/concept/assert.hpp>
#include <boost/concept/usage.hpp>
#include <boost/concept/detail/concept_def.hpp>
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
 * @struct InputIterator
 * @brief Specifies that an instance of the type is an <i>Iterator</i> that can read from the pointed-to element.
 *
 * <p>
 * <i>InputIterator</i>s only guarantee validity for single pass algorithms: once an <i>InputIterator</i> i has been
 * incremented, all copies of its previous value may be invalidated.
 * </p><p>
 * <b>Requirements</b>
 * </p><p>
 * The type It satisfies <i>InputIterator</i> if<br/>
 * <ul style="list-style-type:disc">
 *   <li>The type It satisfies <i>Iterator</i>, and</li>
 *   <li>The type It satisfies <i>EqualityComparable</i>, and</li>
 * </ul>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>i and j, values of type It or const It</li>
 *   <li>reference, the type denoted by std::iterator_traits<It>::reference</li>
 *   <li>value_type, the type denoted by std::iterator_traits<It>::value_type</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Return                              <th>Equivalent expression <th>Precondition
 *   <tr><td>i != j    <td>contextually convertible to bool    <td>!(i == j)             <td>i, j is in the domain of ==
 *   <tr><td>*i        <td>reference, convertible to value_type<td>                      <td>i is dereferenceable
 *   <tr><td>i->m      <td>                                    <td>(*i).m                <td>i is dereferenceable
 *   <tr><td>++i       <td>It&                                 <td>                      <td>i is incrementable
 *   <tr><td>(void)++i <td>                                    <td>                      <td>i is incrementable
 *   <tr><td>*i++      <td>convertible to value_type           <td>value_type x = *i;<br/>++i;<br/>return x;<td>
 * </table>
 * </p>
 * @tparam It - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/InputIterator
 */
#ifdef DOXYGEN_WORKING
template <typename It>
struct InputIterator
    : EqualityComparable<It>
    , Iterator<It> {};
#else // DOXYGEN_WORKING
BOOST_concept(InputIterator, (It))
    : EqualityComparable<It>
    , Iterator<It>
{
    BOOST_CONCEPT_USAGE(InputIterator)
    {
        using __ValueType = __detail::__iterator_value_t<It>;
        using __DifferenceType = __detail::__iterator_difference_t<It>;
        using __CategoryType = __detail::__iterator_category_t<It>;

        BOOST_CONCEPT_ASSERT((SignedIntegral<__DifferenceType>));
        BOOST_CONCEPT_ASSERT((DerivedFrom<__CategoryType, std::input_iterator_tag>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(*iter_), __ValueType>));
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

#endif  // __STL_CONCEPT_INPUT_ITERATOR_HPP__
