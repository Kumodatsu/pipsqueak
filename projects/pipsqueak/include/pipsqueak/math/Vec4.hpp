#pragma once

#include "pipsqueak/Common.hpp"
#include "pipsqueak/math/Functions.hpp"

namespace pipsqueak::math {

  struct alignas(4 * sizeof(F32)) Vec4 {
    inline static constexpr Count cardinality = 4;

    F32 x, y, z, w;

    Vec4() = default;
    constexpr Vec4(F32 x, F32 y, F32 z, F32 w) : x(x), y(y), z(z), w(w) {}

    [[nodiscard]]
    inline constexpr F32& operator [] (Index i) { return *(&x + i); }
    
    [[nodiscard]]
    inline constexpr F32 operator [] (Index i) const { return *(&x + i); }

    [[nodiscard]]
    inline constexpr F32 squared_length() const {
      return x * x + y * y + z * z + w * w;
    }

    [[nodiscard]]
    inline F32 length() const {
      return math::sqrt(squared_length());
    }

    [[nodiscard]]
    inline F32 inverse_length() const {
      return 1.0f / length();
    }

    [[nodiscard]]
    Vec4 normalized() const {
      return inverse_length() * *this;
    }

    void normalize() {
      *this = normalized();
    }

    [[nodiscard]]
    inline constexpr friend Vec4 operator - (const Vec4& rhs) {
      return {-rhs.x, -rhs.y, -rhs.z, -rhs.w};
    }

    [[nodiscard]]
    inline constexpr friend Vec4 operator * (const F32 lhs, const Vec4& rhs) {
      return {lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w};
    }

    [[nodiscard]]
    inline constexpr friend Vec4 operator * (const Vec4& lhs, const F32 rhs) {
      return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs};
    }

    [[nodiscard]]
    inline constexpr friend Vec4 operator / (const Vec4& lhs, const F32 rhs) {
      const F32 inverse_rhs = 1.0f / rhs;
      return {
        lhs.x * inverse_rhs,
        lhs.y * inverse_rhs,
        lhs.z * inverse_rhs,
        lhs.w * inverse_rhs,
      };
    }

    [[nodiscard]]
    inline constexpr friend Vec4 operator + (const Vec4& lhs, const Vec4& rhs) {
      return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w};
    }

    [[nodiscard]]
    inline constexpr friend Vec4 operator - (const Vec4& lhs, const Vec4& rhs) {
      return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w};
    }

    [[nodiscard]]
    inline constexpr friend Vec4 operator * (const Vec4& lhs, const Vec4& rhs) {
      return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w};
    }

    [[nodiscard]]
    inline constexpr friend Vec4 operator / (const Vec4& lhs, const Vec4& rhs) {
      return {lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w};
    }
  };

  [[nodiscard]]
  inline constexpr F32 dot(const Vec4& lhs, const Vec4& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
  }

}
