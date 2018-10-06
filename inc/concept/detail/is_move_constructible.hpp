
#ifndef __STL_CONCEPT_DETAIL_IS_MOVE_CONSTRUCTIBLE_HPP__
#define __STL_CONCEPT_DETAIL_IS_MOVE_CONSTRUCTIBLE_HPP__

#include <boost/type_traits/add_rvalue_reference.hpp>
#include <boost/type_traits/is_constructible.hpp>

namespace stl_concept {
namespace __detail {

template <class T>
struct __is_move_constructible
    : boost::is_constructible<T, typename boost::add_rvalue_reference<T>::type> {};

} // namespace __detail
} // namespace stl_concept

#endif  // __STL_CONCEPT_DETAIL_IS_MOVE_CONSTRUCTIBLE_HPP__