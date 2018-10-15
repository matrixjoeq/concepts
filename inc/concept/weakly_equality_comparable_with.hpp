/** @file */
#ifndef __STL_CONCEPT_WEAKLY_EQUALITY_COMPARABLE_WITH_HPP__
#define __STL_CONCEPT_WEAKLY_EQUALITY_COMPARABLE_WITH_HPP__

#include "concept/convertible_to.hpp"
#include <boost/type_traits/declval.hpp>
#include <boost/type_traits/remove_reference.hpp>
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
 * @struct WeaklyEqualityComparableWith
 * @brief Specifies that an object of type T and an object of type U can be compared for equality with each other
 * (in either order) using both == and !=, and the results of the comparisons are consistent.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type T and U satisfies <i>WeaklyEqualityComparableWith</i> if<br/>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>t, an lvalue of type const std::remove_reference_t<T> and,</li>
 *   <li>u, an lvalue of type const std::remove_reference_t<U></li>
 * </ul>
 * the following are true:
 * <ul style="list-style-type:disc">
 *   <li>t == u, u == t, t != u,u != t have the same domain</li>
 *   <li>bool(u == t) == bool(t == u)</li>
 *   <li>bool(t != u) == !bool(t == u)</li>
 *   <li>bool(u != t) == bool(t != u)</li>
 * </ul>
 * </p>
 * @tparam T - first type to be weakly equal compared
 * @tparam U - second type to be weakly equal compared
 * @see https://en.cppreference.com/w/cpp/experimental/ranges/concepts/WeaklyEqualityComparableWith
 */
#ifdef DOXYGEN_WORKING
template <typename T, typename U> struct WeaklyEqualityComparableWith {};
#else // DOXYGEN_WORKING
BOOST_concept(WeaklyEqualityComparableWith, (T)(U))
{
    BOOST_CONCEPT_USAGE(WeaklyEqualityComparableWith)
    {
        equality_constraints(boost::declval<_Tp&>(), boost::declval<_Up&>());
    }

private:
    using _Tp = boost::remove_reference_t<T>;
    using _Up = boost::remove_reference_t<U>;

    void equality_constraints(const _Tp& t, const _Up& u)
    {
        __detail::__unuse(t);
        __detail::__unuse(u);
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(t == u), bool>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(t != u), bool>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(u == t), bool>));
        BOOST_CONCEPT_ASSERT((ConvertibleTo<decltype(u != t), bool>));
    }
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_WEAKLY_EQUALITY_COMPARABLE_WITH_HPP__
