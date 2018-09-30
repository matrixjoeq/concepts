
#include <iostream>
#include <string>

#include <boost/type_traits.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/map.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/concept/assert.hpp>
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
} // namespace

int main()
{
    BOOST_CONCEPT_ASSERT((boost::DefaultConstructible<void>));
    //BOOST_CONCEPT_ASSERT((stl_concepts::DefaultConstructible<Test&>));
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
