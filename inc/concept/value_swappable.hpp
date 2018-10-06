
#ifndef __STL_CONCEPT_VALUE_SWAPPABLE_HPP__
#define __STL_CONCEPT_VALUE_SWAPPABLE_HPP__

#include "concept/iterator.hpp"
#include "concept/swappable.hpp"
#include <boost/concept/usage.hpp>
#include <boost/concept/assert.hpp>
#include <boost/concept/detail/concept_def.hpp>

#if (defined _MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // object 'class' can never be instantiated - user-defined constructor required
#endif

namespace stl_concept {

/**
 * @addtogroup library_wide_group Library-wide Requirements
 * @class stl_concept::ValueSwappable
 * @brief Two objects of this type can be dereferenced and the resulting values can be swapped using
 * unqualified function call swap() in the context where both std::swap and the user-defined swap()s are visible.
 *
 * <p>
 * <b>Requirements</b>
 * </p><p>
 * The type T satisfies <i>ValueSwappable</i> if<br/>
 * Given
 * <ul style="list-style-type:disc">
 *   <li>T satisfies the <i>Iterator</i> requirements</li>
 *   <li>For any dereferencable object x of type T (that is, any value other than the end iterator),
 *       *x satisfies the <i>Swappable</i> requirements.</li>
 * </ul>
 * </p>
 * @tparam T - type to be checked
 * @see https://en.cppreference.com/w/cpp/named_req/ValueSwappable
 */
BOOST_concept(ValueSwappable, (T)) : Iterator<T>
{
    BOOST_CONCEPT_USAGE(ValueSwappable)
    {
        BOOST_CONCEPT_ASSERT((Swappable<decltype(*(boost::declval<T>()))>));
    }
};

} // namespace stl_concept

#if (defined _MSC_VER)
#pragma warning(pop)
#endif

#include <boost/concept/detail/concept_undef.hpp>

#endif  // __STL_CONCEPT_VALUE_SWAPPABLE_HPP__
