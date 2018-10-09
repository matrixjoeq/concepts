
#include <functional>
#include "util.h"
#include "concept/binary_predicate.hpp"

namespace stl_concept {
namespace test {
namespace {

using FirstType = int;
using SecondType = int;

struct Predicator
{
    bool predicate(FirstType, SecondType)
    {
        return true;
    }
};

bool predicate_func(FirstType, SecondType)
{
    return true;
}

struct PredicateFunctor
{
    PredicateFunctor() = delete;

    bool operator()(FirstType, SecondType)
    {
        return true;
    }
};

using PredicateTL = mpl::vector<
    bool(*)(FirstType, SecondType),
    bool(* const)(FirstType, SecondType),
    std::function<bool(FirstType, SecondType)>,
    std::function<bool(FirstType, SecondType)> const
>;

struct ConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        BOOST_CONCEPT_ASSERT((boost::BinaryPredicate<T, FirstType, SecondType>));
        BOOST_CONCEPT_ASSERT((stl_concept::BinaryPredicate<T, FirstType, SecondType>));
    }
};

} // namespace

void binary_predicate_check()
{
    using namespace std::placeholders;

    Predicator pred;
    (void)(pred.predicate(0, 0));
    (void)(predicate_func(0, 0));

    BOOST_CONCEPT_ASSERT((boost::BinaryPredicate<PredicateFunctor, FirstType, SecondType>));
    BOOST_CONCEPT_ASSERT((stl_concept::BinaryPredicate<PredicateFunctor, FirstType, SecondType>));

    BOOST_CONCEPT_ASSERT((boost::BinaryPredicate<decltype(std::bind(predicate_func, _1, _2)), FirstType, SecondType>));
    BOOST_CONCEPT_ASSERT((stl_concept::BinaryPredicate<decltype(std::bind(predicate_func, _1, _2)), FirstType, SecondType>));

    BOOST_CONCEPT_ASSERT((boost::BinaryPredicate<decltype(std::bind(&Predicator::predicate, &pred, _1, _2)), FirstType, SecondType>));
    BOOST_CONCEPT_ASSERT((stl_concept::BinaryPredicate<decltype(std::bind(&Predicator::predicate, &pred, _1, _2)), FirstType, SecondType>));

    mpl::for_each<PredicateTL>(ConceptChecker());
}

} // namespace test
} // namespace stl_concept
