/** @file */
#ifndef __STL_CONCEPT_REGULAR_HPP__
#define __STL_CONCEPT_REGULAR_HPP__

#include "concept/equality_comparable.hpp"
#include "concept/semiregular.hpp"
#include <boost/concept/detail/concept_def.hpp>

#if (defined _MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4197) // topmost volatile ignored
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // object 'class' can never be instantiated - user-defined constructor required
#endif

namespace stl_concept {

/**
 * @addtogroup object_group Object Concepts
 * @struct Regular
 * @brief Specifies that a type is both regular and equality comparable.
 *
 * <p>
 * It is satisfied by types that behave similarly to built-in types like int, and that are comparable with ==.
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/concepts/Regular
 */
#ifdef DOXYGEN_WORKING
template <typename T> struct Regular : Semiregular<T>, EqualityComparable<T> {};
#else // DOXYGEN_WORKING
BOOST_concept(Regular, (T)) : Semiregular<T>, EqualityComparable<T> {};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_REGULAR_HPP__
