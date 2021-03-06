
#include <exception>
#include <memory>
#include <scoped_allocator>
#include "util.h"
#include "concept/nullable_pointer.hpp"

namespace stl_concept {
namespace test {
namespace {

using PointerTL = mpl::vector<
    DefaultType*,
    const DefaultType*,
    volatile DefaultType*,
    const volatile DefaultType*,
    //DefaultType* const,
    DefaultType* volatile,
    //DefaultType* const volatile,
    NullablePointerType,
    std::unique_ptr<DefaultType>::pointer,
    std::shared_ptr<DefaultType>,
    std::allocator<DefaultType>::pointer,
    std::allocator<DefaultType>::const_pointer,
    std::scoped_allocator_adaptor<std::allocator<DefaultType>>::pointer,
    std::scoped_allocator_adaptor<std::allocator<DefaultType>>::const_pointer,
    std::scoped_allocator_adaptor<std::allocator<DefaultType>>::void_pointer,
    std::scoped_allocator_adaptor<std::allocator<DefaultType>>::const_void_pointer,
    std::exception_ptr
>;

struct ConceptChecker
{
    template <class T>
    void operator()(T&)
    {
        BOOST_CONCEPT_ASSERT((stl_concept::NullablePointer<T>));
    }
};

} // namespace

void nullable_pointer_check()
{
    mpl::for_each<PointerTL>(ConceptChecker());
}

} // namespace test
} // namespace stl_concept
