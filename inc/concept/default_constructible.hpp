
#ifndef __STL_CONCEPT_DEFAULT_CONSTRUCTIBLE_HPP__
#define __STL_CONCEPT_DEFAULT_CONSTRUCTIBLE_HPP__

#include <boost/concept/assert.hpp>
#include <boost/concept/usage.hpp>
#include <boost/concept/detail/concept_def.hpp>

#include "concept/detail/unuse.hpp"

#if (defined _MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // object 'class' can never be instantiated - user-defined constructor required
#endif

namespace stl_concept {

/**
 * @addtogroup basic_group Basic Requirements
 * @class stl_concept::DefaultConstructible
 * @brief Specifies that an instance of the type can be default constructed.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
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
        __detail::__unuse(u);
        __detail::__unuse(T());

        T v{};
        __detail::__unuse(v);
        __detail::__unuse(T{});
    }
};

template <class T, size_t N>
struct DefaultConstructible<T[N]>
{
    BOOST_CONCEPT_USAGE(DefaultConstructible)
    {
        BOOST_CONCEPT_ASSERT((DefaultConstructible<T>));
    }
};

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_DEFAULT_CONSTRUCTIBLE_HPP__
