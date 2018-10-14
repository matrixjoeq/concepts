/** @file */
#ifndef __STL_CONCEPT_FORWARD_ITERATOR_HPP__
#define __STL_CONCEPT_FORWARD_ITERATOR_HPP__

#include "concept/convertible_to.hpp"
#include "concept/derived_from.hpp"
#include "concept/input_iterator.hpp"
#include "concept/incrementable.hpp"
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
 * @struct ForwardIterator
 * @brief A <i>ForwardIterator</i> is an <i>Iterator</i> that can read data from the pointed-to element.
 *
 * <p>
 * Unlike <i>InputIterator</i> and <i>OutputIterator</i>, it can be used in multipass algorithms.<br/>
 * <b>Requirements</b>
 * </p><p>
 * The type It satisfies <i>ForwardIterator</i> if
 * <ul style="list-style-type:disc">
 *   <li>The type It satisfies <i>InputIterator</i></li>
 *   <li>The type It satisfies <i>DefaultConstructible</i></li>
 *   <li>Objects of the type It provide multipass guarantee described below</li>
 *   <li>The type boost::iterator_reference<It>::type must be convertible to const T&, where T is the type denoted by
 *       boost::iterator_value<It>::type</li>
 *   <li></li>
 * </ul>
 * And, given
 * <ul style="list-style-type:disc">
 *   <li>i, dereferenceable iterator of type It</li>
 *   <li>reference, the type denoted by boost::iterator_reference<It>::type</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Return type<th>Equivalent expression
 *   <tr><td>i++       <td>It         <td>It ip = i;<br/>++i;<br/>return ip;
 *   <tr><td>*i++      <td>reference  <td>
 * </table>
 * </p>
 * @tparam It - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/ForwardIterator
 * @see https://en.cppreference.com/w/cpp/experimental/ranges/iterator/ForwardIterator
 */
#ifdef DOXYGEN_WORKING
template <typename It> struct ForwardIterator : InputIterator<It>, Incrementable<It> {};
#else // DOXYGEN_WORKING
BOOST_concept(ForwardIterator, (It)) : InputIterator<It>, Incrementable<It>
{
    BOOST_CONCEPT_USAGE(ForwardIterator)
    {
        using _ValueType = __detail::__iterator_value_t<It>;
        using _ReferenceType = __detail::__iterator_reference_t<It>;
        using _CategoryType = __detail::__iterator_category_t<It>;
        // According to C++ named requirements for ForwardIterator,
        // if It satisfies OutputIterator as well, _ReferenceType should be exactly _ValueType&,
        // otherwise, it should be exactly const _ValueType&.
        // However, it is not possible for boost concept to be applied to enable_if for static dispatch.
        // The only way to check if It satisfies OutputIterator is to use BOOST_CONCEPT_ASSERT macro,
        // which will cause compile failure if it does not meet the requirement.
        // So the compromising requirement for _ReferenceType is to check if it can be converted to const _ValueType&.
        // And add another concept called MutableForwardIterator, which set strict requirements on it.
        BOOST_CONCEPT_ASSERT((ConvertibleTo<_ReferenceType, const _ValueType&>));
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
