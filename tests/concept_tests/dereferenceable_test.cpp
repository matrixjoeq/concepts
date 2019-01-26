
#include <type_traits>
#include "util.h"
#include "concept/dereferenceable.hpp"

namespace stl_concept {
namespace test {
namespace {

struct Dereference
{
    void operator*() {}
};

using PointerTL = mpl::vector<
    mpl::identity<DefaultType*>,
    mpl::identity<const DefaultType*>,
    mpl::identity<volatile DefaultType*>,
    mpl::identity<const volatile DefaultType*>,
    mpl::identity<DefaultType* const>,
    mpl::identity<DefaultType* volatile>,
    mpl::identity<DefaultType* const volatile>,
    mpl::identity<const DefaultType* const>,
    mpl::identity<volatile DefaultType* const>,
    mpl::identity<const volatile DefaultType* const>,
    mpl::identity<const DefaultType* const volatile>,
    mpl::identity<volatile DefaultType* const volatile>,
    mpl::identity<const volatile DefaultType* const volatile>,
    mpl::identity<const DefaultType* volatile>,
    mpl::identity<volatile DefaultType* volatile>,
    mpl::identity<const volatile DefaultType* volatile>
>;

struct ConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        using Type = typename T::type;
        BOOST_CONCEPT_ASSERT((stl_concept::Dereferenceable<Type>));
    }
};

} // namespace

void dereferenceable_check()
{
    BOOST_CONCEPT_ASSERT((stl_concept::Dereferenceable<Dereference>));
    mpl::for_each<PointerTL>(ConceptChecker());
}

} // namespace test
} // namespace stl_concept
