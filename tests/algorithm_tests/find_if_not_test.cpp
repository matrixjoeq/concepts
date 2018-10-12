
#include <cassert>
#include <vector>
#include <functional>
#include "algorithm/find_if_not.hpp"

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

void find_if_not_check()
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

    assert(stl_algorithm::find_if_not(first, last, func) == last);
    assert(stl_algorithm::find_if_not(first, last, pred) == last);
    assert(stl_algorithm::find_if_not(first, last, functor) == last);
    assert(stl_algorithm::find_if_not(first, last, binder) == last);
    assert(stl_algorithm::find_if_not(first, last, lambda) == last);

    assert(stl_algorithm::find_if_not(v.begin(), v.end(), is_positive) == last);
    assert(stl_algorithm::find_if_not(v.begin(), v.end(), IsPositive()) == last);
    assert(stl_algorithm::find_if_not(v.begin(), v.end(), std::function<decltype(is_positive)>(is_positive)) == last);
    assert(stl_algorithm::find_if_not(v.begin(), v.end(), std::bind(is_positive, _1)) == last);
    assert(stl_algorithm::find_if_not(v.begin(), v.end(), std::bind(&IsPositive::operator(), &pred, _1)) == last);
    assert(stl_algorithm::find_if_not(v.begin(), v.end(), [](int i){ return is_positive(i); }) == last);
}

} // namespace test
} // namespace stl_algorithm
