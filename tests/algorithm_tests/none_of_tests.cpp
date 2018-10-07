
#include <cassert>
#include <vector>
#include <functional>
#include "algorithm/none_of.hpp"

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

void none_of_check()
{
    std::vector<int> v{-1, -2, -3};
    IsPositive pred;
    assert(stl_algorithm::none_of(v.begin(), v.end(), is_positive));
    assert(stl_algorithm::none_of(v.begin(), v.end(), IsPositive()));
    assert(stl_algorithm::none_of(v.begin(), v.end(), std::bind(is_positive, std::placeholders::_1)));
    assert(stl_algorithm::none_of(v.begin(), v.end(), std::bind(&IsPositive::operator(), &pred, std::placeholders::_1)));
}

} // namespace test
} // namespace stl_algorithm
