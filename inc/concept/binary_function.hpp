/** @file */
#ifndef __STL_CONCEPT_BINARY_FUNCTION_HPP__
#define __STL_CONCEPT_BINARY_FUNCTION_HPP__

#include <boost/static_assert.hpp>
#include <boost/type_traits/add_lvalue_reference.hpp>
#include <boost/type_traits/declval.hpp>
#include <boost/type_traits/is_object.hpp>
#include <boost/type_traits/is_void.hpp>
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
 * @struct stl_concept::BinaryFunction
 * @brief Specifies that an instance of the type is callable with one and only one argument.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * <ul style="list-style-type:disc">
 *   <li><i>FunctionObject</i></li>
 * </ul>
 * @tparam Func - function object type
 * @tparam First - first argument type
 * @tparam Second - second argument type
 * </p>
 */
#ifdef DOXYGEN_WORKING
template <typename Func, typename First, typename Second> struct BinaryFunction {};
#else // DOXYGEN_WORKING
BOOST_concept(BinaryFunction, (Func)(First)(Second))
{
    BOOST_CONCEPT_USAGE(BinaryFunction)
    {
        BOOST_STATIC_ASSERT_MSG(boost::is_object<Func>::value, "Type is not object");
        using _ReturnType = decltype(function_object_(boost::declval<_FirstArg>(), boost::declval<_SecondArg>()));
        callable_test(boost::is_void<_ReturnType>());
    }

private:
    using _FirstArg = boost::add_lvalue_reference_t<First>;
    using _SecondArg = boost::add_lvalue_reference_t<Second>;

    void callable_test(boost::is_void<void>)
    {
        function_object_(boost::declval<_FirstArg>(), boost::declval<_SecondArg>());
    }

    void callable_test(...)
    {
        __detail::__unuse(function_object_(boost::declval<_FirstArg>(), boost::declval<_SecondArg>()));
    }

    Func function_object_;
};
#endif // DOXYGEN_WORKING

template <typename Func, typename First, typename Second>
struct BinaryFunction<const Func, First, Second> : BinaryFunction<Func, First, Second> {};

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_BINARY_FUNCTION_HPP__
