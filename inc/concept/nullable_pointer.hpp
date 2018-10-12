/** @file */
#ifndef __STL_CONCEPT_NULLABLE_POINTER_HPP__
#define __STL_CONCEPT_NULLABLE_POINTER_HPP__

#include "concept/same.hpp"
#include "concept/convertible_to.hpp"
#include "concept/copy_assignable.hpp"
#include "concept/copy_constructible.hpp"
#include "concept/default_constructible.hpp"
#include "concept/destructible.hpp"
#include "concept/equality_comparable.hpp"
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
 * @struct NullablePointer
 * @brief Specifies that the type is a pointer-like object which can be compared to std::nullptr_t objects.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type must meet all of the following requirements:
 * <ul style="list-style-type:disc">
 *   <li><i>EqualityComparable</i></li>
 *   <li><i>DefaultConstructible</i></li>
 *   <li><i>CopyConstructible</i></li>
 *   <li><i>CopyAssignable</i></li>
 *   <li><i>Destructible</i></li>
 * </ul>
 * In addition, a value-initialized object of the type must produce a null value of that type.
 * This null value shall only be equivalent to itself. Default initialization of the type may have an indeterminate
 * value.<br/>
 * An object of the type must be contextually convertible to bool. The effect of this conversion returns false if the
 * value is equivalent to its null value and true otherwise.<br/>
 * None of the operations that this type performs may throw exceptions.<br/>
 * The type must satisfy the following additional expressions, given two values p and q that are of the type, and that
 * np is a value of std::nullptr_t type (possibly const qualified):
 * <table>
 *   <tr><th>Expression                  <th>Effects
 *   <tr><td>Type p(np);<br/>Type p = np;<td>Afterwards, p is equivalent to nullptr
 *   <tr><td>Type(np)                    <td>A temporary object that is equivalent to nullptr
 *   <tr><td>p = np                      <td>Must return a Type&, and afterwards, p is equivalent to nullptr
 *   <tr><td>p != q                      <td>Must return a value that is contextually convertible to bool.<br/>The effect is !(p == q)
 *   <tr><td>p == np<br/>np == p         <td>Must return a value that is contextually convertible to bool.<br/>The effect is (p == Type())
 *   <tr><td>p != np<br/>np != p         <td>Must return a value that is contextually convertible to bool.<br/>The effect is !(p == np)
 * </table>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/NullablePointer
 */
#ifdef DOXYGEN_WORKING
template <typename T> struct NullablePointer
    : EqualityComparable<T>, DefaultConstructible<T>, CopyConstructible<T>, CopyAssignable<T>, Destructible<T> {};
#else // DOXYGEN_WORKING
BOOST_concept(NullablePointer, (T))
    : EqualityComparable<T>, DefaultConstructible<T>, CopyConstructible<T>, CopyAssignable<T>, Destructible<T>
{
    BOOST_CONCEPT_USAGE(NullablePointer)
    {
        T p(nullptr);
        T q = nullptr;
        __detail::__unuse(T(nullptr));

        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(p == q), bool>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(p != q), bool>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(p == nullptr), bool>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(nullptr == p), bool>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(p != nullptr), bool>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(nullptr != p), bool>));

        __detail::__unuse(p = nullptr);
        BOOST_CONCEPT_ASSERT((Same<decltype(p = nullptr), T&>));
    }
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_NULLABLE_POINTER_HPP__
