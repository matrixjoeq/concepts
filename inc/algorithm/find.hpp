/** @file */
#ifndef __STL_ALGORITHM_FIND_HPP__
#define __STL_ALGORITHM_FIND_HPP__

#include <algorithm>
#include <iterator>
#include <boost/concept/requires.hpp>
#include "concept/equality_comparable_with.hpp"
#include "concept/input_iterator.hpp"
#include "algorithm/detail/iterator_traits.hpp"

namespace stl_algorithm {

/**
 * @brief Returns the first element in the range [first, last) that equals to value.
 * @tparam InputIt - must meet the requirements of <i>stl_concept::InputIterator</i>.
 * The dereference type of InputIt must meet the requirements of <i>stl_concept::EqualityComparableWith</i>.
 * @tparam T - must meet the requirements of <i>stl_concept::EqualityComparableWith</i>.
 * @param first, last - the range of elements to examine
 * @param value - the value to compare the elements to
 * @return Iterator to the first element satisfying the condition or last if no such element is found.
 * @see https://en.cppreference.com/w/cpp/algorithm/find
 */
#ifdef DOXYGEN_WORKING
template <class InputIt, class T>
constexpr inline InputIt find(InputIt first, InputIt last, const T& value);
#else // DOXYGEN_WORKING
template <class InputIt, class T>
    BOOST_CONCEPT_REQUIRES(
        // Requirements
        ((stl_concept::InputIterator<InputIt>))
        ((stl_concept::EqualityComparableWith<__detail::__iterator_value_t<InputIt>, T>)),
        // Return
        (InputIt)
    )
constexpr inline find(InputIt first, InputIt last, const T& value)
{
    return std::find(first, last, value);
}
#endif // DOXYGEN_WORKING

} // namespace stl_algorithm

#endif  // __STL_ALGORITHM_FIND_HPP__
