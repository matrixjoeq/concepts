/** @file */
#ifndef __STL_CONCEPT_MUTABLE_FORWARD_ITERATOR_HPP__
#define __STL_CONCEPT_MUTABLE_FORWARD_ITERATOR_HPP__

#include "concept/same.hpp"
#include "concept/derived_from.hpp"
#include "concept/input_iterator.hpp"
#include "concept/incrementable.hpp"
#include "concept/output_iterator.hpp"
#include <iterator>
#include <boost/iterator/iterator_traits.hpp>
#include <boost/concept/assert.hpp>
#include <boost/concept/usage.hpp>
#include <boost/concept/detail/concept_def.hpp>

#if (defined _MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4197) // topmost volatile ignored
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // object 'class' can never be instantiated - user-defined constructor required
#endif

namespace stl_concept {

/**
 * @addtogroup iterator_group Iterator Requirements
 * @struct MutableForwardIterator
 * @brief Refines <i>ForwardIterator</i> by adding output iterator concept check.
 *
 * @tparam It - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/ForwardIterator
 */
#ifdef DOXYGEN_WORKING
template <typename It, typename ValueType> struct MutableForwardIterator
    : InputIterator<It>, Incrementable<It>, OutputIterator<It, ValueType> {};
#else // DOXYGEN_WORKING
BOOST_concept(MutableForwardIterator, (It)(ValueType))
    : InputIterator<It>, Incrementable<It>, OutputIterator<It, ValueType>
{
    BOOST_CONCEPT_USAGE(MutableForwardIterator)
    {
        using _ValueType = typename boost::iterator_value<It>::type;
        using _ReferenceType = typename boost::iterator_reference<It>::type;
        using _CategoryType = typename boost::iterator_category<It>::type;
        BOOST_CONCEPT_ASSERT((Same<_ReferenceType, _ValueType&>));
        BOOST_CONCEPT_ASSERT((DerivedFrom<_CategoryType, std::forward_iterator_tag>));
    }
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_MUTABLE_FORWARD_ITERATOR_HPP__
