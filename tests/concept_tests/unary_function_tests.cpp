
#include <functional>
#include "util.h"
#include "concept/unary_function.hpp"

namespace stl_concept {
namespace test {
namespace {

using ArgType = int;
using ReturnType = int;
using VoidType = void;

struct Func
{
    ReturnType func(ArgType)
    {
        return ReturnType();
    }
};

struct VoidFunc
{
    VoidType void_func(ArgType)
    {}
};

ReturnType func(ArgType)
{
    return ReturnType();
}

VoidType void_func(ArgType)
{}

struct Functor
{
    Functor() = delete;

    ReturnType operator()(ArgType)
    {
        return ReturnType();
    }
};

struct VoidFunctor
{
    VoidFunctor() = delete;

    VoidType operator()(ArgType)
    {}
};

using FunctionTL = mpl::vector<
    mpl::vector<ReturnType(*)(ArgType), ReturnType, ArgType>,
    mpl::vector<VoidType(*)(ArgType), VoidType, ArgType>,
    mpl::vector<ReturnType(* const)(ArgType), ReturnType, ArgType>,
    mpl::vector<VoidType(* const)(ArgType), VoidType, ArgType>,
    mpl::vector<std::function<ReturnType(ArgType)>, ReturnType, ArgType>,
    mpl::vector<std::function<ReturnType(ArgType)> const, ReturnType, ArgType>,
    mpl::vector<std::function<VoidType(ArgType)>, VoidType, ArgType>,
    mpl::vector<std::function<VoidType(ArgType)> const, VoidType, ArgType>
>;

struct ConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        using _FuncType = typename mpl::at<T, mpl::int_<0>>::type;
        using _ReturnType = typename mpl::at<T, mpl::int_<1>>::type;
        using _ArgType = typename mpl::at<T, mpl::int_<2>>::type;
        BOOST_CONCEPT_ASSERT((boost::UnaryFunction<_FuncType, _ReturnType, _ArgType>));
        BOOST_CONCEPT_ASSERT((stl_concept::UnaryFunction<_FuncType, _ReturnType, _ArgType>));
    }
};

} // namespace

void unary_function_check()
{
    using namespace std::placeholders;

    Func f;
    (void)(f.func(0));

    VoidFunc vf;
    vf.void_func(0);

    (void)(func(0));
    void_func(0);

    BOOST_CONCEPT_ASSERT((boost::UnaryFunction<Functor, ReturnType, ArgType>));
    BOOST_CONCEPT_ASSERT((stl_concept::UnaryFunction<Functor, ReturnType, ArgType>));

    BOOST_CONCEPT_ASSERT((boost::UnaryFunction<VoidFunctor, VoidType, ArgType>));
    BOOST_CONCEPT_ASSERT((stl_concept::UnaryFunction<VoidFunctor, VoidType, ArgType>));

    BOOST_CONCEPT_ASSERT((boost::UnaryFunction<decltype(std::bind(func, _1)), ReturnType, ArgType>));
    BOOST_CONCEPT_ASSERT((stl_concept::UnaryFunction<decltype(std::bind(func, _1)), ReturnType, ArgType>));

    BOOST_CONCEPT_ASSERT((boost::UnaryFunction<decltype(std::bind(void_func, _1)), VoidType, ArgType>));
    BOOST_CONCEPT_ASSERT((stl_concept::UnaryFunction<decltype(std::bind(void_func, _1)), VoidType, ArgType>));

    BOOST_CONCEPT_ASSERT((boost::UnaryFunction<decltype(std::bind(&Func::func, &f, _1)), ReturnType, ArgType>));
    BOOST_CONCEPT_ASSERT((stl_concept::UnaryFunction<decltype(std::bind(&Func::func, &f, _1)), ReturnType, ArgType>));

    BOOST_CONCEPT_ASSERT((boost::UnaryFunction<decltype(std::bind(&VoidFunc::void_func, &vf, _1)), VoidType, ArgType>));
    BOOST_CONCEPT_ASSERT((stl_concept::UnaryFunction<decltype(std::bind(&VoidFunc::void_func, &vf, _1)), VoidType, ArgType>));

    mpl::for_each<FunctionTL>(ConceptChecker());
}

} // namespace test
} // namespace stl_concept
