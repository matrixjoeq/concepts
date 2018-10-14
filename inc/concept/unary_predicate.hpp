/** @file */
#ifndef __STL_CONCEPT_UNARY_PREDICATE_HPP__
#define __STL_CONCEPT_UNARY_PREDICATE_HPP__

#include "concept/convertible_to.hpp"
#include "concept/unary_function.hpp"
#include <boost/type_traits/declval.hpp>
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
 * @struct UnaryPredicate
 * @brief Specifies that an instance of the type is callable and returns a value testable as a bool.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * <ul style="list-style-type:disc">
 *   <li><i>FunctionObject</i></li>
 * </ul>
 * @tparam Func - function object type
 * @tparam Arg - argument type
 * </p>
 */
#ifdef DOXYGEN_WORKING
template <typename Func, typename Arg> struct UnaryPredicate : UnaryFunction<Func, Arg> {};
#else // DOXYGEN_WORKING
BOOST_concept(UnaryPredicate, (Func)(Arg)) : UnaryFunction<Func, Arg>
{
    BOOST_CONCEPT_USAGE(UnaryPredicate)
    {
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(boost::declval<Func>()(boost::declval<Arg&>())), bool>));
    }
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_UNARY_PREDICATE_HPP__
