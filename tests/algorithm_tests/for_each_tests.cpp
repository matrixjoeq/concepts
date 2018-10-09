
#include <cassert>
#include <vector>
#include <functional>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <boost/type_traits/is_pointer.hpp>
#include "concept/detail/is_move_constructible.hpp"
#include "util.h"
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

template <class Vector>
void dump_vector(const Vector& v)
{
    auto first = v.begin();
    auto last = v.end();

    using ValueType = typename std::iterator_traits<decltype(first)>::value_type;
    auto print_value = [](ValueType v){ std::cout << v << ' '; };

    (void)(stl_algorithm::for_each(first, last, print_value));
    std::cout << std::endl;
}

} // namespace

void for_each_check()
{
    using namespace std::placeholders;

    std::vector<int> v{1, 2, 3};

    Increase functor;
    auto binder = std::bind(increase, _1);
    auto std_functor = std::function<decltype(increase)>(increase);
    auto lambda = [](int& i){ increase(i); };
    auto func_ptr = increase;
    static_assert(boost::is_pointer<decltype(func_ptr)>::value, "");
    static_assert(stl_concept::__detail::__is_move_constructible<decltype(lambda)>::value, "");

    auto first = v.begin();
    auto last = v.end();

    std::cout << "for_each_check" << std::endl;
    std::cout << "initial values: ";
    dump_vector(v);

    std::cout << "zeroth change: ";
    (void)(stl_algorithm::for_each(v.begin(), v.end(), [](int& i){ increase(i); }));
    dump_vector(v);

    std::cout << "first change: ";
    (void)(stl_algorithm::for_each(v.begin(), v.end(), increase));
    dump_vector(v);

    std::cout << "second change: ";
    (void)(stl_algorithm::for_each(v.begin(), v.end(), Increase()));
    dump_vector(v);

    std::cout << "third change: ";
    (void)(stl_algorithm::for_each(v.begin(), v.end(), std::bind(increase, _1)));
    dump_vector(v);

    std::cout << "fourth change: ";
    (void)(stl_algorithm::for_each(v.begin(), v.end(), std::bind(&Increase::operator(), &functor, _1)));
    dump_vector(v);

    std::cout << "fifth change: ";
    (void)(stl_algorithm::for_each(v.begin(), v.end(), std::function<decltype(increase)>(increase)));
    dump_vector(v);

    std::cout << "sixth change: ";
    (void)(stl_algorithm::for_each(first, last, func_ptr));
    dump_vector(v);

    std::cout << "seventh change: ";
    (void)(stl_algorithm::for_each(first, last, functor));
    dump_vector(v);

    std::cout << "eighth change: ";
    (void)(stl_algorithm::for_each(first, last, binder));
    dump_vector(v);

    std::cout << "ninth change: ";
    (void)(stl_algorithm::for_each(first, last, std_functor));
    dump_vector(v);

    std::cout << "tenth change: ";
    (void)(stl_algorithm::for_each(first, last, lambda));
    dump_vector(v);
}

} // namespace test
} // namespace stl_algorithm
