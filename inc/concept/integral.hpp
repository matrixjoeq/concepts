/** @file */
#ifndef __STL_CONCEPT_INTEGRAL_HPP__
#define __STL_CONCEPT_INTEGRAL_HPP__

#include <boost/static_assert.hpp>
#include <boost/type_traits/is_integral.hpp>
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
 * @struct stl_concept::Integral
 * @brief Specifies that an instance of the type is an integral.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type T satisfies <i>Integral</i> if and only if boost::is_integral<T>::value is true.
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/experimental/ranges/concepts/Integral
 */
#ifdef DOXYGEN_WORKING
template <typename T> struct Integral {};
#else // DOXYGEN_WORKING
BOOST_concept(Integral, (T))
{
    BOOST_CONCEPT_USAGE(Integral)
    {
        BOOST_STATIC_ASSERT_MSG(boost::is_integral<T>::value, "T must be an integral type");
    }
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_INTEGRAL_HPP__
