
#ifndef __STL_CONCEPT_TESTS_UTIL_H__
#define __STL_CONCEPT_TESTS_UTIL_H__

#include <iostream>
#include <boost/static_assert.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/concept/assert.hpp>
#include <boost/concept_check.hpp>

namespace mpl = boost::mpl;

namespace stl_concept {
namespace test {

struct DefaultType {};

struct StreamType
{
    friend std::ostream& operator<<(std::ostream& os, const StreamType&)
    {
        return os;
    }

    friend std::istream& operator>>(std::istream& is, StreamType&)
    {
        return is;
    }
};

struct EqualType
{
    friend bool operator==(const EqualType&, const EqualType&)
    {
        return true;
    }

    friend bool operator!=(const EqualType&, const EqualType&)
    {
        return true;
    }
};

struct LessType
{
    friend bool operator<(const LessType&, const LessType&)
    {
       return true;
    }
};

struct NullablePointerType
{
    NullablePointerType(std::nullptr_t = nullptr) {}

    explicit operator bool()
    {
        return true;
    }

    friend bool operator==(const NullablePointerType&, const NullablePointerType&)
    {
        return true;
    }

    friend bool operator!=(const NullablePointerType&, const NullablePointerType&)
    {
        return true;
    }
};

template <class T>
struct HashFunctor;

template <>
struct HashFunctor<DefaultType>
{
    std::size_t operator()(const DefaultType&) const noexcept
    {
        return 0;
    }
};

// core group
void default_constructible_check();
void move_constructible_check();
void copy_constructible_check();
void move_assignable_check();
void copy_assignable_check();
void assignable_check();
void swappable_check();

// object group
void movable_check();

// library-wide group
void equality_comparable_check();
void less_comparable_check();
void value_swappable_check();
void nullable_pointer_check();
void function_object_check();
void unary_predicate_check();
void unary_function_check();
void binary_predicate_check();
void binary_function_check();

// iterator group
void iterator_check();
void input_iterator_check();
void output_iterator_check();

} // namespace test
} // namespace stl_concept

#endif  // __STL_CONCEPT_TESTS_UTIL_H__
