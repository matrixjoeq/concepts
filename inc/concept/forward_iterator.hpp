/** @file */
#ifndef __STL_CONCEPT_FORWARD_ITERATOR_HPP__
#define __STL_CONCEPT_FORWARD_ITERATOR_HPP__

#include "concept/convertible_to.hpp"
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
 * @struct ForwardIterator
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
 * @see https://en.cppreference.com/w/cpp/experimental/ranges/iterator/ForwardIterator
 */
#ifdef DOXYGEN_WORKING
template <typename It> struct ForwardIterator : InputIterator<It>, Incrementable<It> {};
#else // DOXYGEN_WORKING
BOOST_concept(ForwardIterator, (It)) : InputIterator<It>, Incrementable<It>
{
    BOOST_CONCEPT_USAGE(ForwardIterator)
    {
        using _ValueType = typename boost::iterator_value<It>::type;
        using _ReferenceType = typename boost::iterator_reference<It>::type;
        using _CategoryType = typename boost::iterator_category<It>::type;
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
