
#include <cassert>
#include <vector>
#include <functional>
#include "algorithm/any_of.hpp"

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

void any_of_check()
{
    std::vector<int> v{-1, 2, -3};

    IsPositive pred;
    auto func = is_positive;
    auto functor = std::function<decltype(is_positive)>(is_positive);
    auto binder = std::bind(is_positive, std::placeholders::_1);
    auto first = v.begin();
    auto last = v.end();
    auto lambda = [](int i) { return is_positive(i); };

    assert(stl_algorithm::any_of(first, last, func));
    assert(stl_algorithm::any_of(first, last, pred));
    assert(stl_algorithm::any_of(first, last, functor));
    assert(stl_algorithm::any_of(first, last, binder));
    assert(stl_algorithm::any_of(first, last, lambda));

    assert(stl_algorithm::any_of(v.begin(), v.end(), is_positive));
    assert(stl_algorithm::any_of(v.begin(), v.end(), IsPositive()));
    assert(stl_algorithm::any_of(v.begin(), v.end(), std::function<decltype(is_positive)>(is_positive)));
    assert(stl_algorithm::any_of(v.begin(), v.end(), std::bind(is_positive, std::placeholders::_1)));
    assert(stl_algorithm::any_of(v.begin(), v.end(), std::bind(&IsPositive::operator(), &pred, std::placeholders::_1)));
    assert(stl_algorithm::any_of(v.begin(), v.end(), [](int i){ return is_positive(i); }));
}

} // namespace test
} // namespace stl_algorithm
