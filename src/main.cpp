
#include <iostream>
#include <string>

#include <boost/type_traits.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/map.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/concept/assert.hpp>

#include "stl_concepts.hpp"

namespace {

struct Test
{
    int i_;
};

} // namespace

int main()
{
    BOOST_CONCEPT_ASSERT((stl_concepts::DefaultConstructible<Test>));
    BOOST_CONCEPT_ASSERT((stl_concepts::CopyConstructible<Test>));
    BOOST_CONCEPT_ASSERT((stl_concepts::MoveConstructible<Test>));
    return 0;
}
