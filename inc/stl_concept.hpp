/**
 * @file stl_concept.hpp
 * @brief Classes in this file define named requirements used in the normative text of the C++ standard library.
 * @author Qu Xing
 * @version 0.1
 * @date 2018
 * @copyright MIT License
 */

#ifndef __STL_CONCEPT_HPP__
#define __STL_CONCEPT_HPP__

// for swap
#if __cplusplus < 201103L
#include <algorithm>
#else // __cplusplus < 201103L
#include <utility>
#endif // __cplusplus < 201103L

#include <boost/config.hpp>
#include <boost/type_traits/declval.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <boost/type_traits/add_rvalue_reference.hpp>
#include <boost/type_traits/remove_cv_ref.hpp>
#include <boost/iterator/iterator_traits.hpp>
#include <boost/concept/assert.hpp>
#include <boost/concept/usage.hpp>
#include <boost/concept/detail/concept_def.hpp>

#if (defined _MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // object 'class' can never be instantiated - user-defined constructor required
#endif

namespace stl_concept {

namespace __detail {

template <class T>
inline void __ignore_unused_variable_warning(const T&) {}

template <class T>
void __require_boolean_expr(const T& t)
{
    bool x = t;
    __ignore_unused_variable_warning(x);
}

template <class T, class U, typename = typename boost::enable_if<boost::is_same<T, U> >::type>
inline void __require_exact_type() {}

} // namespace __detail

template <class T> struct Iterator;

/**
 * @defgroup basic_group Basic Requirements
 * @{
 */
/**
 * @class stl_concept::DefaultConstructible
 * @brief Specifies that an instance of the type can be default constructed.
 *
 * <b>Requirements</b>
 * <p>
 * The type T satisfies <i>DefaultConstructible</i> if<br/>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>u, an arbitrary identifier</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Post-conditions
 *   <tr><td>T u       <td>The object u is default-initialized.
 *   <tr><td>T u{}     <td>The object u is value-initialized or aggregate-initialized.
 *   <tr><td>T()       <td rowspan="2">A temporary object of type T is value-initialzied or aggregate-initialized.
 *   <tr><td>T{}
 * </table>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/DefaultConstructible
 * @see https://en.cppreference.com/w/cpp/concepts/DefaultConstructible
 */
BOOST_concept(DefaultConstructible, (T))
{
    BOOST_CONCEPT_USAGE(DefaultConstructible)
    {
        T u;
        __detail::__ignore_unused_variable_warning(u);
        T();

#if !defined(BOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX)
        T v{};
        __detail::__ignore_unused_variable_warning(v);
        __detail::__ignore_unused_variable_warning(T{});
#endif // BOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX
    }
};

namespace __detail {

template <class T>
struct __is_move_constructible
    : boost::is_constructible<T, typename boost::add_rvalue_reference<T>::type> {};

} // namespace __detail

/**
 * @class stl_concept::MoveConstructible
 * @brief Specifies that an instance of the type can be constructed from an rvalue argument.
 *
 * <b>Requirements</b>
 * <p>
 * The type T satisfies <i>MoveConstructible</i> if<br/>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>rv, an rvalue expression of type T</li>
 *   <li>u, an arbitrary identifier</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Post-conditions
 *   <tr><td>T u = rv  <td>The value of u is equivalent to the value of rv before the initialization.<br/>
 *                         The new value of rv is unspecified.
 *   <tr><td>T(rv)     <td>The value of T(rv) is equivalent to the value of rv before the initialization.<br/>
 *                         The new value of rv is unspecified.
 * </table>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/MoveConstructible
 * @see https://en.cppreference.com/w/cpp/concepts/MoveConstructible
 */
BOOST_concept(MoveConstructible, (T))
{
    BOOST_CONCEPT_USAGE(MoveConstructible)
    {
        T u = boost::declval<T>(); // boost::declval works even before c++11
        __detail::__ignore_unused_variable_warning(u);
        (T(boost::declval<T>()));
    }
};

/**
 * @class stl_concept::CopyConstructible
 * @brief Specifies that an instance of the type can be copy-constructed from an lvalue expression.
 *
 * <b>Requirements</b>
 * <p>
 * The type T satisfies <i>CopyConstructible</i> if
 * <ul style="list-style-type:disc">
 *   <li>The type T satisfies <i>MoveConstructible</i>, and</li>
 * </ul>
 * Given
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
 * @see https://en.cppreference.com/w/cpp/concepts/CopyConstructible
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
        __detail::__ignore_unused_variable_warning(u);
    }

    void const_rvalue_constraints()
    {
        T u = boost::declval<const T>();
        (T(boost::declval<const T>()));
        __detail::__ignore_unused_variable_warning(u);
    }

private:
    T v_;
};

/**
 * @class stl_concept::MoveAssignable
 * @brief Specifies that an instance of the type can be assigned from an rvalue argument.
 *
 * <b>Requirements</b>
 * <p>
 * The type T satisfies <i>MoveAssignable</i> if<br/>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>t, a modifiable lvalue expression of type T</li>
 *   <li>rv, an rvalue expression of type T</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Return type<th>Return value<th>Post-conditions
 *   <tr><td>t = rv    <td>T&         <td>t           <td>If t and rv do not refer to the same object, the value of t is
 *                                                        equivalent to the value of rv before the assignment.<br/>
 *                                                        The new value of rv is unspecified.
 * </table>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/MoveAssignable
 * @see https://en.cppreference.com/w/cpp/concepts/Movable
 */
BOOST_concept(MoveAssignable, (T))
{
    BOOST_CONCEPT_USAGE(MoveAssignable)
    {
        t_ = boost::declval<T>();
    }

private:
    T t_;
};

/**
 * @class stl_concept::CopyAssignable
 * @brief Specifies that an instance of the type can be copy-assigned from an lvalue expression.
 *
 * <b>Requirements</b>
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
 *   <tr><td>t = v     <td>T&         <td>t           <td>The value of t is equivalent to the value of v.<br/>
 *                                                        The value of v is unchanged.
 * </table>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/CopyAssignable
 * @see https://en.cppreference.com/w/cpp/concepts/Copyable
 */
BOOST_concept(CopyAssignable, (T)) : MoveAssignable<T>
{
    BOOST_CONCEPT_USAGE(CopyAssignable)
    {
        t_ = v_;
        const_lvalue_constraints(v_);
        const_rvalue_constraints();
    }

private:
    void const_lvalue_constraints(const T& x)
    {
        t_ = x;
    }

    void const_rvalue_constraints()
    {
        t_ = boost::declval<const T>();
    }

private:
    T t_;
    T v_;
};

/**
 * @class stl_concept::Destructible
 * @brief Specifies that an instance of the type can be destructed.
 *
 * <b>Requirements</b>
 * <p>
 * The type T satisfies <i>Destructible</i> if<br/>
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
 * @see https://en.cppreference.com/w/cpp/concepts/Destructible
 */
BOOST_concept(Destructible, (T))
{
    BOOST_CONCEPT_USAGE(Destructible)
    {
        // ~T() is called in ~Destructible()
    }
};
/** @} */ // end of basic_group

/**
 * @defgroup library_wide_group Library-wide Requirements
 * @{
 */
/**
 * @class stl_concept::EqualityComparable
 * @brief The type must work with == operator and the result should have standard semantics.
 *
 * <b>Requirements</b>
 * <p>
 * The type T satisfies <i>EqualityComparable</i> if<br/>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>a, b, and c, expressions of type T or const T</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Return type                   <th>Requirements
 *   <tr><td>a == b    <td>implicitly convertible to bool<td>Establishes an equivalence relation, that is, it satisfies
 *                                                           the following properties:
 *                                                           <ul style="list-style-type:disc">
 *                                                             <li>For all values of a, a == a yields true.</li>
 *                                                             <li>If a == b, then b == a</li>
 *                                                             <li>If a == b and b == c, then a == c</li>
 *                                                           </ul>
 * </table>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/EqualityComparable
 * @see https://en.cppreference.com/w/cpp/concepts/EqualityComparable
 */
BOOST_concept(EqualityComparable, (T))
{
    BOOST_CONCEPT_USAGE(EqualityComparable)
    {
        __detail::__require_boolean_expr(a_ == b_);
        nonconst_const_constraints(a_, b_);
        const_const_constraints(a_, b_);
        const_nonconst_constraints(a_, b_);
    }

private:
    void nonconst_const_constraints(T& x, const T& y)
    {
        __detail::__require_boolean_expr(x == y);
    }

    void const_const_constraints(const T&x, const T& y)
    {
        __detail::__require_boolean_expr(x == y);
    }

    void const_nonconst_constraints(const T& x, T& y)
    {
        __detail::__require_boolean_expr(x == y);
    }

private:
    T a_;
    T b_;
};

/**
 * @class stl_concept::LessThanComparable
 * @brief The type must work with < operator and the result should have standard semantics.
 *
 * <b>Requirements</b>
 * <p>
 * The type T satisfies <i>LessThanComparable</i> if<br/>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>a, b, and c, expressions of type T or const T</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Return type                   <th>Requirements
 *   <tr><td>a < b     <td>implicitly convertible to bool<td>Establishes strict weak ordering relation with the
 *                                                           following properties
 *                                                           <ul style="list-style-type:disc">
 *                                                             <li>For all a, !(a < a)</li>
 *                                                             <li>If a < b then !(b < a)</li>
 *                                                             <li>If a < b and b < c then a < c</li>
 *                                                             <li>Defining equiv(a, b) as !(a < b) && !(b < a), if
 *                                                                 equiv(a, b) and equiv(b, c), then equiv(a, c)</li>
 *                                                           </ul>
 * </table>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/LessThanComparable
 */
BOOST_concept(LessThanComparable, (T))
{
    BOOST_CONCEPT_USAGE(LessThanComparable)
    {
        __detail::__require_boolean_expr(a_ < b_);
        nonconst_const_constraints(a_, b_);
        const_const_constraints(a_, b_);
        const_nonconst_constraints(a_, b_);
    }

private:
    void nonconst_const_constraints(T& x, const T& y)
    {
        __detail::__require_boolean_expr(x < y);
    }

    void const_const_constraints(const T&x, const T& y)
    {
        __detail::__require_boolean_expr(x < y);
    }

    void const_nonconst_constraints(const T& x, T& y)
    {
        __detail::__require_boolean_expr(x < y);
    }

private:
    T a_;
    T b_;
};

namespace __detail {

struct __is_referenceable_impl
{
    template <class T> static T& __test(int);
    template <class T> static boost::type_traits::no_type __test(...);
};

template <class T>
struct __is_referenceable : boost::integral_constant<bool,
    !boost::is_same<decltype(__is_referenceable_impl::__test<T>(0)), boost::type_traits::no_type>::value> {};

BOOST_concept(__Referenceable, (T))
{
private:
    typedef typename boost::remove_cv_ref<T>::type _Tp;
    _Tp t_;

public:
    BOOST_CONCEPT_USAGE(__Referenceable)
    {
        _Tp& r = t_;
        __detail::__ignore_unused_variable_warning(r);
    }
};

template <class T> struct __Referenceable<T[]> {};
template <class T, size_t N> struct __Referenceable<T[N]> {};

#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
template <class R, class... Args> struct __Referenceable<R(Args...)> {};
#else // BOOST_NO_CXX11_VARIADIC_TEMPLATES
template <class R> struct __Referenceable<R()> {};
template <class R, class A0> struct __Referenceable<R(A0)> {};
template <class R, class A0, class A1> struct __Referenceable<R(A0, A1)> {};
template <class R, class A0, class A1, class A2> struct __Referenceable<R(A0, A1, A2)> {};
template <class R, class A0, class A1, class A2, class A3> struct __Referenceable<R(A0, A1, A2, A3)> {};
template <class R, class A0, class A1, class A2, class A3, class A4> struct __Referenceable<R(A0, A1, A2, A3, A4)> {};
template <class R, class A0, class A1, class A2, class A3, class A4, class A5>
struct __Referenceable<R(A0, A1, A2, A3, A4, A5)> {};
template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6>
struct __Referenceable<R(A0, A1, A2, A3, A4, A5, A6)> {};
template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
struct __Referenceable<R(A0, A1, A2, A3, A4, A5, A6, A7)> {};
template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
struct __Referenceable<R(A0, A1, A2, A3, A4, A5, A6, A7, A8)> {};
template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
struct __Referenceable<R(A0, A1, A2, A3, A4, A5, A6, A7, A8, A9)> {};
#endif // BOOST_NO_CXX11_VARIADIC_TEMPLATES

} // namespace __detail

/**
 * @class stl_concept::Swappable
 * @brief Specifies that lvalues of type T are swappable.
 *
 * <b>Requirements</b>
 * <p>
 * The type T satisfies <i>Swappable</i> if<br/>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>a1, a2, b1 and b2, distinct objects of type T such that a1 is equal to a2 and b1 is equal to b2</li>
 * </ul>
 * <i>Swappable</i> is satisfied only if, after evaluating either swap(a1, b1) or swap(b1, a1),
 * a1 is equal to b2 and b1 is equal to a2.
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/Swappable
 * @see https://en.cppreference.com/w/cpp/concepts/Swappable
 */
BOOST_concept(Swappable, (T)) : __detail::__Referenceable<T>
{
    BOOST_CONCEPT_USAGE(Swappable)
    {
        using std::swap;
        swap(boost::declval<T&>(), boost::declval<T&>());
    }
};

/**
 * @class stl_concept::ValueSwappable
 * @brief Two objects of this type can be dereferenced and the resulting values can be swapped using
 * unqualified function call swap() in the context where both std::swap and the user-defined swap()s are visible.
 *
 * <b>Requirements</b>
 * <p>
 * The type T satisfies <i>ValueSwappable</i> if<br/>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>T satisfies the <i>Iterator</i> requirements</li>
 *   <li>For any dereferencable object x of type T (that is, any value other than the end iterator),
 *       *x satisfies the <i>Swappable</i> requirements.</li>
 * </ul>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/ValueSwappable
 */
BOOST_concept(ValueSwappable, (T)) : Iterator<T>
{
    BOOST_CONCEPT_USAGE(ValueSwappable)
    {
        BOOST_CONCEPT_ASSERT((Swappable<decltype(*(boost::declval<T>()))>));
    }
};

/** @} */ // end of library_wide_group

/**
 * @defgroup iterator_group Iterator Requirements
 * @{
 */
/**
 * @class stl_concept::Iterator
 * @brief Describes types that can be used to identify and traverse the elements of a container.
 *
 * <p>
 * <i>Iterator</i> is the base set of requirements used by other iterator types: <i>InputIterator</i>,
 * <i>OutputIterator</i>, <i>ForwardIterator</i>, <i>BidirectionalIterator</i>, and <i>RandomAccessIterator</i>.
 * <i>Iterator</i>s can be thought of as an abstraction of pointers.
 * <br/>
 * <b>Requirements</b>
 * The type It satisfies <i>Iterator</i> if<br/>
 * <ul style="list-style-type:disc">
 *   <li>The type It satisfies <i>CopyConstructible</i>, and</li>
 *   <li>The type It satisfies <i>CopyAssignable</i>, and</li>
 *   <li>The type It satisfies <i>Destructible</i>, and</li>
 *   <li>lvalues of type It satisfy <i>Swappable</i>, and</li>
 *   <li>std::iterator_traits<It> has member typedefs value_type, difference_type, reference, pointer, and
 *       iterator_category , and</li>
 * </ul>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>r, an lvalue of type It.</li>
 * </ul>
 * The following expressions must be valid and have their specified effects
 * <table>
 *   <tr><th>Expression<th>Return Type<th>Precondition
 *   <tr><td>*r        <td>unspecified<td>r is dereferenceable
 *   <tr><td>++r       <td>It&        <td>r is incrementable (the behavior of the expression ++r is defined)
 * </table>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/Iterator
 */
BOOST_concept(Iterator, (It))
    : CopyConstructible<It>
    , CopyAssignable<It>
    , Destructible<It>
    , Swappable<It>
{
    BOOST_CONCEPT_USAGE(Iterator)
    {
        It r(it_);
        __detail::__ignore_unused_variable_warning(*r);
        __detail::__require_exact_type<decltype(++r), It&>();
    }

private:
    typedef typename boost::iterator_value<It>::type value_type;
    typedef typename boost::iterator_difference<It>::type difference_type;
    typedef typename boost::iterator_reference<It>::type reference_type;
    typedef typename boost::iterator_pointer<It>::type pointer_type;
    typedef typename boost::iterator_category<It>::type iterator_category;

    It it_;
};

/** @} */ // end of iterator_group

} // namespace concepts

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_HPP__
