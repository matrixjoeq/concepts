
#include <boost/type_traits/has_equal_to.hpp>
#include "util.h"
#include "concept/equality_comparable.hpp"

namespace stl_concept {
namespace test {
namespace {

using BasicTL = mpl::vector<
    mpl::identity<EqualType>,
    mpl::identity<const EqualType>//,
    //mpl::identity<volatile EqualType>,
    //mpl::identity<const volatile EqualType>
>;

using ReferenceTL = mpl::vector<
    mpl::identity<EqualType&>,
    mpl::identity<const EqualType&>
>;

using PointerTL = mpl::vector<
    mpl::identity<EqualType*>,
    mpl::identity<const EqualType*>,
    mpl::identity<volatile EqualType*>,
    mpl::identity<const volatile EqualType*>,
    mpl::identity<EqualType* const>,
    mpl::identity<EqualType* volatile>,
    mpl::identity<EqualType* const volatile>,
    mpl::identity<const EqualType* const>,
    mpl::identity<volatile EqualType* const>,
    mpl::identity<const volatile EqualType* const>,
    mpl::identity<const EqualType* const volatile>,
    mpl::identity<volatile EqualType* const volatile>,
    mpl::identity<const volatile EqualType* const volatile>,
    mpl::identity<const EqualType* volatile>,
    mpl::identity<volatile EqualType* volatile>,
    mpl::identity<const volatile EqualType* volatile>
>;

using BasicArrayTL = mpl::vector<
    //mpl::identity<EqualType[1]>,
    //mpl::identity<const EqualType[1]>,
    //mpl::identity<volatile EqualType[1]>,
    //mpl::identity<const volatile EqualType[1]>
>;

using PointerArrayTL = mpl::vector<
    //mpl::identity<EqualType*[1]>,
    //mpl::identity<const EqualType*[1]>,
    //mpl::identity<volatile EqualType*[1]>,
    //mpl::identity<const volatile EqualType*[1]>,
    //mpl::identity<EqualType* const[1]>,
    //mpl::identity<EqualType* volatile[1]>,
    //mpl::identity<EqualType* const volatile[1]>,
    //mpl::identity<const EqualType* const[1]>,
    //mpl::identity<volatile EqualType* const[1]>,
    //mpl::identity<const volatile EqualType* const[1]>,
    //mpl::identity<const EqualType* const volatile[1]>,
    //mpl::identity<volatile EqualType* const volatile[1]>,
    //mpl::identity<const volatile EqualType* const volatile[1]>,
    //mpl::identity<const EqualType* volatile[1]>,
    //mpl::identity<volatile EqualType* volatile[1]>,
    //mpl::identity<const volatile EqualType* volatile[1]>
>;

struct ConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        using Type = typename T::type;
        BOOST_STATIC_ASSERT(boost::has_equal_to<Type>::value);
        BOOST_CONCEPT_ASSERT((boost::EqualityComparable<Type>));
        BOOST_CONCEPT_ASSERT((stl_concept::EqualityComparable<Type>));
    }
};

} // namespace

void equality_comparable_check()
{
    mpl::for_each<BasicTL>(ConceptChecker());
    mpl::for_each<ReferenceTL>(ConceptChecker());
    mpl::for_each<PointerTL>(ConceptChecker());
    mpl::for_each<BasicArrayTL>(ConceptChecker());
    mpl::for_each<PointerArrayTL>(ConceptChecker());
}

} // namespace test
} // namespace stl_concept
