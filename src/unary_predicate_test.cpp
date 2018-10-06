
#include <functional>
#include "util.h"
#include "concept/unary_predicate.hpp"

namespace stl_concept {
namespace test {
namespace {

using ArgType = int;

struct Predicator
{
    bool predicate(ArgType)
    {
        return true;
    }
};

bool predicate_func(ArgType)
{
    return true;
}

struct PredicateFunctor
{
    PredicateFunctor() = delete;

    bool operator()(ArgType)
    {
        return true;
    }
};

using PredicateTL = mpl::vector<
    bool(*)(ArgType),
    bool(* const)(ArgType),
    std::function<bool(ArgType)>,
    std::function<bool(ArgType)> const
>;

struct ConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        BOOST_CONCEPT_ASSERT((boost::UnaryPredicate<T, ArgType>));
        BOOST_CONCEPT_ASSERT((stl_concept::UnaryPredicate<T, ArgType>));
    }
};

} // namespace

void unary_predicate_check()
{
    using namespace std::placeholders;

    Predicator pred;
    (void)(pred.predicate(0));
    (void)(predicate_func(0));

    BOOST_CONCEPT_ASSERT((boost::UnaryPredicate<PredicateFunctor, ArgType>));
    BOOST_CONCEPT_ASSERT((stl_concept::UnaryPredicate<PredicateFunctor, ArgType>));

    BOOST_CONCEPT_ASSERT((boost::UnaryPredicate<decltype(std::bind(predicate_func, _1)), ArgType>));
    BOOST_CONCEPT_ASSERT((stl_concept::UnaryPredicate<decltype(std::bind(predicate_func, _1)), ArgType>));

    BOOST_CONCEPT_ASSERT((boost::UnaryPredicate<decltype(std::bind(&Predicator::predicate, &pred, _1)), ArgType>));
    BOOST_CONCEPT_ASSERT((stl_concept::UnaryPredicate<decltype(std::bind(&Predicator::predicate, &pred, _1)), ArgType>));

    mpl::for_each<PredicateTL>(ConceptChecker());
}

} // namespace test
} // namespace stl_concept
