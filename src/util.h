
#ifndef __STL_CONCEPT_UTIL_H__
#define __STL_CONCEPT_UTIL_H__

#include <boost/mpl/at.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/concept/assert.hpp>
#include <boost/concept_check.hpp>

#include "stl_concept.hpp"

namespace mpl = boost::mpl;

namespace stl_concept {
namespace test {

struct DefaultType {};

struct EqualType
{
    friend bool operator==(const EqualType&, const EqualType&);
    friend bool operator!=(const EqualType&, const EqualType&);
};

struct LessType
{
    friend bool operator<(const LessType&, const LessType&);
};

// basic group
void default_constructible_check();
void move_constructible_check();
void copy_constructible_check();
void move_assignable_check();
void copy_assignable_check();

// library-wide group
void equality_comparable_check();
void less_comparable_check();

} // namespace test
} // namespace stl_concept

#endif  // __STL_CONCEPT_UTIL_H__
