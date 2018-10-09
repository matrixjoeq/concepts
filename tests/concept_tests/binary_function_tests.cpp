
#include <functional>
#include "util.h"
#include "concept/binary_function.hpp"

namespace stl_concept {
namespace test {
namespace {

using FirstType = int;
using SecondType = int;
using ReturnType = int;
using VoidType = void;

struct Func
{
    ReturnType func(FirstType, SecondType)
    {
        return ReturnType();
    }
};

struct VoidFunc
{
    VoidType void_func(FirstType, SecondType)
    {}
};

ReturnType func(FirstType, SecondType)
{
    return ReturnType();
}

VoidType void_func(FirstType, SecondType)
{}

struct Functor
{
    Functor() = delete;

    ReturnType operator()(FirstType, SecondType)
    {
        return ReturnType();
    }
};

struct VoidFunctor
{
    VoidFunctor() = delete;

    VoidType operator()(FirstType, SecondType)
    {}
};

using FunctionTL = mpl::vector<
    mpl::vector<ReturnType(*)(FirstType, SecondType), ReturnType, FirstType, SecondType>,
    mpl::vector<VoidType(*)(FirstType, SecondType), VoidType, FirstType, SecondType>,
    mpl::vector<ReturnType(* const)(FirstType, SecondType), ReturnType, FirstType, SecondType>,
    mpl::vector<VoidType(* const)(FirstType, SecondType), VoidType, FirstType, SecondType>,
    mpl::vector<std::function<ReturnType(FirstType, SecondType)>, ReturnType, FirstType, SecondType>,
    mpl::vector<std::function<ReturnType(FirstType, SecondType)> const, ReturnType, FirstType, SecondType>,
    mpl::vector<std::function<VoidType(FirstType, SecondType)>, VoidType, FirstType, SecondType>,
    mpl::vector<std::function<VoidType(FirstType, SecondType)> const, VoidType, FirstType, SecondType>
>;

struct ConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        using _FuncType = typename mpl::at<T, mpl::int_<0>>::type;
        using _ReturnType = typename mpl::at<T, mpl::int_<1>>::type;
        using _FirstType = typename mpl::at<T, mpl::int_<2>>::type;
        using _SecondType = typename mpl::at<T, mpl::int_<3>>::type;
        BOOST_CONCEPT_ASSERT((boost::BinaryFunction<_FuncType, _ReturnType, _FirstType, _SecondType>));
        BOOST_CONCEPT_ASSERT((stl_concept::BinaryFunction<_FuncType, _FirstType, _SecondType>));
    }
};

} // namespace

void binary_function_check()
{
    using namespace std::placeholders;

    Func f;
    (void)(f.func(0, 0));

    VoidFunc vf;
    vf.void_func(0, 0);

    (void)(func(0, 0));
    void_func(0, 0);

    BOOST_CONCEPT_ASSERT((boost::BinaryFunction<Functor, ReturnType, FirstType, SecondType>));
    BOOST_CONCEPT_ASSERT((stl_concept::BinaryFunction<Functor, FirstType, SecondType>));

    BOOST_CONCEPT_ASSERT((boost::BinaryFunction<VoidFunctor, VoidType, FirstType, SecondType>));
    BOOST_CONCEPT_ASSERT((stl_concept::BinaryFunction<VoidFunctor, FirstType, SecondType>));

    BOOST_CONCEPT_ASSERT((boost::BinaryFunction<decltype(std::bind(func, _1, _2)), ReturnType, FirstType, SecondType>));
    BOOST_CONCEPT_ASSERT((stl_concept::BinaryFunction<decltype(std::bind(func, _1, _2)), FirstType, SecondType>));

    BOOST_CONCEPT_ASSERT((boost::BinaryFunction<decltype(std::bind(void_func, _1, _2)), VoidType, FirstType, SecondType>));
    BOOST_CONCEPT_ASSERT((stl_concept::BinaryFunction<decltype(std::bind(void_func, _1, _2)), FirstType, SecondType>));

    BOOST_CONCEPT_ASSERT((boost::BinaryFunction<decltype(std::bind(&Func::func, &f, _1, _2)), ReturnType, FirstType, SecondType>));
    BOOST_CONCEPT_ASSERT((stl_concept::BinaryFunction<decltype(std::bind(&Func::func, &f, _1, _2)), FirstType, SecondType>));

    BOOST_CONCEPT_ASSERT((boost::BinaryFunction<decltype(std::bind(&VoidFunc::void_func, &vf, _1, _2)), VoidType, FirstType, SecondType>));
    BOOST_CONCEPT_ASSERT((stl_concept::BinaryFunction<decltype(std::bind(&VoidFunc::void_func, &vf, _1, _2)), FirstType, SecondType>));

    mpl::for_each<FunctionTL>(ConceptChecker());
}

} // namespace test
} // namespace stl_concept
