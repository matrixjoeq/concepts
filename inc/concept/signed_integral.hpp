/** @file */
#ifndef __STL_CONCEPT_SIGNED_INTEGRAL_HPP__
#define __STL_CONCEPT_SIGNED_INTEGRAL_HPP__

#include "concept/integral.hpp"
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_signed.hpp>
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
 * @addtogroup core_group Core Language Requirements
 * @struct stl_concept::SignedIntegral
 * @brief Specifies that an instance of the type is a signed integral.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type T satisfies <i>SignedIntegral</i> if and only if
 * <ul style="list-style-type:disc">
 *   <li>The type T satisfies <i>Integral</i>, and</li>
 *   <li>The type T makes boost::is_signed<T>::value positive</li>
 * </ul>
  * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/experimental/ranges/concepts/SignedIntegral
 */
#ifdef DOXYGEN_WORKING
template <typename T> struct SignedIntegral : Integral<T> {};
#else // DOXYGEN_WORKING
BOOST_concept(SignedIntegral, (T)) : Integral<T>
{
    BOOST_CONCEPT_USAGE(SignedIntegral)
    {
        BOOST_STATIC_ASSERT_MSG(boost::is_signed<T>::value, "T must be a signed integral type");
    }
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_SIGNED_INTEGRAL_HPP__
