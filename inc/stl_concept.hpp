/**
 * @file
 * @brief Classes in this file define named requirements used in the normative text of the C++ standard library.
 * @author Qu Xing
 * @version 0.1
 * @date 2018
 * @copyright MIT License
 */

#ifndef __STL_CONCEPT_HPP__
#define __STL_CONCEPT_HPP__

#include "concept/derived_from.hpp"
#include "concept/same.hpp"
#include "concept/integral.hpp"
#include "concept/signed_integral.hpp"
#include "concept/unsigned_integral.hpp"
#include "concept/referenceable.hpp"
#include "concept/dereferenceable.hpp"
#include "concept/default_constructible.hpp"
#include "concept/move_constructible.hpp"
#include "concept/copy_constructible.hpp"
#include "concept/move_assignable.hpp"
#include "concept/copy_assignable.hpp"
#include "concept/destructible.hpp"
#include "concept/convertible_to.hpp"
#include "concept/assignable.hpp"
#include "concept/swappable_with.hpp"
#include "concept/swappable.hpp"
#include "concept/object.hpp"
#include "concept/movable.hpp"
#include "concept/copyable.hpp"
#include "concept/semiregular.hpp"
#include "concept/regular.hpp"
#include "concept/weakly_equality_comparable_with.hpp"
#include "concept/equality_comparable.hpp"
#include "concept/equality_comparable_with.hpp"
#include "concept/less_than_comparable.hpp"
#include "concept/value_swappable.hpp"
#include "concept/nullable_pointer.hpp"
#include "concept/function_object.hpp"
#include "concept/unary_predicate.hpp"
#include "concept/unary_function.hpp"
#include "concept/binary_predicate.hpp"
#include "concept/binary_function.hpp"
#include "concept/compare.hpp"
#include "concept/weakly_incrementable.hpp"
#include "concept/incrementable.hpp"
#include "concept/iterator.hpp"
#include "concept/input_iterator.hpp"
#include "concept/output_iterator.hpp"
#include "concept/forward_iterator.hpp"
#include "concept/mutable_forward_iterator.hpp"
#include "concept/bidirectional_iterator.hpp"
#include "concept/mutable_bidirectional_iterator.hpp"
#include "concept/random_access_iterator.hpp"
#include "concept/mutable_random_access_iterator.hpp"
#include "concept/default_insertable.hpp"
#include "concept/move_insertable.hpp"
#include "concept/copy_insertable.hpp"
#include "concept/emplace_insertable.hpp"
#include "concept/erasable.hpp"

#endif  // __STL_CONCEPT_HPP__
