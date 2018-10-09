
#include <iterator>
#include "util.h"
#include "concept/output_iterator.hpp"

namespace stl_concept {
namespace test {
namespace {

using IteratorTL = mpl::vector<
    mpl::vector<std::ostream_iterator<char>, char>
>;

struct ConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        using _Iterator = mpl::at<T, mpl::int_<0>>::type;
        using _Value = mpl::at<T, mpl::int_<1>>::type;
        BOOST_CONCEPT_ASSERT((boost::OutputIterator<_Iterator, _Value>));
        BOOST_CONCEPT_ASSERT((stl_concept::OutputIterator<_Iterator, _Value>));
    }
};

} // namespace

void input_iterator_check()
{
    mpl::for_each<IteratorTL>(ConceptChecker());
}

} // namespace test
} // namespace stl_concept
