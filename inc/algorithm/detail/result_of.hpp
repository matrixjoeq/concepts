
#ifndef __STL_ALGORITHM_DETAIL_RESULT_OF_HPP__
#define __STL_ALGORITHM_DETAIL_RESULT_OF_HPP__

#include <type_traits>

namespace stl_algorithm {
namespace __detail {

template <class F, class... Args>
using __result_of_t = typename std::result_of<F(Args...)>::type;

} // namespace __detail
} // namespace stl_algorithm

#endif  // __STL_ALGORITHM_DETAIL_RESULT_OF_HPP__
