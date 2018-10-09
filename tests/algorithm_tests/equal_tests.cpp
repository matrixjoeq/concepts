
#include <cassert>
#include <vector>
#include <list>
#include "algorithm/equal.hpp"

namespace stl_algorithm {
namespace test {

void equal_check()
{
    std::vector<int> v{1, 2, 3, 4, 5};
    std::list<long> l{1l, 2l, 3l, 4l, 5l};

    auto vfirst = v.begin();
    auto vlast = v.end();
    auto lfirst = l.begin();
    auto llast = l.end();

    assert(stl_algorithm::equal(vfirst, vlast, lfirst));
    assert(stl_algorithm::equal(lfirst, llast, vfirst));

    assert(stl_algorithm::equal(v.begin(), v.end(), l.begin()));
    assert(stl_algorithm::equal(l.begin(), l.end(), v.begin()));
}

} // namespace test
} // namespace stl_algorithm
