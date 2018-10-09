/** @file */
#ifndef __STL_CONCEPT_UNARY_PREDICATE_HPP__
#define __STL_CONCEPT_UNARY_PREDICATE_HPP__

#include <boost/static_assert.hpp>
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/add_lvalue_reference.hpp>
#include <boost/type_traits/declval.hpp>
#include <boost/type_traits/is_object.hpp>
#include <boost/concept/usage.hpp>
#include <boost/concept/detail/concept_def.hpp>
#include "concept/detail/require_expr_convertible_to.hpp"

#if (defined _MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4197) // topmost volatile ignored
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // object 'class' can never be instantiated - user-defined constructor required
#endif

namespace stl_concept {

/**
 * @addtogroup library_wide_group Library-wide Requirements
 * @struct stl_concept::UnaryPredicate
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
template <typename Func, typename Arg> struct UnaryPredicate {};
#else // DOXYGEN_WORKING
BOOST_concept(UnaryPredicate, (Func)(Arg))
{
    BOOST_CONCEPT_USAGE(UnaryPredicate)
    {
        BOOST_STATIC_ASSERT_MSG(boost::is_object<Func>::value, "Type is not object");
        __detail::__require_expr_convertible_to<bool>(predicate_(boost::declval<_ArgType>()));
    }

private:
    using _ArgType = boost::add_lvalue_reference_t<boost::add_const_t<Arg>>;
    Func predicate_;
};
#endif // DOXYGEN_WORKING

template <typename Func, typename Arg>
struct UnaryPredicate<const Func, Arg> : UnaryPredicate<Func, Arg> {};

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_UNARY_PREDICATE_HPP__
