/** @file */
#ifndef __STL_ALGORITHM_DETAIL_ITERATOR_TRAITS_HPP__
#define __STL_ALGORITHM_DETAIL_ITERATOR_TRAITS_HPP__

#include <boost/iterator/iterator_traits.hpp>

namespace stl_algorithm {
namespace __detail {

/// @cond DEV
/**
 * @brief Alias for boost::iterator_value<>::type
 * @tparam Iterator - iterator type
 * @see https://www.boost.org/doc/libs/1_66_0/libs/iterator/doc/iterator_traits.pdf
 */
template <class Iterator>
using __iterator_value_t = typename boost::iterator_value<Iterator>::type;

/**
 * @brief Alias for boost::iterator_reference<>::type
 * @tparam Iterator - iterator type
 * @see https://www.boost.org/doc/libs/1_66_0/libs/iterator/doc/iterator_traits.pdf
 */
template <class Iterator>
using __iterator_reference_t = typename boost::iterator_reference<Iterator>::type;

/**
 * @brief Alias for boost::iterator_pointer<>::type
 * @tparam Iterator - iterator type
 * @see https://www.boost.org/doc/libs/1_66_0/libs/iterator/doc/iterator_traits.pdf
 */
template <class Iterator>
using __iterator_pointer_t = typename boost::iterator_pointer<Iterator>::type;

/**
 * @brief Alias for boost::iterator_difference<>::type
 * @tparam Iterator - iterator type
 * @see https://www.boost.org/doc/libs/1_66_0/libs/iterator/doc/iterator_traits.pdf
 */
template <class Iterator>
using __iterator_difference_t = typename boost::iterator_difference<Iterator>::type;

/**
 * @brief Alias for boost::iterator_category<>::type
 * @tparam Iterator - iterator type
 * @see https://www.boost.org/doc/libs/1_66_0/libs/iterator/doc/iterator_traits.pdf
 */
template <class Iterator>
using __iterator_category_t = typename boost::iterator_category<Iterator>::type;
/// @endcond

} // namespace __detail
} // namespace stl_algorithm

#endif  // __STL_ALGORITHM_DETAIL_ITERATOR_TRAITS_HPP__
