
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "util.h"
#include "concept/emplace_insertable.hpp"

namespace stl_concept {
namespace test {
namespace {

using TL = mpl::vector<
    mpl::vector<DefaultType, std::array<DefaultType, 1>>,
    mpl::vector<DefaultType, std::deque<DefaultType>>,
    mpl::vector<DefaultType, std::forward_list<DefaultType>>,
    mpl::vector<DefaultType, std::list<DefaultType>>,
    mpl::vector<DefaultType, std::queue<DefaultType>>,
    mpl::vector<LessType, std::priority_queue<LessType>>,
    mpl::vector<DefaultType, std::stack<DefaultType>>,
    mpl::vector<LessType, std::set<LessType>>,
    mpl::vector<LessType, std::multiset<LessType>>,
    mpl::vector<DefaultType, std::unordered_set<DefaultType, HashFunctor<DefaultType>>>,
    mpl::vector<DefaultType, std::unordered_multiset<DefaultType, HashFunctor<DefaultType>>>,
    mpl::vector<DefaultType, std::vector<DefaultType>>
>;

using MapTL = mpl::vector<
    mpl::vector<std::pair<const LessType, DefaultType>,
                std::map<LessType, DefaultType>,
                LessType,
                DefaultType>,
    mpl::vector<std::pair<const LessType, DefaultType>,
                std::multimap<LessType, DefaultType>,
                LessType,
                DefaultType>,
    mpl::vector<std::pair<const DefaultType, DefaultType>,
                std::unordered_map<DefaultType, DefaultType, HashFunctor<DefaultType>>,
                DefaultType,
                DefaultType>,
    mpl::vector<std::pair<const DefaultType, DefaultType>,
                std::unordered_multimap<DefaultType, DefaultType, HashFunctor<DefaultType>>,
                DefaultType,
                DefaultType>
>;

struct ConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        using _ValueType = typename mpl::at<T, mpl::int_<0>>::type;
        using _ContainerType = typename mpl::at<T, mpl::int_<1>>::type;
        BOOST_CONCEPT_ASSERT((stl_concept::EmplaceInsertable<_ValueType, _ContainerType>));
    }
};

struct MapConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        using _PairType = typename mpl::at<T, mpl::int_<0>>::type;
        using _ContainerType = typename mpl::at<T, mpl::int_<1>>::type;
        using _KeyType = typename mpl::at<T, mpl::int_<2>>::type;
        using _ValueType = typename mpl::at<T, mpl::int_<3>>::type;
        BOOST_CONCEPT_ASSERT((stl_concept::EmplaceInsertable<_PairType, _ContainerType, _KeyType, _ValueType>));
    }
};

} // namespace

void emplace_insertable_check()
{
    mpl::for_each<TL>(ConceptChecker());
    mpl::for_each<MapTL>(MapConceptChecker());
}

} // namespace test
} // namespace stl_concept
