
#include <boost/type_traits/has_less.hpp>
#include "util.h"
#include "concept/less_than_comparable.hpp"

namespace stl_concept {
namespace test {
namespace {

using BasicTL = mpl::vector<
    mpl::identity<LessType>,
    mpl::identity<const LessType>//,
    //mpl::identity<volatile LessType>,
    //mpl::identity<const volatile LessType>
>;

using PointerTL = mpl::vector<
    mpl::identity<LessType*>,
    mpl::identity<const LessType*>,
    mpl::identity<volatile LessType*>,
    mpl::identity<const volatile LessType*>,
    mpl::identity<LessType* const>,
    mpl::identity<LessType* volatile>,
    mpl::identity<LessType* const volatile>,
    mpl::identity<const LessType* const>,
    mpl::identity<volatile LessType* const>,
    mpl::identity<const volatile LessType* const>,
    mpl::identity<const LessType* const volatile>,
    mpl::identity<volatile LessType* const volatile>,
    mpl::identity<const volatile LessType* const volatile>,
    mpl::identity<const LessType* volatile>,
    mpl::identity<volatile LessType* volatile>,
    mpl::identity<const volatile LessType* volatile>
>;

using BasicArrayTL = mpl::vector<
    //mpl::identity<LessType[1]>,
    //mpl::identity<const LessType[1]>,
    //mpl::identity<volatile LessType[1]>,
    //mpl::identity<const volatile LessType[1]>
>;

using PointerArrayTL = mpl::vector<
    //mpl::identity<LessType*[1]>,
    //mpl::identity<const LessType*[1]>,
    //mpl::identity<volatile LessType*[1]>,
    //mpl::identity<const volatile LessType*[1]>,
    //mpl::identity<LessType* const[1]>,
    //mpl::identity<LessType* volatile[1]>,
    //mpl::identity<LessType* const volatile[1]>,
    //mpl::identity<const LessType* const[1]>,
    //mpl::identity<volatile LessType* const[1]>,
    //mpl::identity<const volatile LessType* const[1]>,
    //mpl::identity<const LessType* const volatile[1]>,
    //mpl::identity<volatile LessType* const volatile[1]>,
    //mpl::identity<const volatile LessType* const volatile[1]>,
    //mpl::identity<const LessType* volatile[1]>,
    //mpl::identity<volatile LessType* volatile[1]>,
    //mpl::identity<const volatile LessType* volatile[1]>
>;

struct ConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        using Type = typename T::type;
        BOOST_STATIC_ASSERT(boost::has_less<Type>::value);
        BOOST_CONCEPT_ASSERT((boost::LessThanComparable<Type>));
        BOOST_CONCEPT_ASSERT((stl_concept::LessThanComparable<Type>));
    }
};

} // namespace

void less_comparable_check()
{
    mpl::for_each<BasicTL>(ConceptChecker());
    mpl::for_each<PointerTL>(ConceptChecker());
    mpl::for_each<BasicArrayTL>(ConceptChecker());
    mpl::for_each<PointerArrayTL>(ConceptChecker());
}

} // namespace test
} // namespace stl_concept
