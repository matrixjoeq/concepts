
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

namespace stl_concept {
namespace test {
namespace {

using ContainerTL = mpl::vector<
    mpl::identity<std::array<DefaultType, 1>::iterator>,
    mpl::identity<std::deque<DefaultType>::iterator>,
    mpl::identity<std::forward_list<DefaultType>::iterator>,
    mpl::identity<std::list<DefaultType>::iterator>,
    mpl::identity<std::map<LessType, DefaultType>::iterator>,
    mpl::identity<std::multimap<LessType, DefaultType>::iterator>,
    mpl::identity<std::unordered_map<DefaultType, DefaultType, HashFunctor<DefaultType>>::iterator>,
    mpl::identity<std::unordered_multimap<DefaultType, DefaultType, HashFunctor<DefaultType>>::iterator>,
    mpl::identity<std::set<LessType>::iterator>,
    mpl::identity<std::multiset<LessType>::iterator>,
    mpl::identity<std::unordered_set<DefaultType, HashFunctor<DefaultType>>::iterator>,
    mpl::identity<std::unordered_multiset<DefaultType, HashFunctor<DefaultType>>::iterator>,
    mpl::identity<std::vector<DefaultType>::iterator>
>;

struct ConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        using Type = typename T::type;
        BOOST_STATIC_ASSERT(stl_concept::__detail::__is_swappable<Type>::value);
        BOOST_CONCEPT_ASSERT((stl_concept::Swappable<Type>));
    };
};

} // namespace

void value_swappable_check()
{
    mpl::for_each<ContainerTL>(ConceptChecker());
}

} // namespace test
} // namespace stl_concept
