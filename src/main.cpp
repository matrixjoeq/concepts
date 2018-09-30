
#include <iostream>
#include <string>

#include <boost/type_traits.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/map.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/concept/assert.hpp>
#include <boost/concept/requires.hpp>
#include <boost/concept_check.hpp>

#include "stl_concepts.hpp"

namespace {

struct Test
{
    Test(int i) : i_(i) {}
    //Test(Test&&) = delete;
    int i_;

    //friend bool operator==(const Test& lhs, const Test& rhs);
    //friend bool operator<(const Test& lhs, const Test& rhs);
};
/*
bool operator==(const Test& lhs, const Test& rhs)
{
    return lhs.i_ == rhs.i_;
}

bool operator<(const Test& lhs, const Test& rhs)
{
    return lhs.i_ < rhs.i_;
}
*/

template <typename E>
    BOOST_CONCEPT_REQUIRES(
        ((boost::SignedInteger<E>)),                     // properties
        (typename std::make_unsigned<E>::type) // return type
    )
constexpr asUnsigned(E e)
{
    // need to perform an additional cast here because otherwise compiler/tools rightly warn about
    // unsafe conversion
    return static_cast<typename std::make_unsigned<E>::type>(typename std::make_unsigned<E>::type(e));
}

} // namespace

int main()
{
    auto i = asUnsigned("100");
    (void)i;
    //BOOST_CONCEPT_ASSERT((boost::DefaultConstructible<Test>));
    //BOOST_CONCEPT_ASSERT((stl_concepts::DefaultConstructible<Test>));
    //BOOST_CONCEPT_ASSERT((boost::DefaultConstructible<void>));

    /*
    BOOST_CONCEPT_ASSERT((stl_concepts::DefaultConstructible<Test>));
    BOOST_CONCEPT_ASSERT((stl_concepts::MoveConstructible<Test>));
    BOOST_CONCEPT_ASSERT((stl_concepts::CopyConstructible<Test>));
    BOOST_CONCEPT_ASSERT((stl_concepts::MoveAssignable<Test>));
    BOOST_CONCEPT_ASSERT((stl_concepts::CopyAssignable<Test>));
    BOOST_CONCEPT_ASSERT((stl_concepts::Destructible<Test>));

    BOOST_CONCEPT_ASSERT((stl_concepts::EqualityComparable<Test>));
    BOOST_CONCEPT_ASSERT((stl_concepts::LessThanComparable<Test>));
    */
    return 0;
}
