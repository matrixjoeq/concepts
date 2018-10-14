/** @file */
#ifndef __STL_CONCEPT_DETAIL_ITERATOR_TRAITS_HPP__
#define __STL_CONCEPT_DETAIL_ITERATOR_TRAITS_HPP__

#include <iterator>
#include <boost/iterator/iterator_traits.hpp>

namespace stl_concept {
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

/**
 * @brief Alias for std::iterator_traits<>::value_type
 * @tparam Iterator - iterator type
 * @see https://en.cppreference.com/w/cpp/iterator/iterator_traits
 */
template <class Iterator>
using __std_iterator_value_t = typename std::iterator_traits<Iterator>::value_type;

/**
 * @brief Alias for std::iterator_traits<>::reference
 * @tparam Iterator - iterator type
 * @see https://en.cppreference.com/w/cpp/iterator/iterator_traits
 */
template <class Iterator>
using __std_iterator_reference_t = typename std::iterator_traits<Iterator>::reference;

/**
 * @brief Alias for std::iterator_traits<>::pointer
 * @tparam Iterator - iterator type
 * @see https://en.cppreference.com/w/cpp/iterator/iterator_traits
 */
template <class Iterator>
using __std_iterator_pointer_t = typename std::iterator_traits<Iterator>::pointer;

/**
 * @brief Alias for std::iterator_traits<>::difference_type
 * @tparam Iterator - iterator type
 * @see https://en.cppreference.com/w/cpp/iterator/iterator_traits
 */
template <class Iterator>
using __std_iterator_difference_t = typename std::iterator_traits<Iterator>::difference_type;

/**
 * @brief Alias for std::iterator_traits<>::iterator_category
 * @tparam Iterator - iterator type
 * @see https://en.cppreference.com/w/cpp/iterator/iterator_traits
 */
template <class Iterator>
using __std_iterator_category_t = typename std::iterator_traits<Iterator>::iterator_category;

/// @endcond

} // namespace __detail
} // namespace stl_concept

#endif  // __STL_CONCEPT_DETAIL_ITERATOR_TRAITS_HPP__
