/** @file */
#ifndef __STL_CONCEPT_SAME_HPP__
#define __STL_CONCEPT_SAME_HPP__

#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
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
 * @struct stl_concept::Same
 * @brief Specifies that type T and type U denote the same type.
 *
 * @tparam T - first type to be checked
 * @tparam U - second type to be checked
 * @see https://en.cppreference.com/w/cpp/concepts/Same
 */
#ifdef DOXYGEN_WORKING
template <typename T> struct Same {};
#else // DOXYGEN_WORKING
BOOST_concept(Same, (T)(U))
{
    BOOST_CONCEPT_USAGE(Same)
    {
        BOOST_STATIC_ASSERT_MSG(boost::is_same<U, T>::value, "T and U must be the same type");
    }
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_SAME_HPP__
