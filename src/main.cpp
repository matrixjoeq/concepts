
#include <utility>
#include "util.h"

struct Test
{
    void operator()() {}
    void operator()(int) {}
};

template <class... Ts>
using Op = auto(Ts...) -> decltype(std::declval<Test>()(std::declval<Ts>()...));

using _Op = Op<>;
using _Op_ = Op<int>;

int main()
{
    using namespace stl_concept::test;

    // basic group
    default_constructible_check();
    move_constructible_check();
    copy_constructible_check();
    move_assignable_check();
    copy_assignable_check();

    // library-wide group
    equality_comparable_check();
    less_comparable_check();
    swappable_check();
    value_swappable_check();
    nullable_pointer_check();
    function_object_check();

    // iterator group
    iterator_check();
    input_iterator_check();

    return 0;
}
