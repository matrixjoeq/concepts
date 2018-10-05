
#include "util.h"

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

    // iterator group
    iterator_check();
    input_iterator_check();

    return 0;
}
