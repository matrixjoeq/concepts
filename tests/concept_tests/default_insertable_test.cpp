
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
#include "concept/default_insertable.hpp"

namespace stl_concept {
namespace test {
namespace {

using TL = mpl::vector<
    mpl::vector<DefaultType, std::array<DefaultType, 1>>,
    mpl::vector<DefaultType, std::deque<DefaultType>>,
    mpl::vector<DefaultType, std::forward_list<DefaultType>>,
    mpl::vector<DefaultType, std::list<DefaultType>>,
    mpl::vector<std::pair<const LessType, DefaultType>, std::map<LessType, DefaultType>>,
    mpl::vector<std::pair<const LessType, DefaultType>, std::multimap<LessType, DefaultType>>,
    mpl::vector<std::pair<const DefaultType, DefaultType>, std::unordered_map<DefaultType, DefaultType, HashFunctor<DefaultType>>>,
    mpl::vector<std::pair<const DefaultType, DefaultType>, std::unordered_multimap<DefaultType, DefaultType, HashFunctor<DefaultType>>>,
    mpl::vector<LessType, std::set<LessType>>,
    mpl::vector<LessType, std::multiset<LessType>>,
    mpl::vector<DefaultType, std::unordered_set<DefaultType, HashFunctor<DefaultType>>>,
    mpl::vector<DefaultType, std::unordered_multiset<DefaultType, HashFunctor<DefaultType>>>,
    mpl::vector<DefaultType, std::vector<DefaultType>>
>;

struct ConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        using _ValueType = typename mpl::at<T, mpl::int_<0>>::type;
        using _ContainerType = typename mpl::at<T, mpl::int_<1>>::type;
        BOOST_CONCEPT_ASSERT((stl_concept::DefaultInsertable<_ValueType, _ContainerType>));
    }
};

} // namespace

void default_insertable_check()
{
    mpl::for_each<TL>(ConceptChecker());
}

} // namespace test
} // namespace stl_concept
