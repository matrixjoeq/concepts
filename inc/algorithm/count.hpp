/** @file */
#ifndef __STL_ALGORITHM_COUNT_HPP__
#define __STL_ALGORITHM_COUNT_HPP__

#include <algorithm>
#include <iterator>
#include <boost/concept/requires.hpp>
#include "concept/equality_comparable_with.hpp"
#include "concept/input_iterator.hpp"
#include "algorithm/detail/iterator_traits.hpp"

namespace stl_algorithm {

/**
 * @brief Returns the number of elements in the range [first, last) that are equal to value.
 * @tparam InputIt - must meet the requirements of <i>stl_concept::InputIterator</i>.
 * The dereference type of InputIt must meet the requirements of <i>stl_concept::EqualityComparableWith</i>.
 * @tparam T - must meet the requirements of <i>stl_concept::EqualityComparableWith</i>.
 * @param first, last - the range of elements to examine
 * @param value - the value to search for
 * @return number of elements satisfying the condition
 * @see https://en.cppreference.com/w/cpp/algorithm/count
 */
#ifdef DOXYGEN_WORKING
template <class InputIt, class T>
constexpr inline auto count(InputIt first, InputIt last, const T& value)
    -> decltype(typename std::iterator_traits<InputIt>::difference_type);
#else // DOXYGEN_WORKING
template <class InputIt, class T>
    BOOST_CONCEPT_REQUIRES(
        // Requirements
        ((stl_concept::InputIterator<InputIt>))
        ((stl_concept::EqualityComparableWith<__detail::__iterator_value_t<InputIt>, T>)),
        // Return
        (__detail::__std_iterator_difference_t<InputIt>)
    )
constexpr inline count(InputIt first, InputIt last, const T& value)
{
    return std::count(first, last, value);
}
#endif // DOXYGEN_WORKING

} // namespace stl_algorithm

#endif  // __STL_ALGORITHM_COUNT_HPP__
