
#include <cassert>
#include <vector>
#include "algorithm/count.hpp"

namespace stl_algorithm {
namespace test {

void count_check()
{
    std::vector<int> v{1, 2, 3};

    auto first = v.begin();
    auto last = v.end();
    auto lvalue = 1l;
    auto ivalue = 1;
    const auto number = 1;

    assert(stl_algorithm::count(first, last, lvalue) == number);
    assert(stl_algorithm::count(first, last, ivalue) == number);
    assert(stl_algorithm::count(v.begin(), v.end(), 1l) == number);
    assert(stl_algorithm::count(v.begin(), v.end(), 1) == number);
}

} // namespace test
} // namespace stl_algorithm
