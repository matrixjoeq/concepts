/** @file */
#ifndef __STL_CONCEPT_OBJECT_HPP__
#define __STL_CONCEPT_OBJECT_HPP__

#include <boost/static_assert.hpp>
#include <boost/type_traits/is_object.hpp>
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
 * @addtogroup object_group Object Concepts
 * @struct stl_concept::Object
 * @brief Specifies that T is an object type.
 *
 * @tparam T - type to be checked
 */
#ifdef DOXYGEN_WORKING
template <typename T> struct Object {};
#else // DOXYGEN_WORKING
BOOST_concept(Object, (T))
{
    BOOST_CONCEPT_USAGE(Object)
    {
        BOOST_STATIC_ASSERT_MSG(boost::is_object<T>::value, "T must be an object");
    }
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_OBJECT_HPP__
