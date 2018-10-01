
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

#include <boost/type_traits.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/map.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/concept/assert.hpp>
#include <boost/concept/requires.hpp>
#include <boost/concept_check.hpp>

#include "stl_concept.hpp"

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

void foo() {}

int main()
{
    BOOST_CONCEPT_ASSERT((stl_concept::ValueSwappable<std::vector<int>::iterator>));
    //static_assert(std::__is_referenceable<int[1][1]>::value, "");
    //static_assert(stl_concept::__detail::__is_referenceable<int[1][1]>::value, "");
    //BOOST_CONCEPT_ASSERT((boost::DefaultConstructible<Test>));
    //BOOST_CONCEPT_ASSERT((stl_concept::DefaultConstructible<Test>));
    //BOOST_CONCEPT_ASSERT((boost::DefaultConstructible<void>));

    /*
    BOOST_CONCEPT_ASSERT((stl_concept::DefaultConstructible<Test>));
    BOOST_CONCEPT_ASSERT((stl_concept::MoveConstructible<Test>));
    BOOST_CONCEPT_ASSERT((stl_concept::CopyConstructible<Test>));
    BOOST_CONCEPT_ASSERT((stl_concept::MoveAssignable<Test>));
    BOOST_CONCEPT_ASSERT((stl_concept::CopyAssignable<Test>));
    BOOST_CONCEPT_ASSERT((stl_concept::Destructible<Test>));

    BOOST_CONCEPT_ASSERT((stl_concept::EqualityComparable<Test>));
    BOOST_CONCEPT_ASSERT((stl_concept::LessThanComparable<Test>));
    */
    return 0;
}
