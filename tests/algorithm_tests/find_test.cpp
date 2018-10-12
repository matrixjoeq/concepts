
#include <cassert>
#include <vector>
#include "algorithm/find.hpp"

namespace stl_algorithm {
namespace test {

void find_check()
{
    std::vector<int> v{1, 2, 3};

    auto first = v.begin();
    auto last = v.end();
    auto lvalue = 1l;
    auto ivalue = 1;

    assert(stl_algorithm::find(first, last, lvalue) == first);
    assert(stl_algorithm::find(first, last, ivalue) == first);
    assert(stl_algorithm::find(v.begin(), v.end(), 1l) == first);
    assert(stl_algorithm::find(v.begin(), v.end(), 1) == first);
}

} // namespace test
} // namespace stl_algorithm
