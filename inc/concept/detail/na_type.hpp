
#ifndef __STL_CONCEPT_DETAIL_NA_TYPE_HPP__
#define __STL_CONCEPT_DETAIL_NA_TYPE_HPP__

namespace stl_concept {
namespace __detail {

struct __na_type
{
    __na_type() = delete;
    __na_type(const __na_type&) = delete;
    __na_type& operator=(const __na_type&) = delete;
    ~__na_type() = delete;
};

} // namespace __detail
} // namespace stl_concept

#endif  // __STL_CONCEPT_DETAIL_NA_TYPE_HPP__
