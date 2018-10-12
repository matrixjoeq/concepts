
#include <iterator>
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <vector>
#include "util.h"
#include "concept/output_iterator.hpp"

namespace stl_concept {
namespace test {
namespace {

using IteratorTL = mpl::vector<
    mpl::vector<std::array<DefaultType, 1>::iterator, DefaultType>,
    mpl::vector<std::deque<DefaultType>::iterator, DefaultType>,
    mpl::vector<std::forward_list<DefaultType>::iterator, DefaultType>,
    mpl::vector<std::list<DefaultType>::iterator, DefaultType>,
    mpl::vector<std::vector<DefaultType>::iterator, DefaultType>,
    mpl::vector<std::insert_iterator<std::list<DefaultType>>, DefaultType>,
    mpl::vector<std::front_insert_iterator<std::deque<DefaultType>>, DefaultType>,
    mpl::vector<std::back_insert_iterator<std::vector<DefaultType>>, DefaultType>,
    mpl::vector<std::ostream_iterator<char>, char>,
    mpl::vector<std::ostreambuf_iterator<char>, char>
>;

struct ConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        using _Iterator = typename mpl::at<T, mpl::int_<0>>::type;
        using _Value = typename mpl::at<T, mpl::int_<1>>::type;
        BOOST_CONCEPT_ASSERT((boost::OutputIterator<_Iterator, _Value>));
        BOOST_CONCEPT_ASSERT((stl_concept::OutputIterator<_Iterator, _Value>));
    }
};

} // namespace

void output_iterator_check()
{
    mpl::for_each<IteratorTL>(ConceptChecker());
}

} // namespace test
} // namespace stl_concept
