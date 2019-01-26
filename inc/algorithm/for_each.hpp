/** @file */
#ifndef UnaryFunction__STL_ALGORITHM_FOR_EACH_HPP__
#define UnaryFunction__STL_ALGORITHM_FOR_EACH_HPP__

#include <algorithm>
#include <boost/concept/requires.hpp>
#include "concept/input_iterator.hpp"
#include "concept/move_constructible.hpp"
#include "algorithm/detail/unary_function_proxy.hpp"

namespace stl_algorithm {

/**
 * @brief Applies the given function object f to the result of dereferencing every iterator in the range [first, last),
 * in order.
 * @tparam InputIt - must meet the requirements of <i>stl_concept::InputIterator</i>.
 * @tparam UnaryFunction - must meet the requirements of <i>stl_concept::UnaryFunction</i>.
 * @param first, last - the range of elements to examine
 * @param f - function object, to be applied to the result of dereferencing every iterator in the range [first, last)<br/>
 * The signature of the function should be equivalent to the following:
 * ```
 * void fun(const Type &a);
 * ```
 * The signature does not need to have const &.<br/>
 * The type Type must be such that an object of type InputIt can be dereferenced and then implicitly converted to Type.
 * @return f (until C++11), std::move(f) (since C++11)
 * @see https://en.cppreference.com/w/cpp/algorithm/for_each
 */
#ifdef DOXYGEN_WORKING
template <class InputIt, class UnaryFunction>
inline UnaryFunction for_each(InputIt first, InputIt last, UnaryFunction f);
#else // DOXYGEN_WORKING
template <class InputIt, class UnaryFunction>
    BOOST_CONCEPT_REQUIRES(
        // Requirements
        ((stl_concept::InputIterator<InputIt>))
        // TODO: UnaryFunction should be move constructible, need to fix MoveConstructible with lambda types first.
        //((stl_concept::MoveConstructible<UnaryFunction>))
        ((__detail::__UnaryFunctionProxy<UnaryFunction, InputIt>)),
        // Return
        (UnaryFunction)
    )
inline for_each(InputIt first, InputIt last, UnaryFunction f)
{
    return std::for_each(first, last, f);
}
#endif // DOXYGEN_WORKING

} // namespace stl_algorithm

#endif  // UnaryFunction__STL_ALGORITHM_FOR_EACH_HPP__
