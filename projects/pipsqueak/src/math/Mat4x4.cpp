#include "pipsqueak/math/Mat4x4.hpp"

#include <iostream>

namespace pipsqueak::math {

  std::ostream& operator << (std::ostream& stream, const Mat4x4& matrix) {
    return stream
      << "| "  << matrix(0, 0) << " " << matrix(0, 1)
      << " "   << matrix(0, 2) << " " << matrix(0, 3)
      << " | " << matrix(1, 0) << " " << matrix(1, 1)
      << " "   << matrix(1, 2) << " " << matrix(1, 3)
      << " | " << matrix(2, 0) << " " << matrix(2, 1)
      << " "   << matrix(2, 2) << " " << matrix(2, 3)
      << " | " << matrix(3, 0) << " " << matrix(3, 1)
      << " "   << matrix(3, 2) << " " << matrix(3, 3)
      << " |";
  }

}
