#include "pipsqueak/math/Vec3.hpp"

#include <ostream>

namespace pipsqueak::math {

  std::ostream& operator << (std::ostream& stream, const Vec3& vector) {
    return stream << "(" << vector.x << ", " << vector.y << ", " << vector.z
      << ")";
  }

}
