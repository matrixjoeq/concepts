
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

struct IsPositive
{
    bool operator()(int i)
    {
        return is_positive(i);
    }
};

} // namespace

void all_of_check()
{
    std::vector<int> v{1, 2, 3};
    assert(std::all_of(v.begin(), v.end(), is_positive));
    assert(std::all_of(v.begin(), v.end(), IsPositive()));
}

} // namespace test
} // namespace stl_algorithm
