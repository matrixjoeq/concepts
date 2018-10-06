
#ifndef __STL_CONCEPT_DETAIL_REFERENCEABLE_HPP__
#define __STL_CONCEPT_DETAIL_REFERENCEABLE_HPP__

#include <boost/type_traits/remove_cv_ref.hpp>
#include <boost/concept/usage.hpp>
#include <boost/concept/detail/concept_def.hpp>

#if (defined _MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // object 'class' can never be instantiated - user-defined constructor required
#endif

namespace stl_concept {
namespace __detail {

BOOST_concept(__Referenceable, (T))
{
    BOOST_CONCEPT_USAGE(__Referenceable)
    {
        _Tp& r = t_;
        __detail::__unuse(r);
    }

private:
    typedef typename boost::remove_cv_ref<T>::type _Tp;
    _Tp t_;
};

template <class T> struct __Referenceable<T[]> {};
template <class T, size_t N> struct __Referenceable<T[N]> {};
template <class R, class... Args> struct __Referenceable<R(Args...)> {};

} // namespace __detail
} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_DETAIL_REFERENCEABLE_HPP__
