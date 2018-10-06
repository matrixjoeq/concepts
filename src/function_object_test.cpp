
#include <functional>
#include "util.h"

namespace stl_concept {
namespace test {
namespace {

struct ClassWithMemberFunction
{
    void foo() {}
    void bar(int, long) {}
};

using FunctorTL = mpl::vector<
    void(*)(void),
    void(*)(int, long),
    void(* const)(void),
    void(* const)(int, long),
    std::function<void()>,
    std::function<void(int, long)>/*,
    decltype(std::mem_fn(&ClassWithMemberFunction::foo)),
    decltype(std::mem_fn(&ClassWithMemberFunction::bar))*/
>;

struct ConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        BOOST_CONCEPT_ASSERT((stl_concept::FunctionObject<T>));
    }
};

} // namespace

void function_object_check()
{
    mpl::for_each<FunctorTL>(ConceptChecker());
}

} // namespace test
} // namespace stl_concept