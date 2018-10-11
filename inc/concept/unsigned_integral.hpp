/** @file */
#ifndef __STL_CONCEPT_UNSIGNED_INTEGRAL_HPP__
#define __STL_CONCEPT_UNSIGNED_INTEGRAL_HPP__

#include "concept/integral.hpp"
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_unsigned.hpp>
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
 * @addtogroup integral_group Integral Requirements
 * @struct stl_concept::UnsignedIntegral
 * @brief Specifies that an instance of the type is a signed integral.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type T satisfies <i>UnsignedIntegral</i> if and only if
 * <ul style="list-style-type:disc">
 *   <li>The type T satisfies <i>Integral</i>, and</li>
 *   <li>The type T makes boost::is_unsigned<T>::value positive</li>
 * </ul>
  * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/experimental/ranges/concepts/UnsignedIntegral
 */
#ifdef DOXYGEN_WORKING
template <typename T> struct UnsignedIntegral : Integral<T> {};
#else // DOXYGEN_WORKING
BOOST_concept(UnsignedIntegral, (T)) : Integral<T>
{
    BOOST_CONCEPT_USAGE(UnsignedIntegral)
    {
        BOOST_STATIC_ASSERT_MSG(boost::is_unsigned<T>::value, "T must be an unsigned integral type");
    }
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_UNSIGNED_INTEGRAL_HPP__
