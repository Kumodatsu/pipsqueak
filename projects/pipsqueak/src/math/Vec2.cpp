#include "pipsqueak/math/Vec2.hpp"

#include <ostream>

namespace pipsqueak::math {

  std::ostream& operator << (std::ostream& stream, const Vec2& vector) {
    return stream << "(" << vector.x << ", " << vector.y << ")";
  }

}
