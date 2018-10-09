/** @file */
#ifndef __STL_ALGORITHM_DETAIL_UNARY_PREDICATE_PROXY_HPP__
#define __STL_ALGORITHM_DETAIL_UNARY_PREDICATE_PROXY_HPP__

#include "concept/unary_predicate.hpp"
#include "algorithm/detail/function_object_adapter.hpp"
#include "algorithm/detail/iterator_traits.hpp"

namespace stl_algorithm {
namespace __detail {

/// @cond DEV
/**
 * @brief Proxy for using stl_concept::UnaryPredicate with standard library algorithms applicable unary predicates and
 * values.
 * @tparam UnaryPredicate - unary predicate to be applied to algorithms
 * @tparam Iterator - iterator to be applied to algorithms
 */
template <typename UnaryPredicate, typename Iterator>
using __UnaryPredicateProxy = stl_concept::UnaryPredicate<
    __FunctionObjectAdapter<UnaryPredicate>,
    __iterator_value_t<Iterator>>;
/// @endcond

} // namespace __detail
} // namespace stl_algorithm

#endif  // __STL_ALGORITHM_DETAIL_UNARY_PREDICATE_PROXY_HPP__
