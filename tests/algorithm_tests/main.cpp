
#include "util.h"

int main()
{
    using namespace stl_algorithm::test;

    all_of_check();
    any_of_check();
    none_of_check();
    for_each_check();
    count_check();
    count_if_check();
    mismatch_check();
    mismatch_if_check();
    equal_check();
    equal_if_check();

    return 0;
}
