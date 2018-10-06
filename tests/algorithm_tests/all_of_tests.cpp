
#include <cassert>
#include <vector>
#include "algorithm/all_of.hpp"

namespace stl_algorithm {
namespace test {
namespace {

bool is_positive(int i)
{
    return i > 0;
}

} // namespace

void all_of_check()
{
    std::vector<int> v{1, 2, 3};
    assert(stl_algorithm::all_of(v.begin(), v.end(), is_positive));
}

} // namespace test
} // namespace stl_algorithm
