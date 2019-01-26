/** @file */
#ifndef __STL_ALGORITHM_DETAIL_BINARY_FUNCTION_PROXY_HPP__
#define __STL_ALGORITHM_DETAIL_BINARY_FUNCTION_PROXY_HPP__

#include "concept/binary_function.hpp"
#include "algorithm/detail/function_object_adapter.hpp"
#include "algorithm/detail/iterator_traits.hpp"

namespace stl_algorithm {
namespace __detail {

/// @cond DEV
/**
 * @brief Proxy for using stl_concept::BinaryFunction
 *        with standard library algorithms applicable unary predicates and values.
 * @tparam BinaryFunction - binary function to be applied to algorithms
 * @tparam Iterator1, Iterator2 - iterators to be applied to algorithms
 */
template <typename BinaryFunction, typename Iterator1, typename Iterator2>
using __BinaryFunctionProxy = stl_concept::BinaryFunction<
    __FunctionObjectAdapter<BinaryFunction>,
    __iterator_value_t<Iterator1>,
    __iterator_value_t<Iterator2>>;
/// @endcond

} // namespace __detail
} // namespace stl_algorithm

#endif  // __STL_ALGORITHM_DETAIL_BINARY_FUNCTION_PROXY_HPP__
