
#ifndef __STL_ALGORITHM_ALL_OF_HPP__
#define __STL_ALGORITHM_ALL_OF_HPP__

#include <algorithm>
#include <boost/iterator/iterator_traits.hpp>
#include <boost/concept/requires.hpp>
#include "concept/input_iterator.hpp"
#include "concept/unary_predicate.hpp"

namespace stl_algorithm {

template <class InputIt, class UnaryPredicate>
    BOOST_CONCEPT_REQUIRES(
        ((stl_concept::InputIterator<InputIt>))
        ((stl_concept::UnaryPredicate<UnaryPredicate, typename boost::iterator_value<InputIt>::type>)),
        (bool)
    )
inline all_of(InputIt first, InputIt last, UnaryPredicate p)
{
    return std::all_of(first, last, p);
}

} // namespace stl_algorithm

#endif  // __STL_ALGORITHM_ALL_OF_HPP__
