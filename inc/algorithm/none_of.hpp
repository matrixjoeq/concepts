/** @file */
#ifndef __STL_ALGORITHM_NONE_OF_HPP__
#define __STL_ALGORITHM_NONE_OF_HPP__

#include <algorithm>
#include <boost/concept/requires.hpp>
#include "concept/input_iterator.hpp"
#include "algorithm/detail/unary_predicate_proxy.hpp"

namespace stl_algorithm {

/**
 * @brief Checks if unary predicate p returns true for no elements in the range [first, last).
 * @tparam InputIt - must meet the requirements of <i>stl_concept::InputIterator</i>.
 * @tparam UnaryPredicate - must meet the requirements of <i>stl_concept::UnaryPredicate</i>.
 * @param first, last - the range of elements to examine
 * @param p - unary predicate<br/>
 * The signature of the predicate function should be equivalent to the following:
 * ```
 * bool pred(const Type &a);
 * ```
 * The signature does not need to have const &, but the function must not modify the objects passed to it.<br/>
 * The type Type must be such that an object of type InputIt can be dereferenced and then implicitly converted to Type.
 * @return true if unary predicate returns true for all elements in the range, false otherwise. Returns true if the
 * range is empty.
 * @see https://en.cppreference.com/w/cpp/algorithm/all_any_none_of
 */
#ifdef DOXYGEN_WORKING
template <class InputIt, class UnaryPredicate>
constexpr inline bool none_of(InputIt first, InputIt last, UnaryPredicate p);
#else // DOXYGEN_WORKING
template <class InputIt, class UnaryPredicate>
    BOOST_CONCEPT_REQUIRES(
        // Requirements
        ((stl_concept::InputIterator<InputIt>))
        ((__detail::__UnaryPredicateProxy<UnaryPredicate, InputIt>)),
        // Return
        (bool)
    )
constexpr inline none_of(InputIt first, InputIt last, UnaryPredicate p)
{
    return std::none_of(first, last, p);
}
#endif // DOXYGEN_WORKING

} // namespace stl_algorithm

#endif  // __STL_ALGORITHM_NONE_OF_HPP__
