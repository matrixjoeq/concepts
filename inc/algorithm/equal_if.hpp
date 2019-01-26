/** @file */
#ifndef __STL_ALGORITHM_EQUAL_IF_HPP__
#define __STL_ALGORITHM_EQUAL_IF_HPP__

#include <algorithm>
#include <boost/concept/requires.hpp>
#include "concept/input_iterator.hpp"
#include "algorithm/detail/iterator_traits.hpp"
#include "algorithm/detail/binary_predicate_proxy.hpp"

namespace stl_algorithm {

/**
 * @brief Returns true if the range [first1, last1) is equal to the range [first2, first2 + (last1 - first1)),
 * and false otherwise.
 *
 * <p>
 * Two ranges are considered equal if they have the same number of elements and, for every iterator i in the range
 * [first1, last1), *i equals *(first2 + (i - first1)).<br/>
 * The given binary predicate p is used to determine if two elements are equal.
 * </p>
 * @tparam InputIt1, InputIt2 - must meet the requirements of <i>stl_concept::InputIterator</i>.
 * @tparam BinaryPredicate - must meet the requirements of <i>stl_concept::BinaryPredicate</i>.
 * @param first1, last1 - the first range of elements
 * @param first2 - the start point of second range of elements
 * @param p - binary predicate which returns ​true if the elements should be treated as equal.<br/>
 * The signature of the predicate function should be equivalent to the following:
 * ```
 * bool pred(const Type1 &a, const Type2 &b);
 * ```
 * The signature does not need to have const &, but the function must not modify the objects passed to it.<br/>
 * The types Type1 and Type2 must be such that objects of types InputIt1 and InputIt2 can be dereferenced and then
 * implicitly converted to Type1 and Type2 respectively. ​
 * @return If the elements in the two ranges are equal, returns true.  Otherwise returns false.
 * @see https://en.cppreference.com/w/cpp/algorithm/equal
 */
#ifdef DOXYGEN_WORKING
template <class InputIt1, class InputIt2, class BinaryPredicate>
inline bool equal_if(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p);
#else // DOXYGEN_WORKING
template <class InputIt1, class InputIt2, class BinaryPredicate>
    BOOST_CONCEPT_REQUIRES(
        // Requirements
        ((stl_concept::InputIterator<InputIt1>))
        ((stl_concept::InputIterator<InputIt2>))
        ((__detail::__BinaryPredicateProxy<BinaryPredicate, InputIt1, InputIt2>)),
        // Return
        (bool)
    )
inline equal_if(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
{
    return std::equal(first1, last1, first2, p);
}
#endif // DOXYGEN_WORKING

} // namespace stl_algorithm

#endif  // __STL_ALGORITHM_EQUAL_IF_HPP__
