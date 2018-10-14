/** @file */
#ifndef __STL_CONCEPT_EMPLACE_INSERTABLE_HPP__
#define __STL_CONCEPT_EMPLACE_INSERTABLE_HPP__

#include "concept/same.hpp"
#include <memory>
#include <boost/container/allocator_traits.hpp>
#include <boost/type_traits/declval.hpp>
#include <boost/concept/assert.hpp>
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
 * @addtogroup container_element_group Container Element Requirements
 * @struct EmplaceInsertable
 * @brief Specifies that an object of the type can be constructed from a given set of arguments in uninitialized storage
 * by a given allocator.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type T is <i>EmplaceConstructible</i> into the <i>Container</i> X (whose value_type is identical to T) from the
 * arguments args if<br/>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>A, an allocator type</li>
 *   <li>m, an lvalue of type A</li>
 *   <li>p, the pointer of type T* prepared by the container</li>
 *   <li>args, zero or more arguments</li>
 * </ul>
 * where X::allocator_type is identical to boost::allocator_traits<A>::rebind_alloc<T>, the following expression is
 * well-formed:
 * ```
 * boost::allocator_traits<A>::construct(m, p, args...);
 * ```
 * If X is not allocator-aware, the term is defined as if A were std::allocator<T>, except that no allocator object
 * needs to be created, and user-defined specializations of std::allocator are not instantiated.
 * </p>
 * @tparam T - value type
 * @tparam X - container type
 * @tparam Args - argument types
 * @see https://en.cppreference.com/w/cpp/named_req/EmplaceInsertable
 */
#ifdef DOXYGEN_WORKING
template <typename T, typename X, typename... Args> struct EmplaceInsertable {};
#else // DOXYGEN_WORKING
template <typename T, typename X, typename... Args>
struct EmplaceInsertable
{
    BOOST_CONCEPT_USAGE(EmplaceInsertable)
    {
        BOOST_CONCEPT_ASSERT((Same<T, _ValueType>));
        using _RebindAllocType = typename boost::container::allocator_traits<_AllocatorType>::template rebind_alloc<T>;
        BOOST_CONCEPT_ASSERT((Same<_RebindAllocType, _AllocatorType>));
        boost::container::allocator_traits<_AllocatorType>::construct(alloc_, pointer_, boost::declval<Args>()...);
    }

private:
    template <typename C, typename = typename C::allocator_type>
    static typename C::allocator_type get_allocator_type(int);

    template <typename C>
    static std::allocator<T> get_allocator_type(...);

    using _ValueType = typename X::value_type;
    using _AllocatorType = decltype(get_allocator_type<X>(0));
    _AllocatorType alloc_;
    T* pointer_;
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_EMPLACE_INSERTABLE_HPP__
