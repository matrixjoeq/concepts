
#include <cassert>
#include <vector>
#include <functional>
#include <iostream>
#include "algorithm/for_each.hpp"

namespace stl_algorithm {
namespace test {
namespace {

void increase(int& i)
{
    ++i;
}

struct Increase
{
    void operator()(int& i)
    {
        increase(i);
    }
};

} // namespace

void for_each_check()
{
    std::vector<int> v{1, 2, 3};
    Increase functor;

    auto print_value = [](int i){ std::cout << i << ' '; };

    std::cout << "for_each_check" << std::endl;
    std::cout << "initial values: ";
    (void)(stl_algorithm::for_each(v.begin(), v.end(), print_value));
    std::cout << std::endl;

    std::cout << "first change: ";
    (void)(stl_algorithm::for_each(v.begin(), v.end(), increase));
    (void)(stl_algorithm::for_each(v.begin(), v.end(), print_value));
    std::cout << std::endl;

    std::cout << "second change: ";
    (void)(stl_algorithm::for_each(v.begin(), v.end(), Increase()));
    (void)(stl_algorithm::for_each(v.begin(), v.end(), print_value));
    std::cout << std::endl;

    std::cout << "third change: ";
    (void)(stl_algorithm::for_each(v.begin(), v.end(), std::bind(increase, std::placeholders::_1)));
    (void)(stl_algorithm::for_each(v.begin(), v.end(), print_value));
    std::cout << std::endl;

    std::cout << "fourth change: ";
    (void)(stl_algorithm::for_each(v.begin(), v.end(), std::bind(&Increase::operator(), &functor, std::placeholders::_1)));
    (void)(stl_algorithm::for_each(v.begin(), v.end(), print_value));
    std::cout << std::endl;

    std::function<void(int&)> fn = increase;
    std::cout << "fifth change: ";
    (void)(stl_algorithm::for_each(v.begin(), v.end(), fn));
    (void)(stl_algorithm::for_each(v.begin(), v.end(), print_value));
    std::cout << std::endl;
}

} // namespace test
} // namespace stl_algorithm
