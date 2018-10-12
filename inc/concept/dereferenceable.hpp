/** @file */
#ifndef __STL_CONCEPT_DEREFERENCEABLE_HPP__
#define __STL_CONCEPT_DEREFERENCEABLE_HPP__

#include <boost/type_traits/declval.hpp>
#include <boost/concept/usage.hpp>
#include <boost/concept/detail/concept_def.hpp>
#include "concept/detail/unuse.hpp"

#if (defined _MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4197) // topmost volatile ignored
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // object 'class' can never be instantiated - user-defined constructor required
#endif

namespace stl_concept {

/**
 * @addtogroup core_group Core Language Concepts
 * @struct Dereferenceable
 * @brief Specifies that T is an object of operator* applicable.
 *
 * @tparam T - type to be checked
 */
#ifdef DOXYGEN_WORKING
template <typename T> struct Dereferenceable {};
#else // DOXYGEN_WORKING
BOOST_concept(Dereferenceable, (T))
{
    BOOST_CONCEPT_USAGE(Dereferenceable)
    {
        T t = boost::declval<T>();
        __detail::__unuse(*t);
    }
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_DEREFERENCEABLE_HPP__
