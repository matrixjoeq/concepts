/** @file */
#ifndef __STL_ALGORITHM_FIND_IF_NOT_HPP__
#define __STL_ALGORITHM_FIND_IF_NOT_HPP__

#include <algorithm>
#include <iterator>
#include <boost/concept/requires.hpp>
#include "concept/input_iterator.hpp"
#include "algorithm/detail/unary_predicate_proxy.hpp"

namespace stl_algorithm {

/**
 * @brief Returns the first element in the range [first, last) that predicate p returns false.
 * @tparam InputIt - must meet the requirements of <i>stl_concept::InputIterator</i>.
 * @tparam UnaryPredicate - must meet the requirements of <i>stl_concept::UnaryPredicate</i>.
 * @param first, last - the range of elements to examine
 * @param p - unary predicate which returns false for the required element.<br/>
 * The signature of the predicate function should be equivalent to the following:
 * ```
 * bool pred(const Type &a);
 * ```
 * The signature does not need to have const &, but the function must not modify the objects passed to it.<br/>
 * The type Type must be such that an object of type InputIt can be dereferenced and then implicitly converted to Type.
 * @return Iterator to the first element satisfying the condition or last if no such element is found.
 * @see https://en.cppreference.com/w/cpp/algorithm/find
 */
#ifdef DOXYGEN_WORKING
template <class InputIt, class UnaryPredicate>
inline InputIt find_if_not(InputIt first, InputIt last, UnaryPredicate p);
#else // DOXYGEN_WORKING
template <class InputIt, class UnaryPredicate>
    BOOST_CONCEPT_REQUIRES(
        // Requirements
        ((stl_concept::InputIterator<InputIt>))
        ((__detail::__UnaryPredicateProxy<UnaryPredicate, InputIt>)),
        // Return
        (InputIt)
    )
inline find_if_not(InputIt first, InputIt last, UnaryPredicate p)
{
    return std::find_if_not(first, last, p);
}
#endif // DOXYGEN_WORKING

} // namespace stl_algorithm

#endif  // __STL_ALGORITHM_FIND_IF_NOT_HPP__
