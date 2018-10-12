
#include "util.h"

int main()
{
    using namespace stl_concept::test;

    // These check functions are not necessary to be called, not even to be public.
    // However, linkage of these functions help to detect if certain concept check is missed.

    // core group
    default_constructible_check();
    move_constructible_check();
    copy_constructible_check();
    move_assignable_check();
    copy_assignable_check();
    assignable_check();
    swappable_check();

    // object group
    movable_check();
    copyable_check();

    // library-wide group
    equality_comparable_check();
    less_comparable_check();
    value_swappable_check();
    nullable_pointer_check();
    function_object_check();
    unary_predicate_check();
    unary_function_check();
    binary_predicate_check();
    binary_function_check();

    // iterator group
    iterator_check();
    input_iterator_check();
    output_iterator_check();
    forward_iterator_check();
    mutable_forward_iterator_check();

    return 0;
}
