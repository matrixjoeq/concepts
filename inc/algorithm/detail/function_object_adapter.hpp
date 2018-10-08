/** @file */
#ifndef __STL_ALGORITHM_DETAIL_FUNCTION_OBJECT_ADAPTER_HPP__
#define __STL_ALGORITHM_DETAIL_FUNCTION_OBJECT_ADAPTER_HPP__

#include <boost/type_traits/conditional.hpp>
#include <boost/type_traits/decay.hpp>
#include <boost/type_traits/is_function.hpp>

namespace stl_algorithm {
namespace __detail {
namespace {

template <class T>
using __FunctionObjectAdapterImpl = boost::conditional_t<boost::is_function<T>::value, boost::decay_t<T>, T>;

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
using __FunctionObjectAdapter = __FunctionObjectAdapterImpl<boost::remove_reference_t<T>>;
/// @endcond

} // namespace __detail
} // namespace stl_algorithm

#endif  // __STL_ALGORITHM_DETAIL_FUNCTION_OBJECT_ADAPTER_HPP__
