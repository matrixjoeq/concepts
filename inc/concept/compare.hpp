/** @file */
#ifndef __STL_CONCEPT_COMPARE_HPP__
#define __STL_CONCEPT_COMPARE_HPP__

#include "concept/same.hpp"
#include "concept/convertible_to.hpp"
#include "concept/binary_predicate.hpp"
#include <boost/type_traits/declval.hpp>
#include <boost/concept/assert.hpp>
#include <boost/concept/usage.hpp>
#include <boost/concept/detail/concept_def.hpp>
#include "concept/detail/unuse.hpp"

#if (defined _MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4197) // topmost volatile ignored
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // object 'class' can never be instantiated - user-defined constructor required
#endif

namespace stl_concept {

/**
 * @addtogroup library_wide_group Library-wide Requirements
 * @struct Compare
 * @brief <i>Compare</i> is a set of requirements expected by some of the standard library facilities from the
 * user-provided function object types.
 *
 * <p>
 * The return value of the function call operation applied to an object of a type satisfying <i>Compare</i>, when
 * contextually converted to bool, yields true if the first argument of the call appears before the second in the strict
 * weak ordering relation induced by this type, and false otherwise.<br/>
 * As with any <i>BinaryPredicate</i>, evaluation of that expression is not allowed to call non-const functions through
 * the dereferenced iterators.
 * </p><p>
 * <b>Requirements</b>
 * </p><p>
 * The type T satisfies <i>Compare</i> if
 * <ul style="list-style-type:disc">
 *   <li>The type T satisfies <i>BinaryPredicate</i>, and</li>
 * </ul>
 * Given
 * <ul style="list-style-type:disc">
 *   <li><i>comp, an object of type T</li>
 *   <li>equiv(a, b), an expression equivalent to !comp(a, b) && !comp(b, a)</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression <th>Return type
 *   <tr><td>comp(a, b) <td>implicitly convertible to bool
 *   <tr><td>equiv(a, b)<td>bool
 * </table>
 * @tparam Func - function object type
 * @tparam First - first argument type
 * @tparam Second - second argument type
 * </p>
 */
#ifdef DOXYGEN_WORKING
template <typename Func, typename First, typename Second> struct Compare : BinaryPredicate<Func, First, Second> {};
#else // DOXYGEN_WORKING
BOOST_concept(Compare, (Func)(First)(Second)) : BinaryPredicate<Func, First, Second>
{
    BOOST_CONCEPT_USAGE(Compare)
    {
        using _CompRet1 = decltype(boost::declval<Func>()(boost::declval<First&>(), boost::declval<Second&>()));
        using _CompRet2 = decltype(boost::declval<Func>()(boost::declval<Second&>(), boost::declval<First&>()));
        BOOST_CONCETP_ASSERT((ConvertibleTo<_CompRet1, bool>));
        BOOST_CONCETP_ASSERT((ConvertibleTo<_CompRet2, bool>));
        BOOST_CONCEPT_ASSERT((Same<decltype(!boost::declval<_CompRet1>() && !boost::declval<_CompRet2>()), bool>));
    }
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_COMPARE_HPP__
