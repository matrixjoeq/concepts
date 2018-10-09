/** @file */
#ifndef __STL_ALGORITHM_DETAIL_UNARY_FUNCTION_PROXY_HPP__
#define __STL_ALGORITHM_DETAIL_UNARY_FUNCTION_PROXY_HPP__

#include "concept/unary_function.hpp"
#include "algorithm/detail/function_object_adapter.hpp"
#include "algorithm/detail/iterator_traits.hpp"

namespace stl_algorithm {
namespace __detail {

/// @cond DEV
/**
 * @brief Proxy for using stl_concept::UnaryFunction with standard library algorithms applicable unary predicates and
 * values.
 * @tparam UnaryFunction - unary function to be applied to algorithms
 * @tparam Iterator - iterator to be applied to algorithms
 */
template <typename UnaryFunction, typename Iterator>
using __UnaryFunctionProxy = stl_concept::UnaryFunction<
    __FunctionObjectAdapter<UnaryFunction>,
    __iterator_value_t<Iterator>>;
/// @endcond

} // namespace __detail
} // namespace stl_algorithm

#endif  // __STL_ALGORITHM_DETAIL_UNARY_FUNCTION_PROXY_HPP__
