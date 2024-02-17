#pragma once

#include "pipsqueak/Common.hpp"
#include <cmath>
#include <limits>
#include <type_traits>

namespace pipsqueak::math {

  inline namespace constants {
    template <Real T>
    inline constexpr T infinity = std::numeric_limits<T>::infinity();

    template <Real T>
    inline constexpr T pi = static_cast<T>(3.141592653589793238);
  }

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
  inline constexpr T sqrt(T x) {
    if (std::is_constant_evaluated()) {
      if (x < static_cast<T>(0) || x >= constants::infinity<T>) {
        return std::numeric_limits<T>::quiet_NaN();
      }
      T current = x;
      for (T previous = static_cast<T>(0); current != previous; ) {
        previous = current;
        current  = static_cast<T>(0.5) * (current + x / current); 
      }
      return current;
    }
    return ::sqrt(x);
  }

}
