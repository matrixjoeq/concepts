/** @file */
#ifndef __STL_ALGORITHM_DETAIL_ITERATOR_TRAITS_HPP__
#define __STL_ALGORITHM_DETAIL_ITERATOR_TRAITS_HPP__

#include "concept/detail/iterator_traits.hpp"

namespace stl_algorithm {
namespace __detail {

/// @cond DEV
/** @brief Alias of stl_concept::__detail::__iterator_category_t */
template <class Iterator>
using __iterator_category_t = stl_concept::__detail::__iterator_category_t<Iterator>;

/** @brief Alias of stl_concept::__detail::__iterator_difference_t */
template <class Iterator>
using __iterator_difference_t = stl_concept::__detail::__iterator_difference_t<Iterator>;

/** @brief Alias of stl_concept::__detail::__iterator_pointer_t */
template <class Iterator>
using __iterator_pointer_t = stl_concept::__detail::__iterator_pointer_t<Iterator>;

/** @brief Alias of stl_concept::__detail::__iterator_reference_t */
template <class Iterator>
using __iterator_reference_t = stl_concept::__detail::__iterator_reference_t<Iterator>;

/** @brief Alias of stl_concept::__detail::__iterator_value_t */
template <class Iterator>
using __iterator_value_t = stl_concept::__detail::__iterator_value_t<Iterator>;

/// @endcond

} // namespace __detail
} // namespace stl_algorithm

#endif  // __STL_ALGORITHM_DETAIL_ITERATOR_TRAITS_HPP__
