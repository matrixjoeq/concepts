/** @file */
#ifndef __STL_CONCEPT_SWAPPABLE_WITH_HPP__
#define __STL_CONCEPT_SWAPPABLE_WITH_HPP__

#include "concept/referenceable.hpp"
#include <type_traits>
#include <utility>
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
 * @struct SwappableWith
 * @brief Specifies that lvalues of type T and type U are swappable.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type T and type U satisfies <i>SwappableWith</i> if<br/>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>t1 and t2, distinct equal objects of type std::remove_cvref_t<T></li>
 * </ul>
 * <i>SwappableWith</i> is satisfied only if, after evaluating either swap(a1, b1) or swap(b1, a1),
 * a1 is equal to b2 and b1 is equal to a2.
 * </p>
 * @tparam T - first type to be checked
 * @tparam U - second type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/Swappable
 * @see https://en.cppreference.com/w/cpp/concepts/Swappable
 */
#ifdef DOXYGEN_WORKING
template <typename T, typename U>
struct SwappableWith {};
#else // DOXYGEN_WORKING
BOOST_concept(SwappableWith, (T)(U))
{
    BOOST_CONCEPT_USAGE(SwappableWith)
    {
        BOOST_CONCEPT_ASSERT((Referenceable<T>));
        BOOST_CONCEPT_ASSERT((Referenceable<U>));

        swap_constraint<T, T>();
        swap_constraint<T, U>();
        swap_constraint<U, T>();
        swap_constraint<U, U>();
    }

private:
    template <typename _T, typename _U>
    void swap_constraint()
    {
        using std::swap;
        using __Return = decltype(swap(std::declval<_T&>(), std::declval<_U&>()));
        __detail::__Unuse<__Return>();
    }
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_SWAPPABLE_WITH_HPP__
