/** @file */
#ifndef __STL_ALGORITHM_DETAIL_RESULT_OF_HPP__
#define __STL_ALGORITHM_DETAIL_RESULT_OF_HPP__

#include <type_traits>

namespace stl_algorithm {
namespace __detail {

/// @cond DEV
/**
 * @brief Alias of std::result_of<>::type
 * @tparam F - Callable object type
 * @tparam Args - Variadic argument types
 * @see https://en.cppreference.com/w/cpp/types/result_of
 */
template <class F, class... Args>
using __result_of_t = typename std::result_of<F(Args...)>::type;
/// @endcond

} // namespace __detail
} // namespace stl_algorithm

#endif  // __STL_ALGORITHM_DETAIL_RESULT_OF_HPP__
