
#ifndef __STL_CONCEPTS_HPP__
#define __STL_CONCEPTS_HPP__

#include <boost/config.hpp>
#include <boost/utility/declval.hpp>
#include <boost/concept/assert.hpp>
#include <boost/concept/usage.hpp>
#include <boost/concept/detail/concept_def.hpp>

#if (defined _MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // object 'class' can never be instantiated - user-defined constructor required
#endif

namespace stl_concepts {
namespace details {

template <class T>
inline void ignore_unused_variable_warning(const T&) {}

} // namespace details

/**
 * @class DefaultConstructible
 * @brief Specifies that an instance of the type can be default constructed.
 *
 * <p>
 * The type T satisfies <i>DefaultConstructible</i> if given
 * <ul style="list-style-type:disc">
 *   <li>u, an arbitrary identifier</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Post-conditions
 *   <tr><td>T u       <td> The object u is default-initialized.
 *   <tr><td>T u{}     <td> The object u is value-initialized or aggregate-initialized.
 *   <tr><td>T()       <td rowspan="2"> A temporary object of type T is value-initialzied or aggregate-initialized.
 *   <tr><td>T{}
 * </table>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/DefaultConstructible
 */
BOOST_concept(DefaultConstructible, (T))
{
    BOOST_CONCEPT_USAGE(DefaultConstructible)
    {
        T u;
        details::ignore_unused_variable_warning(u);
        T();

#if !defined(BOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX)
        T v{};
        details::ignore_unused_variable_warning(v);
        T{};
#endif // BOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX
    }
};

/**
 * @class MoveConstructible
 * @brief Specifies that an instance of the type can be constructed from an rvalue argument.
 *
 * <p>
 * The type T satisfies <i>MoveConstructible</i> if given
 * <ul style="list-style-type:disc">
 *   <li>rv, an rvalue expression of type T</li>
 *   <li>u, an arbitrary identifier</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Post-conditions
 *   <tr><td>T u = rv  <td> The value of u is equivalent to the value of rv before the initialization.<br/>The new value of rv is unspecified.
 *   <tr><td>T(rv)     <td> The value of T(rv) is equivalent to the value of rv before the initialization.<br/>The new value of rv is unspecified.
 * </table>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/MoveConstructible
 */
BOOST_concept(MoveConstructible, (T))
{
    BOOST_CONCEPT_USAGE(MoveConstructible)
    {
#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
        T u = boost::declval<T>();
        details::ignore_unused_variable_warning(u);
        T(boost::declval<T>());
#endif // BOOST_NO_CXX11_RVALUE_REFERENCES
    }
};

/**
 * @class CopyConstructible
 * @brief Specifies that an instance of the type can be copy-constructed from an lvalue expression.
 *
 * <p>
 * The type T satisfies <i>CopyConstructible</i> if
 * <ul style="list-style-type:disc">
 *   <li>The type T satisfies MoveConstructible, and</li>
 * </ul>
 * Given</br>
 * <ul style="list-style-type:disc">
 *   <li>v, an lvalue expression of type T or const T or an rvalue expression of type const T</li>
 *   <li>u, an arbitrary identifier</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Post-conditions
 *   <tr><td>T u = v   <td> The value of u is equivalent to the value of v.<br/>The value of v is unchanged.
 *   <tr><td>T(v)      <td> The value of T(v) is equivalent to the value of v.<br/>The value of v is unchanged.
 * </table>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/CopyConstructible
 */
BOOST_concept(CopyConstructible, (T)) : MoveConstructible<T>
{
    BOOST_CONCEPT_USAGE(CopyConstructible)
    {
        T u = v_;
        (T(v_));
        const_lvalue_constraints(u);
        const_rvalue_constraints();
    }

private:
    void const_lvalue_constraints(const T& v)
    {
        T u = v;
        (T(v));
        details::ignore_unused_variable_warning(u);
    }

    void const_rvalue_constraints()
    {
#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
        T u = boost::declval<const T>();
        T(boost::declval<const T>());
        details::ignore_unused_variable_warning(u);
#endif // BOOST_NO_CXX11_RVALUE_REFERENCES
    }

private:
    T v_;
};

} // namespace concepts

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPTS_HPP__
