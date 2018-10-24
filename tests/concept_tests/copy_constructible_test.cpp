
#include <type_traits>
#include "util.h"
#include "concept/copy_constructible.hpp"

namespace stl_concept {
namespace test {
namespace {

using BasicTL = mpl::vector<
    mpl::identity<DefaultType>,
    mpl::identity<const DefaultType>//,
    //mpl::identity<volatile DefaultType>//,
    //mpl::identity<const volatile DefaultType>
>;

using ReferenceTL = mpl::vector<
    mpl::identity<DefaultType&>,
    mpl::identity<const DefaultType&>,
    mpl::identity<volatile DefaultType&>,
    mpl::identity<const volatile DefaultType&>
>;

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

using BasicArrayTL = mpl::vector<
    //mpl::identity<DefaultType[1]>,
    //mpl::identity<const DefaultType[1]>,
    //mpl::identity<volatile DefaultType[1]>,
    //mpl::identity<const volatile DefaultType[1]>
>;

using PointerArrayTL = mpl::vector<
    //mpl::identity<DefaultType*[1]>,
    //mpl::identity<const DefaultType*[1]>,
    //mpl::identity<volatile DefaultType*[1]>,
    //mpl::identity<const volatile DefaultType*[1]>,
    //mpl::identity<DefaultType* const[1]>,
    //mpl::identity<DefaultType* volatile[1]>,
    //mpl::identity<DefaultType* const volatile[1]>,
    //mpl::identity<const DefaultType* const[1]>,
    //mpl::identity<volatile DefaultType* const[1]>,
    //mpl::identity<const volatile DefaultType* const[1]>,
    //mpl::identity<const DefaultType* const volatile[1]>,
    //mpl::identity<volatile DefaultType* const volatile[1]>,
    //mpl::identity<const volatile DefaultType* const volatile[1]>,
    //mpl::identity<const DefaultType* volatile[1]>,
    //mpl::identity<volatile DefaultType* volatile[1]>,
    //mpl::identity<const volatile DefaultType* volatile[1]>
>;

struct ConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        using Type = typename T::type;
        BOOST_STATIC_ASSERT(std::is_copy_constructible<Type>::value);
        // boost::CopyConstructible has problem with lvalue reference check
        //BOOST_CONCEPT_ASSERT((boost::CopyConstructible<Type>));
        BOOST_CONCEPT_ASSERT((stl_concept::CopyConstructible<Type>));
    }
};

} // namespace

void copy_constructible_check()
{
    mpl::for_each<BasicTL>(ConceptChecker());
    //mpl::for_each<ReferenceTL>(ConceptChecker());
    mpl::for_each<PointerTL>(ConceptChecker());
    mpl::for_each<BasicArrayTL>(ConceptChecker());
    mpl::for_each<PointerArrayTL>(ConceptChecker());
}

} // namespace test
} // namespace stl_concept
