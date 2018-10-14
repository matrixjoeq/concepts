/** @file */
#ifndef __STL_CONCEPT_FUNCTION_OBJECT_HPP__
#define __STL_CONCEPT_FUNCTION_OBJECT_HPP__

#include <boost/static_assert.hpp>
#include <boost/type_traits/declval.hpp>
#include <boost/type_traits/is_object.hpp>
#include <boost/type_traits/remove_const.hpp>
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
 * @struct FunctionObject
 * @brief Specifies that an instance of the type can be used on the left of the function call operator.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type F satisfies <i>FunctionObject</i> if
 * <ul style="list-style-type:disc">
 *   <li>The type F satisfies std::is_object, and</li>
 * </ul>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>f, a value of type F or const F</li>
 *   <li>args, suitable argument list, which may be empty</li>
 * </ul>
 * The following expressions must be valid:
 * <table>
 *   <tr><th>Expression<th>Requirements
 *   <tr><td>f(args)   <td>performs a function call
 * </table>
 * </p>
 * @tparam F - function object type
 * @tparam Args - argument types
 * @see https://en.cppreference.com/w/cpp/named_req/FunctionObject
 */
#ifdef DOXYGEN_WORKING
template <typename F, typename... Args> struct FunctionObject {};
#else // DOXYGEN_WORKING
template <typename F, typename... Args>
struct FunctionObject
{
    BOOST_CONCEPT_USAGE(FunctionObject)
    {
        BOOST_STATIC_ASSERT_MSG(boost::is_object<F>::value, "Type is not an object");
        using _ReturnType = decltype(boost::declval<F>()(boost::declval<Args&>()...));
        callable_test(boost::is_void<_ReturnType>());
    }

private:
    void callable_test(boost::is_void<void>)
    {
        boost::declval<F>()(boost::declval<Args&>()...);
    }

    void callable_test(...)
    {
        __detail::__unuse(boost::declval<F>()(boost::declval<Args&>()...));
    }
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_FUNCTION_OBJECT_HPP__
