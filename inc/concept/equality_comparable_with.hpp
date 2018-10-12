/** @file */
#ifndef __STL_CONCEPT_EQUALITY_COMPARABLE_WITH_HPP__
#define __STL_CONCEPT_EQUALITY_COMPARABLE_WITH_HPP__

#include "concept/convertible_to.hpp"
#include <boost/type_traits/remove_const.hpp>
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
 * @addtogroup library_wide_group Library-wide Requirements
 * @struct stl_concept::EqualityComparableWith
 * @brief Specifies that instances of the types must work with == operator and the result should have standard semantics.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type T and U satisfies <i>EqualityComparableWith</i> if<br/>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>a, expressions of type T or const T</li>
 *   <li>b, expressions of type U or const U</li>
 *   <li>c, expressions of type T or U or const T or const U</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Return type                   <th>Requirements
 *   <tr><td>a == b    <td>implicitly convertible to bool<td>Establishes an equivalence relation, that is, it satisfies
 *                                                           the following properties:
 *                                                           <ul style="list-style-type:disc">
 *                                                             <li>For all values of a, a == a yields true.</li>
 *                                                             <li>If a == b, then b == a</li>
 *                                                             <li>If a == b and b == c, then a == c</li>
 *                                                           </ul>
 * </table>
 * </p>
 * @tparam T - first type to be equal compared
 * @tparam U - second type to be equal compared
 * @see https://en.cppreference.com/w/cpp/named_req/EqualityComparable
 * @see https://en.cppreference.com/w/cpp/concepts/EqualityComparable
 */
#ifdef DOXYGEN_WORKING
template <typename T, typename U> struct EqualityComparableWith {};
#else // DOXYGEN_WORKING
BOOST_concept(EqualityComparableWith, (T)(U))
{
    BOOST_CONCEPT_USAGE(EqualityComparableWith)
    {
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(a_ == b_), bool>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(b_ == a_), bool>));
        const_constraints(a_, b_);
    }

private:
    using _Tp = boost::remove_const_t<T>;
    using _Up = boost::remove_const_t<U>;

    void const_constraints(const _Tp& x, const _Up& y)
    {
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(x == y), bool>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(y == x), bool>));
    }

    _Tp a_;
    _Up b_;
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_EQUALITY_COMPARABLE_WITH_HPP__
