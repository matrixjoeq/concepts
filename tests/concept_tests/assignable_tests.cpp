
#include <type_traits>
#include "util.h"
#include "concept/assignable.hpp"

namespace stl_concept {
namespace test {
namespace {

using BasicTL = mpl::vector<
    mpl::vector<DefaultType&, DefaultType>,
    mpl::vector<DefaultType&, DefaultType&>,
    mpl::vector<DefaultType&, const DefaultType>,
    mpl::vector<DefaultType&, const DefaultType&>,
    mpl::vector<DefaultType&, DefaultType&&>,
    mpl::vector<DefaultType&, const DefaultType&&>
>;

using PointerTL = mpl::vector<
    mpl::vector<DefaultType*&, DefaultType*>,
    mpl::vector<DefaultType*&, DefaultType*&>,
    mpl::vector<const DefaultType*&, const DefaultType*>,
    mpl::vector<const DefaultType*&, const DefaultType*&>,
    mpl::vector<volatile DefaultType*&, volatile DefaultType*>,
    mpl::vector<volatile DefaultType*&, volatile DefaultType*&>,
    mpl::vector<const volatile DefaultType*&, const volatile DefaultType*>,
    mpl::vector<const volatile DefaultType*&, const volatile DefaultType*&>,
    mpl::vector<DefaultType*&, DefaultType*&&>,
    mpl::vector<const DefaultType*&, const DefaultType*&&>,
    mpl::vector<volatile DefaultType*&, volatile DefaultType*&&>,
    mpl::vector<const volatile DefaultType*&, const volatile DefaultType*&&>,
    //mpl::vector<DefaultType* const&, DefaultType* const>,
    //mpl::vector<DefaultType* const&, DefaultType* const&>,
    mpl::vector<DefaultType* volatile&, DefaultType* volatile>,
    mpl::vector<DefaultType* volatile&, DefaultType* volatile&>,
    //mpl::vector<DefaultType* const volatile&, DefaultType* const volatile>,
    //mpl::vector<DefaultType* const volatile&, DefaultType* const volatile&>,
    //mpl::vector<DefaultType* const&, DefaultType* const&&>,
    mpl::vector<DefaultType* volatile&, DefaultType* volatile&&>//,
    //mpl::vector<DefaultType* const volatile&, DefaultType* const volatile&&>
>;

struct ConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        using LHS = typename mpl::at<T, mpl::int_<0>>::type;
        using RHS = typename mpl::at<T, mpl::int_<1>>::type;
        BOOST_STATIC_ASSERT(std::is_assignable<LHS, RHS>::value);
        BOOST_CONCEPT_ASSERT((stl_concept::Assignable<LHS, RHS>));
    }
};

} // namespace

void assignable_check()
{
    mpl::for_each<BasicTL>(ConceptChecker());
    mpl::for_each<PointerTL>(ConceptChecker());
}

} // namespace test
} // namespace stl_concept
