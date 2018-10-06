#ifndef __STL_CONCEPT_DETAIL_UNUSE_HPP__
#define __STL_CONCEPT_DETAIL_UNUSE_HPP__

namespace stl_concept {
namespace __detail {

template <class T>
inline void __unuse(T&&) {}

} // namespace __detail
} // namespace stl_concept

#endif // __STL_CONCEPT_DETAIL_UNUSE_HPP__
