
#include <cassert>
#include <vector>
#include <list>
#include "algorithm/mismatch.hpp"

namespace stl_algorithm {
namespace test {
namespace {

template <typename Pair>
void inline assert_not_equal(const Pair& p)
{
    assert(*(p.first) != *(p.second));
}

} // namespace

void mismatch_check()
{
    std::vector<int> v{1, 2, 3, 4, 5};
    std::list<long> l{1l, 2l, 3l, 5l, 6l};

    auto vfirst = v.begin();
    auto vlast = v.end();
    auto lfirst = l.begin();
    auto llast = l.end();

    auto p1 = stl_algorithm::mismatch(vfirst, vlast, lfirst);
    auto p2 = stl_algorithm::mismatch(lfirst, llast, vfirst);
    assert_not_equal(p1);
    assert_not_equal(p2);

    auto p3 = stl_algorithm::mismatch(v.begin(), v.end(), l.begin());
    auto p4 = stl_algorithm::mismatch(l.begin(), l.end(), v.begin());
    assert_not_equal(p3);
    assert_not_equal(p4);
}

} // namespace test
} // namespace stl_algorithm
