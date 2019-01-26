/** @file */
#ifndef __STL_CONCEPT_UNARY_FUNCTION_HPP__
#define __STL_CONCEPT_UNARY_FUNCTION_HPP__

#include "concept/function_object.hpp"
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
 * @struct UnaryFunction
 * @brief Specifies that an instance of the type is callable with one and only one argument.
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
template <typename Func, typename Arg>
struct UnaryFunction
    : FunctionObject<Func, Arg> {};
#else // DOXYGEN_WORKING
BOOST_concept(UnaryFunction, (Func)(Arg))
    : FunctionObject<Func, Arg> {};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_UNARY_FUNCTION_HPP__
