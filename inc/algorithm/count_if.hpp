/** @file */
#ifndef __STL_ALGORITHM_COUNT_IF_HPP__
#define __STL_ALGORITHM_COUNT_IF_HPP__

#include <algorithm>
#include <iterator>
#include <boost/concept/requires.hpp>
#include "concept/input_iterator.hpp"
#include "algorithm/detail/unary_predicate_proxy.hpp"

namespace stl_algorithm {

/**
 * @brief Returns the number of elements in the range [first, last) for which predicate p returns true.
 * @tparam InputIt - must meet the requirements of <i>stl_concept::InputIterator</i>.
 * @tparam UnaryPredicate - must meet the requirements of <i>stl_concept::UnaryPredicate</i>.
 * @param first, last - the range of elements to examine
 * @param p - unary predicate which returns ​true for the required elements.<br/>
 * The signature of the predicate function should be equivalent to the following:
 * ```
 * bool pred(const Type &a);
 * ```
 * The signature does not need to have const &, but the function must not modify the objects passed to it.<br/>
 * The type Type must be such that an object of type InputIt can be dereferenced and then implicitly converted to Type.
 * @return number of elements satisfying the condition
 * @see https://en.cppreference.com/w/cpp/algorithm/count
 */
#ifdef DOXYGEN_WORKING
template <class InputIt, class UnaryPredicate>
constexpr inline auto count_if(InputIt first, InputIt last, UnaryPredicate p)
    -> decltype(typename std::iterator_traits<InputIt>::difference_type);
#else // DOXYGEN_WORKING
template <class InputIt, class UnaryPredicate>
    BOOST_CONCEPT_REQUIRES(
        // Requirements
        ((stl_concept::InputIterator<InputIt>))
        ((__detail::__UnaryPredicateProxy<UnaryPredicate, InputIt>)),
        // Return
        (__detail::__std_iterator_difference_t<InputIt>)
    )
constexpr inline count_if(InputIt first, InputIt last, UnaryPredicate p)
{
    return std::count_if(first, last, p);
}
#endif // DOXYGEN_WORKING

} // namespace stl_algorithm

#endif  // __STL_ALGORITHM_COUNT_IF_HPP__
