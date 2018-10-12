/** @file */
#ifndef __STL_CONCEPT_OUTPUT_ITERATOR_HPP__
#define __STL_CONCEPT_OUTPUT_ITERATOR_HPP__

#include "concept/same.hpp"
#include "concept/iterator.hpp"
#include <boost/static_assert.hpp>
#include <boost/iterator/iterator_traits.hpp>
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/add_lvalue_reference.hpp>
#include <boost/type_traits/is_object.hpp>
#include <boost/type_traits/is_pointer.hpp>
#include <boost/concept/assert.hpp>
#include <boost/concept/usage.hpp>
#include <boost/concept/detail/concept_def.hpp>
#include "concept/detail/require_expr_convertible_to.hpp"
#include "concept/detail/unuse.hpp"

#if (defined _MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4197) // topmost volatile ignored
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // object 'class' can never be instantiated - user-defined constructor required
#endif

namespace stl_concept {

/**
 * @addtogroup iterator_group Iterator Requirements
 * @struct stl_concept::OutputIterator
 * @brief Specifies that an instance of the type is an <i>Iterator</i> that can write to the pointed-to element.
 *
 * <p>
 * An example of a type that implements <i>OutputIterator</i> is std::ostream_iterator.<br/>
 * When <i>ForwardIterator</i>, <i>BidirectionalIterator</i>, or <i>RandomAccessIterator</i> satisfies the
 * <i>OutputIterator</i> requirements in addition to its own requirements, it is described as mutable.
 * </p><p>
 * <b>Requirements</b>
 * </p><p>
 * The type It satisfies <i>OutputIterator</i> if
 * <ul style="list-style-type:disc">
 *   <li>The type It satisfies <i>Iterator</i>, and</li>
 *   <li>The type It is a class type or a pointer type, and</li>
 * </ul>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>o, a value of some type that is writable to the output iterator (there may be multiple types that are writable,
 *       e.g. if operator= may be a template. There is no notion of value_type as for the input iterators)</li>
 *   <li>r, an lvalue of type It</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Return                  <th>Equivalent expression                 <th>Pre-condition     <th>Post-conditions
 *   <tr><td>*r = o    <td>(not used)              <td>                                      <td>r is dereferecable<td>r is incrementable
 *   <tr><td>++r       <td>It&                     <td>                                      <td>r is incrementable<td>&r == &++r, r is dereferencable or past-the-end
 *   <tr><td>r++       <td>convertible to const It&<td>It temp = r;<br/>++r;<br/>return temp;<td>                  <td>
 *   <tr><td>*r++ = o  <td>(not used)              <td>*r = o;<br/>++r;                      <td>                  <td>
 * </table>
 * </p>
 * @tparam It - iterator type
 * @tparam ValueType - value type to be written to iterator
 * @see https://en.cppreference.com/w/cpp/named_req/OutputIterator
 */
#ifdef DOXYGEN_WORKING
template <typename It, typename ValueType> struct OutputIterator : Iterator<It> {};
#else // DOXYGEN_WORKING
BOOST_concept(OutputIterator, (It)(ValueType)) : Iterator<It>
{
    BOOST_CONCEPT_USAGE(OutputIterator)
    {
        BOOST_STATIC_ASSERT_MSG(boost::is_object<It>::value || boost::is_pointer<It>::value,
                                "Type is neither object nor pointer");
        BOOST_CONCEPT_ASSERT((Same<decltype(++iter_r_), It&>));
        __detail::__unuse(*iter_r_ = value_);
        __detail::__unuse(++iter_r_);
        __detail::__require_expr_convertible_to<_ConstItRefType>(iter_r_++);
        __detail::__unuse(*iter_r_++ = value_);
    }

private:
    using _ConstItRefType = boost::add_lvalue_reference_t<boost::add_const_t<It>>;
    It iter_r_;
    ValueType value_;
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_OUTPUT_ITERATOR_HPP__
