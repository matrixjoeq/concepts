/** @file */
#ifndef __STL_CONCEPT_DERIVED_FROM_HPP__
#define __STL_CONCEPT_DERIVED_FROM_HPP__

#include <type_traits>
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
 * @addtogroup core_group Core Language Concepts
 * @struct DerivedFrom
 * @brief Specifies that type U is a class type that is either T or a public and unambiguous base of T.
 *
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/concepts/DerivedFrom
 */
#ifdef DOXYGEN_WORKING
template <typename T>
struct DerivedFrom {};
#else // DOXYGEN_WORKING
BOOST_concept(DerivedFrom, (T)(U))
{
    BOOST_CONCEPT_USAGE(DerivedFrom)
    {
        static_assert(
            std::is_base_of<U, T>::value,
            "U must be the base of T");

        static_assert(
            std::is_convertible<
                typename std::remove_cv<T>::type*,
                typename std::remove_cv<U>::type*>::value,
            "T* must be convertible to U*");
    }
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_DERIVED_FROM_HPP__
