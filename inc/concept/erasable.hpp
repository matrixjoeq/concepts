/** @file */
#ifndef __STL_CONCEPT_ERASABLE_HPP__
#define __STL_CONCEPT_ERASABLE_HPP__

#include "concept/same.hpp"
#include <memory>
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
 * @struct Erasable
 * @brief Specifies that an object of the type can be destroyed by a given Allocator.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type T is <i>Erasable</i> into the <i>Container</i> X whose value_type is identical to T if<br/>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>A, an allocator type</li>
 *   <li>m, an lvalue of type A</li>
 *   <li>p, the pointer of type T* prepared by the container</li>
 * </ul>
 * where X::allocator_type is identical to boost::allocator_traits<A>::rebind_alloc<T>, the following expression is
 * well-formed:
 * ```
 * boost::allocator_traits<A>::destroy(m, p);
 * ```
 * If X is not allocator-aware, the term is defined as if A were std::allocator<T>, except that no allocator object
 * needs to be created, and user-defined specializations of std::allocator are not instantiated.
 * </p>
 * @tparam T - value type
 * @tparam X - container type
 * @see https://en.cppreference.com/w/cpp/named_req/Erasable
 */
#ifdef DOXYGEN_WORKING
template <typename T, typename X>
struct Erasable {};
#else // DOXYGEN_WORKING
BOOST_concept(Erasable, (T)(X))
{
    BOOST_CONCEPT_USAGE(Erasable)
    {
        BOOST_CONCEPT_ASSERT((Same<T, __ValueType>));
        using __RebindAllocType =
            typename std::allocator_traits<__AllocatorType>::template rebind_alloc<T>;

        BOOST_CONCEPT_ASSERT((Same<__RebindAllocType, __AllocatorType>));
        std::allocator_traits<__AllocatorType>::destroy(alloc_, pointer_);
    }

private:
    template <typename C, typename = typename C::allocator_type>
    static typename C::allocator_type get_allocator_type(int);

    template <typename C>
    static std::allocator<T> get_allocator_type(...);

    using __ValueType = typename X::value_type;
    using __AllocatorType = decltype(get_allocator_type<X>(0));
    __AllocatorType alloc_;
    T* pointer_;
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_ERASABLE_HPP__
