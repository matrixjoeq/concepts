
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
#include "concept/iterator.hpp"

namespace stl_concept {
namespace test {
namespace {

using IteratorTL = mpl::vector<
    std::array<DefaultType, 1>::iterator,
    std::deque<DefaultType>::iterator,
    std::forward_list<DefaultType>::iterator,
    std::list<DefaultType>::iterator,
    std::map<LessType, DefaultType>::iterator,
    std::multimap<LessType, DefaultType>::iterator,
    std::unordered_map<DefaultType, DefaultType, HashFunctor<DefaultType>>::iterator,
    std::unordered_multimap<DefaultType, DefaultType, HashFunctor<DefaultType>>::iterator,
    std::set<LessType>::iterator,
    std::multiset<LessType>::iterator,
    std::unordered_set<DefaultType, HashFunctor<DefaultType>>::iterator,
    std::unordered_multiset<DefaultType, HashFunctor<DefaultType>>::iterator,
    std::vector<DefaultType>::iterator
>;

struct ConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        BOOST_CONCEPT_ASSERT((stl_concept::Iterator<T>));
    };
};

} // namespace

void iterator_check()
{
    mpl::for_each<IteratorTL>(ConceptChecker());
}

} // namespace test
} // namespace stl_concept
