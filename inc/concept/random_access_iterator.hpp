/** @file */
#ifndef __STL_CONCEPT_RANDOM_ACCESS_ITERATOR_HPP__
#define __STL_CONCEPT_RANDOM_ACCESS_ITERATOR_HPP__

#include "concept/same.hpp"
#include "concept/convertible_to.hpp"
#include "concept/derived_from.hpp"
#include "concept/bidirectional_iterator.hpp"
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
 * @struct RandomAccessIterator
 * @brief A <i>RandomAccessIterator</i> is a <i>BidirectionalIterator</i> that can be moved to point to any element in
 * constant time.
 *
 * <p>
 * A pointer to an element of an array satisfies all requirements of <i>RandomAccessIterator</i>.<br/>
 * <b>Requirements</b>
 * </p><p>
 * The type It satisfies <i>RandomAccessIterator</i> if
 * <ul style="list-style-type:disc">
 *   <li>The type It satisfies <i>BidirectionalIterator</i></li>
 * </ul>
 * And, given
 * <ul style="list-style-type:disc">
 *   <li>value_type, the type denoted by boost::iterator_value<It>::type</li>
 *   <li>difference_type, the type denoted by boost::iterator_difference<It>::type</li>
 *   <li>reference, the type denoted by boost::iterator_reference<It>::type</li>
 *   <li>i, a, b, objects of type It or const It</li>
 *   <li>r, a value of type It&</li>
 *   <li>n, an integer of type difference_type</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression     <th>Return type
 *   <tr><td>r += n         <td>It&
 *   <tr><td>a + n<br/>n + a<td>It
 *   <tr><td>r -= n         <td>It&
 *   <tr><td>i - n          <td>It
 *   <tr><td>b - a          <td>difference_type
 *   <tr><td>i[n]           <td>convertible to reference
 *   <tr><td>a < b          <td>contextually convertible to bool
 *   <tr><td>a > b          <td>contextually convertible to bool
 *   <tr><td>a >= b         <td>contextually convertible to bool
 *   <tr><td>a <= b         <td>contextually convertible to bool
 * </table>
 * </p>
 * @tparam It - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator
 * @see https://en.cppreference.com/w/cpp/experimental/ranges/iterator/RandomAccessIterator
 */
#ifdef DOXYGEN_WORKING
template <typename It>
struct RandomAccessIterator
    : BidirectionalIterator<It> {};
#else // DOXYGEN_WORKING
BOOST_concept(RandomAccessIterator, (It))
    : BidirectionalIterator<It>
{
    BOOST_CONCEPT_USAGE(RandomAccessIterator)
    {
        It& r = iter_a_;
        __DifferenceType n = iter_b_ - iter_a_;
        BOOST_CONCEPT_ASSERT((DerivedFrom<__CategoryType, std::random_access_iterator_tag>));
        BOOST_CONCEPT_ASSERT((Same<decltype(r += n), It&>));
        BOOST_CONCEPT_ASSERT((Same<decltype(iter_a_ + n), It>));
        BOOST_CONCEPT_ASSERT((Same<decltype(n + iter_a_), It>));
        BOOST_CONCEPT_ASSERT((Same<decltype(r -= n), It&>));
        BOOST_CONCEPT_ASSERT((Same<decltype(iter_a_ - n), It>));
        BOOST_CONCEPT_ASSERT((Same<decltype(iter_b_ - iter_a_), __DifferenceType>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(iter_a_[n]), __ReferenceType>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(iter_a_ < iter_b_), bool>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(iter_a_ > iter_b_), bool>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(iter_a_ <= iter_b_), bool>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(iter_a_ >= iter_b_), bool>));
        __detail::__unuse(r += n);
        __detail::__unuse(iter_a_ + n);
        __detail::__unuse(n + iter_a_);
        __detail::__unuse(r -= n);
        __detail::__unuse(iter_a_ - n);
        __detail::__unuse(iter_b_ - iter_a_);
        __detail::__unuse(iter_a_[n]);
        __detail::__unuse(iter_a_ < iter_b_);
        __detail::__unuse(iter_a_ > iter_b_);
        __detail::__unuse(iter_a_ <= iter_b_);
        __detail::__unuse(iter_a_ >= iter_b_);
    }

private:
    using __ValueType = __detail::__iterator_value_t<It>;
    using __ReferenceType = __detail::__iterator_reference_t<It>;
    using __DifferenceType = __detail::__iterator_difference_t<It>;
    using __CategoryType = __detail::__iterator_category_t<It>;

    void const_constraints(const It& x, const It& y)
    {
        __DifferenceType n = x - y;
        BOOST_CONCEPT_ASSERT((Same<decltype(x + n), It>));
        BOOST_CONCEPT_ASSERT((Same<decltype(n + x), It>));
        BOOST_CONCEPT_ASSERT((Same<decltype(x - n), It>));
        BOOST_CONCEPT_ASSERT((Same<decltype(y - x), __DifferenceType>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(x[n]), __ReferenceType>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(x < y), bool>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(x > y), bool>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(x <= y), bool>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(x >= y), bool>));
        __detail::__unuse(x + n);
        __detail::__unuse(n + x);
        __detail::__unuse(x - n);
        __detail::__unuse(y - x);
        __detail::__unuse(x[n]);
        __detail::__unuse(x < y);
        __detail::__unuse(x > y);
        __detail::__unuse(x <= y);
        __detail::__unuse(x >= y);
    }

    It iter_a_;
    It iter_b_;
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_RANDOM_ACCESS_ITERATOR_HPP__
