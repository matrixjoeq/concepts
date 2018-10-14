/** @file */
#ifndef __STL_ALGORITHM_DETAIL_ITERATOR_TRAITS_HPP__
#define __STL_ALGORITHM_DETAIL_ITERATOR_TRAITS_HPP__

#include "concept/detail/iterator_traits.hpp"

namespace stl_algorithm {
namespace __detail {

/// @cond DEV
/** @brief Alias of stl_concept::__detail::__iterator_category_t */
using stl_concept::__detail::__iterator_category_t;

/** @brief Alias of stl_concept::__detail::__iterator_difference_t */
using stl_concept::__detail::__iterator_difference_t;

/** @brief Alias of stl_concept::__detail::__iterator_pointer_t */
using stl_concept::__detail::__iterator_pointer_t;

/** @brief Alias of stl_concept::__detail::__iterator_reference_t */
using stl_concept::__detail::__iterator_reference_t;

/** @brief Alias of stl_concept::__detail::__iterator_value_t */
using stl_concept::__detail::__iterator_value_t;

/** @brief Alias of stl_concept::__detail::__std_iterator_category_t */
using stl_concept::__detail::__std_iterator_category_t;

/** @brief Alias of stl_concept::__detail::__std_iterator_difference_t */
using stl_concept::__detail::__std_iterator_difference_t;

/** @brief Alias of stl_concept::__detail::__std_iterator_pointer_t */
using stl_concept::__detail::__std_iterator_pointer_t;

/** @brief Alias of stl_concept::__detail::__std_iterator_reference_t */
using stl_concept::__detail::__std_iterator_reference_t;

/** @brief Alias of stl_concept::__detail::__std_iterator_value_t */
using stl_concept::__detail::__std_iterator_value_t;
/// @endcond

} // namespace __detail
} // namespace stl_algorithm

#endif  // __STL_ALGORITHM_DETAIL_ITERATOR_TRAITS_HPP__
