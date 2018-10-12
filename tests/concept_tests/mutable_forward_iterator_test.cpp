
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "util.h"
#include "concept/mutable_forward_iterator.hpp"

namespace stl_concept {
namespace test {
namespace {

using IteratorTL = mpl::vector<
    mpl::vector<std::array<DefaultType, 1>::iterator, DefaultType>,
    mpl::vector<std::deque<DefaultType>::iterator, DefaultType>,
    mpl::vector<std::forward_list<DefaultType>::iterator, DefaultType>,
    mpl::vector<std::list<DefaultType>::iterator, DefaultType>,
    //mpl::vector<std::map<LessType, DefaultType>::iterator, DefaultType>,
    //mpl::vector<std::multimap<LessType, DefaultType>::iterator, DefaultType>,
    //mpl::vector<std::unordered_map<DefaultType, DefaultType, HashFunctor<DefaultType>>::iterator, DefaultType>,
    //mpl::vector<std::unordered_multimap<DefaultType, DefaultType, HashFunctor<DefaultType>>::iterator, DefaultType>,
    //mpl::vector<std::set<LessType>::iterator, DefaultType>,
    //mpl::vector<std::multiset<LessType>::iterator, DefaultType>,
    //mpl::vector<std::unordered_set<DefaultType, HashFunctor<DefaultType>>::iterator, DefaultType>,
    //mpl::vector<std::unordered_multiset<DefaultType, HashFunctor<DefaultType>>::iterator, DefaultType>,
    mpl::vector<std::vector<DefaultType>::iterator, DefaultType>
>;

struct ConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        using _Iterator = typename mpl::at<T, mpl::int_<0>>::type;
        using _Value = typename mpl::at<T, mpl::int_<1>>::type;
        BOOST_CONCEPT_ASSERT((boost::Mutable_ForwardIterator<_Iterator>));
        BOOST_CONCEPT_ASSERT((stl_concept::MutableForwardIterator<_Iterator, _Value>));
    }
};

} // namespace

void mutable_forward_iterator_check()
{
    mpl::for_each<IteratorTL>(ConceptChecker());
}

} // namespace test
} // namespace stl_concept
