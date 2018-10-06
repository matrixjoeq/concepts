
#include <array>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <queue>
#include <regex>
#include <thread>
#include <tuple>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
#include <boost/any.hpp>
#include <boost/optional.hpp>
#include <boost/variant.hpp>
#include "util.h"
#include "concept/detail/is_swappable.hpp"
#include "concept/swappable.hpp"

namespace stl_concept {
namespace test {
namespace {

using BasicTL = mpl::vector<
    mpl::identity<DefaultType>//,
    //mpl::identity<const DefaultType>,
    //mpl::identity<volatile DefaultType>,
    //mpl::identity<const volatile DefaultType>
>;

using PointerTL = mpl::vector<
    mpl::identity<DefaultType*>,
    mpl::identity<const DefaultType*>,
    mpl::identity<volatile DefaultType*>,
    mpl::identity<const volatile DefaultType*>,
    //mpl::identity<DefaultType* const>,
    mpl::identity<DefaultType* volatile>,
    //mpl::identity<DefaultType* const volatile>,
    //mpl::identity<const DefaultType* const>,
    //mpl::identity<volatile DefaultType* const>,
    //mpl::identity<const volatile DefaultType* const>,
    //mpl::identity<const DefaultType* const volatile>,
    //mpl::identity<volatile DefaultType* const volatile>,
    //mpl::identity<const volatile DefaultType* const volatile>,
    mpl::identity<const DefaultType* volatile>,
    mpl::identity<volatile DefaultType* volatile>,
    mpl::identity<const volatile DefaultType* volatile>
>;

using BasicArrayTL = mpl::vector<
    mpl::identity<DefaultType[1]>//,
    //mpl::identity<const DefaultType[1]>,
    //mpl::identity<volatile DefaultType[1]>,
    //mpl::identity<const volatile DefaultType[1]>
>;

using PointerArrayTL = mpl::vector<
    mpl::identity<DefaultType*[1]>,
    mpl::identity<const DefaultType*[1]>,
    mpl::identity<volatile DefaultType*[1]>,
    mpl::identity<const volatile DefaultType*[1]>,
    //mpl::identity<DefaultType* const[1]>,
    mpl::identity<DefaultType* volatile[1]>,
    //mpl::identity<DefaultType* const volatile[1]>,
    //mpl::identity<const DefaultType* const[1]>,
    //mpl::identity<volatile DefaultType* const[1]>,
    //mpl::identity<const volatile DefaultType* const[1]>,
    //mpl::identity<const DefaultType* const volatile[1]>,
    //mpl::identity<volatile DefaultType* const volatile[1]>,
    //mpl::identity<const volatile DefaultType* const volatile[1]>,
    mpl::identity<const DefaultType* volatile[1]>,
    mpl::identity<volatile DefaultType* volatile[1]>,
    mpl::identity<const volatile DefaultType* volatile[1]>
>;

using SpecialTL = mpl::vector<
    mpl::identity<std::pair<DefaultType, DefaultType>>,
    mpl::identity<std::shared_ptr<DefaultType>>,
    mpl::identity<std::weak_ptr<DefaultType>>,
    mpl::identity<std::unique_ptr<DefaultType>>,
    mpl::identity<std::function<DefaultType()>>,
    mpl::identity<std::string>,
    mpl::identity<std::stringbuf>,
    mpl::identity<std::istringstream>,
    mpl::identity<std::ostringstream>,
    mpl::identity<std::stringstream>,
    mpl::identity<std::filebuf>,
    mpl::identity<std::ifstream>,
    mpl::identity<std::ofstream>,
    mpl::identity<std::fstream>,
    mpl::identity<std::regex>,
    mpl::identity<std::smatch>,
    mpl::identity<std::thread>,
    mpl::identity<std::unique_lock<std::mutex>>,
    mpl::identity<std::promise<DefaultType>>,
    mpl::identity<std::packaged_task<DefaultType()>>
>;

using ContainerTL = mpl::vector<
    mpl::identity<std::tuple<DefaultType>>,
    mpl::identity<std::array<DefaultType, 1>>,
    mpl::identity<std::deque<DefaultType>>,
    mpl::identity<std::forward_list<DefaultType>>,
    mpl::identity<std::list<DefaultType>>,
    mpl::identity<std::vector<DefaultType>>,
    mpl::identity<std::map<LessType, DefaultType>>,
    mpl::identity<std::multimap<LessType, DefaultType>>,
    mpl::identity<std::unordered_map<DefaultType, DefaultType, HashFunctor<DefaultType>>>,
    mpl::identity<std::unordered_multimap<DefaultType, DefaultType, HashFunctor<DefaultType>>>,
    mpl::identity<std::set<LessType>>,
    mpl::identity<std::multiset<LessType>>,
    mpl::identity<std::unordered_set<DefaultType, DefaultType, HashFunctor<DefaultType>>>,
    mpl::identity<std::unordered_multiset<DefaultType, DefaultType, HashFunctor<DefaultType>>>,
    mpl::identity<std::queue<DefaultType>>,
    mpl::identity<std::priority_queue<DefaultType>>,
    mpl::identity<std::stack<DefaultType>>,
    mpl::identity<std::valarray<DefaultType>>
>;

using BoostTL = mpl::vector<
    mpl::identity<boost::any>,
    mpl::identity<boost::optional<DefaultType>>,
    mpl::identity<boost::variant<DefaultType>>
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

void swappable_check()
{
    mpl::for_each<BasicTL>(ConceptChecker());
    mpl::for_each<PointerTL>(ConceptChecker());
    mpl::for_each<BasicArrayTL>(ConceptChecker());
    mpl::for_each<PointerArrayTL>(ConceptChecker());
    mpl::for_each<SpecialTL>(ConceptChecker());
    mpl::for_each<ContainerTL>(ConceptChecker());
}

} // namespace test
} // namespace stl_concept
