
#include <cassert>
#include <vector>
#include <functional>
#include "algorithm/count_if.hpp"

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

void count_if_check()
{
    using namespace std::placeholders;

    std::vector<int> v{1, 2, 3};

    IsPositive pred;
    auto func = is_positive;
    auto functor = std::function<decltype(is_positive)>(is_positive);
    auto binder = std::bind(is_positive, _1);
    auto first = v.begin();
    auto last = v.end();
    auto lambda = [](int i) { return is_positive(i); };
    const auto number = 3;

    assert(stl_algorithm::count_if(first, last, func) == number);
    assert(stl_algorithm::count_if(first, last, pred) == number);
    assert(stl_algorithm::count_if(first, last, functor) == number);
    assert(stl_algorithm::count_if(first, last, binder) == number);
    assert(stl_algorithm::count_if(first, last, lambda) == number);

    assert(stl_algorithm::count_if(v.begin(), v.end(), is_positive) == number);
    assert(stl_algorithm::count_if(v.begin(), v.end(), IsPositive()) == number);
    assert(stl_algorithm::count_if(v.begin(), v.end(), std::function<decltype(is_positive)>(is_positive)) == number);
    assert(stl_algorithm::count_if(v.begin(), v.end(), std::bind(is_positive, _1)) == number);
    assert(stl_algorithm::count_if(v.begin(), v.end(), std::bind(&IsPositive::operator(), &pred, _1)) == number);
    assert(stl_algorithm::count_if(v.begin(), v.end(), [](int i){ return is_positive(i); }) == number);
}

} // namespace test
} // namespace stl_algorithm
