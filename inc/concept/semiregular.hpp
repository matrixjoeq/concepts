/** @file */
#ifndef __STL_CONCEPT_SEMIREGULAR_HPP__
#define __STL_CONCEPT_SEMIREGULAR_HPP__

#include "concept/default_constructible.hpp"
#include "concept/copyable.hpp"
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
 * @struct stl_concept::Semiregular
 * @brief Specifies that a type is both copyable and default constructible.
 *
 * <p>
 * It is satisfied by types that behave similarly to built-in types like int, except that they need not support
 * comparison with ==.
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/concepts/Semiregular
 */
#ifdef DOXYGEN_WORKING
template <typename T> struct Semiregular : Copyable<T>, DefaultConstructible<T> {};
#else // DOXYGEN_WORKING
BOOST_concept(Semiregular, (T)) : Copyable<T>, DefaultConstructible<T> {};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_SEMIREGULAR_HPP__
