
#include "util.h"

namespace stl_concept {
namespace test {

bool operator==(const EqualType&, const EqualType&)
{
    return true;
}

bool operator<(const LessType&, const LessType&)
{
    return true;
}

} // namespace test
} // namespace stl_concept
