/** @file */
#ifndef __STL_CONCEPT_FUNCTION_OBJECT_HPP__
#define __STL_CONCEPT_FUNCTION_OBJECT_HPP__

#include <boost/static_assert.hpp>
#include <boost/type_traits/is_object.hpp>
#include <boost/type_traits/remove_const.hpp>
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
 * @struct stl_concept::FunctionObject
 * @brief Specifies that an instance of the type can be used on the left of the function call operator.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type T satisfies <i>FunctionObject</i> if
 * <ul style="list-style-type:disc">
 *   <li>The type T satisfies std::is_object, and</li>
 * </ul>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>f, a value of type T or const T</li>
 *   <li>args, suitable argument list, which may be empty</li>
 * </ul>
 * The following expressions must be valid:
 * <table>
 *   <tr><th>Expression<th>Requirements
 *   <tr><td>f(args)   <td>performs a function call
 * </table>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/FunctionObject
 */
#ifdef DOXYGEN_WORKING
template <typename T> struct FunctionObject {};
#else // DOXYGEN_WORKING
BOOST_concept(FunctionObject, (T))
{
    BOOST_CONCEPT_USAGE(FunctionObject)
    {
        BOOST_STATIC_ASSERT_MSG(boost::is_object<_Tp>::value, "Type is not object");
    }

private:
    using _Tp = boost::remove_const_t<T>;

    _Tp function_object_;
};
#endif // DOXYGEN_WORKING

template <typename R, typename... Args>
struct FunctionObject<R(*)(Args...)> {};

template <typename R, typename... Args>
struct FunctionObject<R(* const)(Args...)> {};

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_FUNCTION_OBJECT_HPP__
