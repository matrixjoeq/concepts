/** @file */
#ifndef __STL_CONCEPT_ASSIGNABLE_HPP__
#define __STL_CONCEPT_ASSIGNABLE_HPP__

#include "concept/same.hpp"
#include <utility>
#include <type_traits>
#include <boost/concept/usage.hpp>
#include <boost/concept/detail/concept_def.hpp>

#if (defined _MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4197) // topmost volatile ignored
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // object 'class' can never be instantiated - user-defined constructor required
#endif

namespace stl_concept {

/**
 * @addtogroup core_group Core Language Concepts
 * @struct Assignable
 * @brief Specifies that an expression of the type and value category specified by RHS can be assigned to an lvalue
 * expression whose type is specified by LHS.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type LHS and type RHS satisfies <i>Assignable</i> if<br/>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>lhs, an lvalue that refers to an object lcopy such that decltype((lhs)) is LHS</li>
 *   <li>rhs, an expression such that decltype((rhs)) is RHS</li>
 *   <li>rcopy, a distinct object that is equal to rhs</li>
 * </ul>
 * <i>Assignable</i> is satisfied only if
 * <ul style="list-style-type:disc">
 *   <li>std::addressof(lhs = rhs) == std::addressof(lcopy)</li>
 *   <li>After evaluating lhs = rhs:</li>
 *     <ul style="list-style-type:disc">
 *       <li>lhs is equal to rcopy, unless rhs is a non-const xvalue that refers to lcopy</li>
 *       <li>if rhs is a glvalue:</li>
 *         <ul style="list-style-type:disc">
 *           <li>If it is a non-const xvalue, the object to which it refers is in a valid but unspecified state</li>
 *           <li>Otherwise, the object it refers to is not modified</li>
 *         </ul>
 *     </ul>
 * </ul>
 * </p>
 * @tparam LHS - left operand type
 * @tparam RHS - right operand type
 * @see https://en.cppreference.com/w/cpp/concepts/Assignable
 */
#ifdef DOXYGEN_WORKING
template <typename LHS, typename RHS>
struct Assignable {};
#else // DOXYGEN_WORKING
BOOST_concept(Assignable, (LHS)(RHS))
{
    BOOST_CONCEPT_USAGE(Assignable)
    {
        static_assert(std::is_lvalue_reference<LHS>::value, "LHS must be an lvalue reference");
        assignable_constraints(lhs_, rhs_);
        assignable_constraints(lhs_, std::move(rhs_));
    }

private:
    Assignable();

    template <typename _LHS, typename _RHS>
    void assignable_constraints(_LHS& lhs, _RHS&& rhs)
    {
        lhs = std::forward<_RHS>(rhs);
        BOOST_CONCEPT_ASSERT((Same<decltype(lhs = std::forward<_RHS>(rhs)), _LHS&>));
    }

    LHS lhs_;
    RHS rhs_;
};
#endif // DOXYGEN_WORKING

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_ASSIGNABLE_HPP__
