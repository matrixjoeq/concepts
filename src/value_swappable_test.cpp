
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iterator>
#include "concept/detail/is_swappable.hpp"
#include "util.h"

namespace stl_concept {
namespace test {
namespace {

using IteratorTL = mpl::vector<
    std::array<DefaultType, 1>::iterator,
    std::deque<DefaultType>::iterator,
    std::forward_list<DefaultType>::iterator,
    std::list<DefaultType>::iterator,
    //std::map<LessType, DefaultType>::iterator, // value type is std::pair<__CONST__ LessType, DefaultType>
    //std::multimap<LessType, DefaultType>::iterator,
    //std::unordered_map<DefaultType, DefaultType, HashFunctor<DefaultType>>::iterator,
    //std::unordered_multimap<DefaultType, DefaultType, HashFunctor<DefaultType>>::iterator,
    //std::set<LessType>::iterator,
    //std::multiset<LessType>::iterator,
    //std::unordered_set<DefaultType, HashFunctor<DefaultType>>::iterator,
    //std::unordered_multiset<DefaultType, HashFunctor<DefaultType>>::iterator,
    std::vector<DefaultType>::iterator
>;

struct ConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        using ValueType = typename std::iterator_traits<T>::value_type;
        BOOST_STATIC_ASSERT(stl_concept::__detail::__is_swappable<ValueType>::value);
        BOOST_CONCEPT_ASSERT((stl_concept::ValueSwappable<T>));
    };
};

} // namespace

void value_swappable_check()
{
    mpl::for_each<IteratorTL>(ConceptChecker());
}

} // namespace test
} // namespace stl_concept
