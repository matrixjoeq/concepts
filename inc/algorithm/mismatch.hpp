/** @file */
#ifndef __STL_ALGORITHM_MISMATCH_HPP__
#define __STL_ALGORITHM_MISMATCH_HPP__

#include <algorithm>
#include <utility>
#include <boost/concept/requires.hpp>
#include "concept/equality_comparable_with.hpp"
#include "concept/input_iterator.hpp"
#include "algorithm/detail/iterator_traits.hpp"

namespace stl_algorithm {

/**
 * @brief Returns the first mismatching pair of elements from two ranges: one defined by [first1, last1) and another
 * defined by [first2, first2 + (last1 - first1)).
 * @tparam InputIt1, InputIt2 - must meet the requirements of <i>stl_concept::InputIterator</i>.
 * The dereferenced type of InputIt1 and Input2 must meet the requirements of <i>stl_concept::EqualityComparableWith</i>.
 * @param first1, last1 - the first range of elements
 * @param first2 - the start point of second range of elements
 * @return std::pair with iterators to the first two non-equal elements.<br/>
 * If no mismatches are found when the comparison reaches last1, the pair holds last1 and the corresponding iterator
 * from the second range.<br/>
 * The behavior is undefined if the second range is shorter than the first range.
 * @see https://en.cppreference.com/w/cpp/algorithm/mismatch
 */
#ifdef DOXYGEN_WORKING
template <class InputIt1, class InputIt2>
inline auto mismatch(InputIt1 first1, InputIt1 last1, InputIt2 first2) -> decltype(std::pair<InputIt1, InputIt2>);
#else // DOXYGEN_WORKING
template <class InputIt1, class InputIt2>
    BOOST_CONCEPT_REQUIRES(
        // Requirements
        ((stl_concept::InputIterator<InputIt1>))
        ((stl_concept::InputIterator<InputIt2>))
        ((stl_concept::EqualityComparableWith<__detail::__iterator_value_t<InputIt1>, __detail::__iterator_value_t<InputIt2>>)),
        // Return
        (std::pair<InputIt1, InputIt2>)
    )
inline mismatch(InputIt1 first1, InputIt1 last1, InputIt2 first2)
{
    return std::mismatch(first1, last1, first2);
}
#endif // DOXYGEN_WORKING

} // namespace stl_algorithm

#endif  // __STL_ALGORITHM_MISMATCH_HPP__
