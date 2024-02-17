#include "pipsqueak/math/Vec4.hpp"

#include <ostream>

namespace pipsqueak::math {

  std::ostream& operator << (std::ostream& stream, const Vec4& vector) {
    return stream
      << "("  << vector.x
      << ", " << vector.y
      << ", " << vector.z
      << ", " << vector.w
      << ")";
  }

}
