/** @file */
#ifndef __STL_ALGORITHM_DETAIL_FUNCTION_OBJECT_ADAPTER_HPP__
#define __STL_ALGORITHM_DETAIL_FUNCTION_OBJECT_ADAPTER_HPP__

#include <type_traits>

namespace stl_algorithm {
namespace __detail {
namespace {

template <class T>
using __FunctionObjectAdapterImpl =
    typename std::conditional<
        std::is_function<T>::value,
        typename std::decay<T>::type,
        T
    >::type;

} // namespace

/// @cond DEV
/**
 * @brief Type adapter for function objects.
 *
 * <p>
 * Adapter type T to meet the requirement of <i>stl_concept::FunctionObject</i>.<br/>
 * Because references are not object, it removes reference first.<br/>
 * Then decay it to function pointer if reference removed type is function.
 * </p>
 * @tparam T - type to be adapted
 * @see https://en.cppreference.com/w/cpp/named_req/FunctionObject
 */
template <class T>
using __FunctionObjectAdapter =
    __FunctionObjectAdapterImpl<typename std::remove_reference<T>::type>;
/// @endcond

} // namespace __detail
} // namespace stl_algorithm

#endif  // __STL_ALGORITHM_DETAIL_FUNCTION_OBJECT_ADAPTER_HPP__
