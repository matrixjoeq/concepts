/** @file */
#ifndef __STL_CONCEPT_DETAIL_REQUIRE_EXPR_CONVERTIBLE_TO_HPP__
#define __STL_CONCEPT_DETAIL_REQUIRE_EXPR_CONVERTIBLE_TO_HPP__

#include "concept/detail/unuse.hpp"

namespace stl_concept {
namespace __detail {

/// @cond DEV
/**
 * @brief Specifies type From can be converted to type To.
 * @tparam To - type to be converted to
 * @tparam From - type to be converted from
 * @param x - object to be converted
 */
template <class To, class From>
inline void __require_expr_convertible_to(const From& x)
{
    To y = x;
    __unuse(y);
}
/// @endcond

} // namespace __detail
} // namespace stl_concept

#endif  // __STL_CONCEPT_DETAIL_REQUIRE_EXPR_CONVERTIBLE_TO_HPP__
