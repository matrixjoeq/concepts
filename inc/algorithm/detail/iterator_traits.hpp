
#ifndef __STL_ALGORITHM_DETAIL_ITERATOR_TRAITS_HPP__
#define __STL_ALGORITHM_DETAIL_ITERATOR_TRAITS_HPP__

#include <boost/iterator/iterator_traits.hpp>

namespace stl_algorithm {
namespace __detail {

template <class Iterator>
using __iterator_value_t = typename boost::iterator_value<Iterator>::type;

template <class Iterator>
using __iterator_reference_t = typename boost::iterator_reference<Iterator>::type;

template <class Iterator>
using __iterator_pointer_t = typename boost::iterator_pointer<Iterator>::type;

template <class Iterator>
using __iterator_difference_t = typename boost::iterator_difference<Iterator>::type;

template <class Iterator>
using __iterator_category_t = typename boost::iterator_category<Iterator>::type;

} // namespace __detail
} // namespace stl_algorithm

#endif  // __STL_ALGORITHM_DETAIL_ITERATOR_TRAITS_HPP__
