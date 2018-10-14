
#include <functional>
#include "util.h"
#include "concept/function_object.hpp"

namespace stl_concept {
namespace test {
namespace {

using UnaryFunctorTL = mpl::vector<
    mpl::vector<void(*)(int), int>,
    mpl::vector<void(* const)(int), int>,
    mpl::vector<std::function<void(int)>, int>
>;

using BinaryFunctorTL = mpl::vector<
    mpl::vector<void(*)(int, long), int, long>,
    mpl::vector<void(* const)(int, long), int, long>,
    mpl::vector<std::function<void(int, long)>, int, long>
>;

struct UnaryConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        using _FunctorType = typename mpl::at<T, mpl::int_<0>>::type;
        using _ArgType = typename mpl::at<T, mpl::int_<1>>::type;
        BOOST_CONCEPT_ASSERT((stl_concept::FunctionObject<_FunctorType, _ArgType>));
    }
};

struct BinaryConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        using _FunctorType = typename mpl::at<T, mpl::int_<0>>::type;
        using _FirstType = typename mpl::at<T, mpl::int_<1>>::type;
        using _SecondType = typename mpl::at<T, mpl::int_<2>>::type;
        BOOST_CONCEPT_ASSERT((stl_concept::FunctionObject<_FunctorType, _FirstType, _SecondType>));
    }
};

} // namespace

void function_object_check()
{
    mpl::for_each<UnaryFunctorTL>(UnaryConceptChecker());
    mpl::for_each<BinaryFunctorTL>(BinaryConceptChecker());
}

} // namespace test
} // namespace stl_concept