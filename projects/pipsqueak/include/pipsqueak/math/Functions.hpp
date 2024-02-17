#pragma once

#include "pipsqueak/Common.hpp"
#include <cmath>

namespace pipsqueak::math {

  template <Real T>
  inline constexpr T pi = 3.141592653589793238;

  template <Real T>
  inline T sin(T x) {
    return std::sin(x);
  }

  template <Real T>
  inline T cos(T x) {
    return ::cos(x);
  }

  template <Real T>
  inline T tan(T x) {
    return ::tan(x);
  }

  template <Real T>
  inline T asin(T x) {
    return ::asin(x);
  }

  template <Real T>
  inline T acos(T x) {
    return ::acos(x);
  }

  template <Real T>
  inline T atan(T x) {
    return ::atan(x);
  }

  template <Real T>
  inline T atan2(T y, T x) {
    return ::atan2(y, x);
  }

  template <Real T>
  inline T sqrt(T x) {
    return ::sqrt(x);
  }

}
