/** @file */
#ifndef UnaryFunction__STL_ALGORITHM_FOR_EACH_HPP__
#define UnaryFunction__STL_ALGORITHM_FOR_EACH_HPP__

#include <algorithm>
#include <boost/type_traits/add_reference.hpp>
#include <boost/concept/requires.hpp>
#include "concept/input_iterator.hpp"
#include "concept/unary_function.hpp"
#include "algorithm/detail/function_object_adapter.hpp"
#include "algorithm/detail/iterator_traits.hpp"
#include "algorithm/detail/result_of.hpp"

namespace stl_algorithm {

/**
 * @brief Applies the given function object f to the result of dereferencing every iterator in the range [first, last), in order.
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
constexpr inline UnaryFunction for_each(InputIt first, InputIt last, UnaryFunction f);
#else // DOXYGEN_WORKING
template <class InputIt, class UnaryFunction>
    BOOST_CONCEPT_REQUIRES(
        // Requirements
        ((stl_concept::InputIterator<InputIt>))
        //((stl_concept::MoveConstructible<UnaryFunction>))
        ((stl_concept::UnaryFunction<
            __detail::__FunctionObjectAdapter<UnaryFunction>,
            __detail::__iterator_value_t<InputIt>
        >)),
        // Return
        (UnaryFunction)
    )
constexpr inline for_each(InputIt first, InputIt last, UnaryFunction f)
{
    return std::for_each(first, last, f);
}
#endif // DOXYGEN_WORKING

} // namespace stl_algorithm

#endif  // UnaryFunction__STL_ALGORITHM_FOR_EACH_HPP__
