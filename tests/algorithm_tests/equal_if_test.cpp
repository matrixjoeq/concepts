
#include <cassert>
#include <vector>
#include <list>
#include <functional>
#include <boost/type_traits/conditional.hpp>
#include "algorithm/equal_if.hpp"

namespace stl_algorithm {
namespace test {
namespace {

using FirstType = int;
using SecondType = long;

using DataType = boost::conditional_t<(sizeof(FirstType) > sizeof(SecondType)), FirstType, SecondType>;

bool is_equal(DataType i, DataType j)
{
    return i == j;
}

struct IsEqual
{
    bool operator()(DataType i, DataType j)
    {
        return is_equal(i, j);
    }
};

} // namespace

void equal_if_check()
{
    using namespace std::placeholders;

    std::vector<FirstType> v{1, 2, 3, 4, 5};
    std::list<SecondType> l{1l, 2l, 3l, 4l, 5l};

    IsEqual pred;
    auto func = is_equal;
    auto functor = std::function<decltype(is_equal)>(is_equal);
    auto binder = std::bind(is_equal, _1, _2);
    auto vfirst = v.begin();
    auto vlast = v.end();
    auto lfirst = l.begin();
    auto llast = l.end();
    auto lambda = [](DataType i, DataType j) { return is_equal(i, j); };

    assert(stl_algorithm::equal_if(vfirst, vlast, lfirst, func));
    assert(stl_algorithm::equal_if(vfirst, vlast, lfirst, pred));
    assert(stl_algorithm::equal_if(lfirst, llast, vfirst, functor));
    assert(stl_algorithm::equal_if(lfirst, llast, vfirst, binder));
    assert(stl_algorithm::equal_if(vfirst, vlast, lfirst, lambda));
    assert(stl_algorithm::equal_if(v.begin(), v.end(), l.begin(), is_equal));
    assert(stl_algorithm::equal_if(v.begin(), v.end(), l.begin(), IsEqual()));
    assert(stl_algorithm::equal_if(v.begin(), v.end(), l.begin(), std::function<decltype(is_equal)>(is_equal)));
    assert(stl_algorithm::equal_if(l.begin(), l.end(), v.begin(), std::bind(is_equal, _1, _2)));
    assert(stl_algorithm::equal_if(l.begin(), l.end(), v.begin(), std::bind(&IsEqual::operator(), &pred, _1, _2)));
    assert(stl_algorithm::equal_if(l.begin(), l.end(), v.begin(), [](DataType i, DataType j){ return is_equal(i, j); }));
}

} // namespace test
} // namespace stl_algorithm
