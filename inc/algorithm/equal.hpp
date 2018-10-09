/** @file */
#ifndef __STL_ALGORITHM_EQUAL_HPP__
#define __STL_ALGORITHM_EQUAL_HPP__

#include <algorithm>
#include <boost/concept/requires.hpp>
#include "concept/equality_comparable_with.hpp"
#include "concept/input_iterator.hpp"
#include "algorithm/detail/iterator_traits.hpp"

namespace stl_algorithm {

/**
 * @brief Returns true if the range [first1, last1) is equal to the range [first2, first2 + (last1 - first1)),
 * and false otherwise.
 *
 * <p>
 * Two ranges are considered equal if they have the same number of elements and, for every iterator i in the range
 * [first1, last1), *i equals *(first2 + (i - first1)).<br/>
 * Operator== is used to determine if two elements are equal.
 * </p>
 * @tparam InputIt1, InputIt2 - must meet the requirements of <i>stl_concept::InputIterator</i>.
 * The dereferenced type of InputIt1 and Input2 must meet the requirements of <i>stl_concept::EqualityComparableWith</i>.
 * @param first1, last1 - the first range of elements
 * @param first2 - the start point of second range of elements
 * @return If the elements in the two ranges are equal, returns true.  Otherwise returns false.
 * @see https://en.cppreference.com/w/cpp/algorithm/equal
 */
#ifdef DOXYGEN_WORKING
template <class InputIt1, class InputIt2>
constexpr inline bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2);
#else // DOXYGEN_WORKING
template <class InputIt1, class InputIt2>
    BOOST_CONCEPT_REQUIRES(
        // Requirements
        ((stl_concept::InputIterator<InputIt1>))
        ((stl_concept::InputIterator<InputIt2>))
        ((stl_concept::EqualityComparableWith<__detail::__iterator_value_t<InputIt1>, __detail::__iterator_value_t<InputIt2>>)),
        // Return
        (bool)
    )
constexpr inline equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
{
    return std::equal(first1, last1, first2);
}
#endif // DOXYGEN_WORKING

} // namespace stl_algorithm

#endif  // __STL_ALGORITHM_EQUAL_HPP__
