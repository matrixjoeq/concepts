
#include "util.h"

int main()
{
    using namespace stl_concept::test;
    default_constructible_check();
    move_constructible_check();
    copy_constructible_check();

    return 0;
}
