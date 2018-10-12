/** @file */
#ifndef __STL_CONCEPT_COPYABLE_HPP__
#define __STL_CONCEPT_COPYABLE_HPP__

#include "concept/copy_constructible.hpp"
#include "concept/copy_assignable.hpp"
#include "concept/movable.hpp"
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
 * @struct Copyable
 * @brief Specifies that T is an <i>Movable</i> object type that can also copied (i.e. it supports copy construction and
 * copy assignment).
 *
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/concepts/Copyable
 */
#ifdef DOXYGEN_WORKING
template <typename T> struct Copyable : Movable<T>, CopyConstructible<T>, CopyAssignable<T> {};
#else // DOXYGEN_WORKING
BOOST_concept(Copyable, (T)) : Movable<T>, CopyConstructible<T>, CopyAssignable<T> {};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_COPYABLE_HPP__
