/** @file */
#ifndef __STL_CONCEPT_MOVABLE_HPP__
#define __STL_CONCEPT_MOVABLE_HPP__

#include "concept/object.hpp"
#include "concept/move_constructible.hpp"
#include "concept/move_assignable.hpp"
#include "concept/swappable.hpp"
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
 * @struct Movable
 * @brief Specifies that T is an object type that can moved (i.e. it can be move constructed, move assigned, and lvalues
 * of type T can be swapped).
 *
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/concepts/Movable
 */
#ifdef DOXYGEN_WORKING
template <typename T> struct Movable : Object<T>, MoveConstructible<T>, MoveAssignable<T>, Swappable<T> {};
#else // DOXYGEN_WORKING
BOOST_concept(Movable, (T)) : Object<T>, MoveConstructible<T>, MoveAssignable<T>, Swappable<T> {};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_MOVABLE_HPP__
