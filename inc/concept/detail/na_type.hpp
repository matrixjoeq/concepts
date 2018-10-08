/** @file */
#ifndef __STL_CONCEPT_DETAIL_NA_TYPE_HPP__
#define __STL_CONCEPT_DETAIL_NA_TYPE_HPP__

namespace stl_concept {
namespace __detail {

/// @cond DEV
/**
 * @struct stl_concept::__detail::__na_type
 * @brief Not available type for internal use.
 */
struct __na_type
{
    __na_type() = delete;
    __na_type(const __na_type&) = delete;
    __na_type& operator=(const __na_type&) = delete;
    __na_type(__na_type&&) = delete;
    __na_type& operator=(__na_type&&) = delete;
    ~__na_type() = delete;
};
/// @endcond

} // namespace __detail
} // namespace stl_concept

#endif  // __STL_CONCEPT_DETAIL_NA_TYPE_HPP__
