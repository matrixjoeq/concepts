
#ifndef __STL_CONCEPT_DETAIL_REQUIRE_EXPR_CONVERTIBLE_TO_HPP__
#define __STL_CONCEPT_DETAIL_REQUIRE_EXPR_CONVERTIBLE_TO_HPP__

#include "concept/detail/unuse.hpp"

namespace stl_concept {
namespace __detail {

template <class To, class From>
inline void __require_expr_convertible_to(const From& x)
{
    To y = x;
    __unuse(y);
}

} // namespace __detail
} // namespace stl_concept

#endif  // __STL_CONCEPT_DETAIL_REQUIRE_EXPR_CONVERTIBLE_TO_HPP__
