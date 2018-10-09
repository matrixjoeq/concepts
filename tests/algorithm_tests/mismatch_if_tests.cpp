
#include <cassert>
#include <vector>
#include <list>
#include <functional>
#include "algorithm/mismatch_if.hpp"

namespace stl_algorithm {
namespace test {
namespace {

bool is_equal(int i, int j)
{
    return i == j;
}

struct IsEqual
{
    bool operator()(int i, int j)
    {
        return is_equal(i, j);
    }
};

template <class Pair>
inline void assert_not_equal(const Pair& p)
{
    assert(*(p.first) != *(p.second));
}

} // namespace

void mismatch_if_check()
{
    using namespace std::placeholders;

    std::vector<int> v{1, 2, 3, 4, 5};
    std::list<long> l{1l, 2l, 3l, 5l, 6l};

    IsEqual pred;
    auto func = is_equal;
    auto functor = std::function<decltype(is_equal)>(is_equal);
    auto binder = std::bind(is_equal, _1, _2);
    auto vfirst = v.begin();
    auto vlast = v.end();
    auto lfirst = l.begin();
    auto llast = l.end();
    auto lambda = [](int i, int j) { return is_equal(i, j); };

    auto p1 = stl_algorithm::mismatch_if(vfirst, vlast, lfirst, func);
    assert_not_equal(p1);

    auto p2 = stl_algorithm::mismatch_if(vfirst, vlast, lfirst, pred);
    assert_not_equal(p2);

    auto p3 = stl_algorithm::mismatch_if(lfirst, llast, vfirst, functor);
    assert_not_equal(p3);

    auto p4 = stl_algorithm::mismatch_if(lfirst, llast, vfirst, binder);
    assert_not_equal(p4);

    auto p5 = stl_algorithm::mismatch_if(vfirst, vlast, lfirst, lambda);
    assert_not_equal(p5);

    auto p6 = stl_algorithm::mismatch_if(v.begin(), v.end(), l.begin(), is_equal);
    assert_not_equal(p6);

    auto p7 = stl_algorithm::mismatch_if(v.begin(), v.end(), l.begin(), IsEqual());
    assert_not_equal(p7);

    auto p8 = stl_algorithm::mismatch_if(v.begin(), v.end(), l.begin(), std::function<decltype(is_equal)>(is_equal));
    assert_not_equal(p8);

    auto p9 = stl_algorithm::mismatch_if(l.begin(), l.end(), v.begin(), std::bind(is_equal, _1, _2));
    assert_not_equal(p9);

    auto p10 = stl_algorithm::mismatch_if(l.begin(), l.end(), v.begin(), std::bind(&IsEqual::operator(), &pred, _1, _2));
    assert_not_equal(p10);

    auto p11 = stl_algorithm::mismatch_if(l.begin(), l.end(), v.begin(), [](int i, int j){ return is_equal(i, j); });
    assert_not_equal(p11);
}

} // namespace test
} // namespace stl_algorithm
