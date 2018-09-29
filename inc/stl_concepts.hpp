
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
 * The type T satisfies <i>DefaultConstructible</i> if
 * Given
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
 * The type T satisfies <i>MoveConstructible</i> if
 * Given
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
        (T(boost::declval<T>()));
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
 *   <li>The type T satisfies <i>MoveConstructible</i>, and</li>
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
    void const_lvalue_constraints(const T& x)
    {
        T u = x;
        (T(x));
        details::ignore_unused_variable_warning(u);
    }

    void const_rvalue_constraints()
    {
#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
        T u = boost::declval<const T>();
        (T(boost::declval<const T>()));
        details::ignore_unused_variable_warning(u);
#endif // BOOST_NO_CXX11_RVALUE_REFERENCES
    }

private:
    T v_;
};

/**
 * @class MoveAssignable
 * @brief Specifies that an instance of the type can be assigned from an rvalue argument.
 *
 * <p>
 * The type T satisfies <i>MoveAssignable</i> if
 * Given
 * <ul style="list-style-type:disc">
 *   <li>t, a modifiable lvalue expression of type T</li>
 *   <li>rv, an rvalue expression of type T</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Return type<th>Return value<th>Post-conditions
 *   <tr><td>t = rv    <td>T&         <td>t           <td>If t and rv do not refer to the same object, the value of t is equivalent to the value of rv before the assignment.<br/>The new value of rv is unspecified.
 * </table>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/MoveAssignable
 */
BOOST_concept(MoveAssignable, (T))
{
    BOOST_CONCEPT_USAGE(MoveAssignable)
    {
#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
        t_ = boost::declval<T>();
#endif // BOOST_NO_CXX11_RVALUE_REFERENCES
    }

private:
    T t_;
};

/**
 * @class CopyAssignable
 * @brief Specifies that an instance of the type can be copy-assigned from an lvalue expression.
 *
 * <p>
 * The type T satisfies <i>CopyAssignable</i> if
 * <ul style="list-style-type:disc">
 *   <li>The type T satisfies <i>MoveAssignable</i>, and</li>
 * </ul>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>t, a modifiable lvalue expression of type T</li>
 *   <li>v, an lvalue expression of type T or const T or an rvalue expression of type const T</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Return type<th>Return value<th>Post-conditions
 *   <tr><td>t = v     <td>T&         <td>t           <td>The value of t is equivalent to the value of v.<br/>The value of v is unchanged.
 * </table>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/CopyAssignable
 */
BOOST_concept(CopyAssignable, (T)) : MoveAssignable<T>
{
    BOOST_CONCEPT_USAGE(CopyAssignable)
    {
        t_ = v_;
        const_lvalue_constraints(v_);
    }

private:
    void const_lvalue_constraints(const T& x)
    {
        t_ = x;
    }

    void const_rvalue_constraints()
    {
#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
        t_ = boost::declval<const T>();
#endif // BOOST_NO_CXX11_RVALUE_REFERENCES
    }

private:
    T t_;
    T v_;
};

/**
 * @class Destructible
 * @brief Specifies that an instance of the type can be destructed.
 *
 * <p>
 * The type T satisfies <i>Destructible</i> if
 * Given
 * <ul style="list-style-type:disc">
 *   <li>u, a expression of type T</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Post-conditions
 *   <tr><td>u.~T()    <td>All resources owned by u are reclaimed, no exceptions are thrown.
 * </table>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/Destructible
 */
BOOST_concept(Destructible, (T))
{
    ~Destructible()
    {
        u_.~T();
    }

private:
    T u_;
};

} // namespace concepts

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPTS_HPP__
