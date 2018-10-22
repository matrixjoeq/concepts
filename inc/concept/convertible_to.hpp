/** @file */
#ifndef __STL_CONCEPT_CONVERTIBLE_TO_HPP__
#define __STL_CONCEPT_CONVERTIBLE_TO_HPP__

#include <boost/static_assert.hpp>
#include <boost/type_traits/is_convertible.hpp>
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
 * @addtogroup core_group Core Language Concepts
 * @class stl_concept::ConvertibleTo
 * @brief Specifies that an expression of the type and value category specified by From can be implicitly and explicitly
 * converted to the type To, and the two forms of conversion are equivalent.
 *
 * <p>
 * Specifically, <i>ConvertibleTo</i> is satisfied only if, given the invented function
 * ```
 * To test(From (&f)())
 * {
 *     return f();
 * }
 * ```
 * and a function f of type From () such that the expression f() is equality-preserving,
 * The type T satisfies <i>ConvertibleTo</i> if
 * <ul style="list-style-type:disc">
 *   <li>Either</li>
 *     <ul style="list-style-type:disc">
 *       <li>To is neither an object type nor a reference-to-object type, or</li>
 *       <li>static_cast<To>(f()) is equal to test(f), and</li>
 *     </ul>
 * </ul>
 * <ul style="list-style-type:disc">
 *   <li>One of the following is true:</li>
 *     <ul style="list-style-type:disc">
 *       <li>From is not a reference-to-object type, or</li>
 *       <li>From is an rvalue reference to a non-const-qualified type, and the resulting state of the object referenced
 *           by f() is valid but unspecified after either expression above; or</li>
 *       <li>the object referred to by f() is not modified by either expression above.</li>
 *     </ul>
 * </ul>
 * </p>
 * @tparam From - type to be converted from
 * @tparam To - type to be converted to
 * @see https://en.cppreference.com/w/cpp/concepts/ConvertibleTo
 */
#ifdef DOXYGEN_WORKING
template <typename From, typename To> struct ConvertibleTo {};
#else // DOXYGEN_WORKING
BOOST_concept(ConvertibleTo, (From)(To))
{
    BOOST_CONCEPT_USAGE(ConvertibleTo)
    {
        BOOST_STATIC_ASSERT(boost::is_convertible<From, To>::value);
        convertible_constraints(func_);
    }

private:
    ConvertibleTo();

    using _ConvertibleFuncRef = From (&)();
    void convertible_constraints(_ConvertibleFuncRef f)
    {
        __detail::__unuse(static_cast<To>(f()));
    }

    _ConvertibleFuncRef func_;
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_CONVERTIBLE_TO_HPP__
