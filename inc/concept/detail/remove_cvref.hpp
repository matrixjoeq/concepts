/** @file */
#ifndef __STL_CONCEPT_DETAIL_REMOVE_CVREF_HPP__
#define __STL_CONCEPT_DETAIL_REMOVE_CVREF_HPP__

#include <type_traits>

namespace stl_concept {
namespace __detail {

/// @cond DEV
/**
 * @brief If the type T is a reference type, provides the member alias type
 *        which is the type referred to by T with its topmost cv-qualifiers
 *        removed. Otherwise type is T with its topmost cv-qualifiers removed.
 * @tparam T - object type
 */
template <typename T>
struct __remove_cvref
{
    using type = typename std::remove_cv<
        typename std::remove_reference<T>::type
    >::type;
};

/**
 * @brief Helper type of remove cv qualifier and reference
 */
template <typename T>
using __remove_cvref_t = typename __remove_cvref<T>::type;

/// @endcond

} // namespace __detail
} // namespace stl_concept

#endif // __STL_CONCEPT_DETAIL_REMOVE_CVREF_HPP__
