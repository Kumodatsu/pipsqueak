#pragma once

#include "pipsqueak/Common.hpp"
#include "pipsqueak/math/Functions.hpp"

namespace pipsqueak::math {

  struct alignas(2 * sizeof(F32)) Vec2 {
    inline static constexpr Count cardinality = 2;

    F32 x, y;

    Vec2() = default;
    constexpr Vec2(F32 x, F32 y) : x(x), y(y) {}

    [[nodiscard]]
    inline constexpr F32& operator [] (Index i) { return *(&x + i); }
    
    [[nodiscard]]
    inline constexpr F32 operator [] (Index i) const { return *(&x + i); }

    [[nodiscard]]
    inline constexpr F32 squared_length() const {
      return x * x + y * y;
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
    Vec2 normalized() const {
      return inverse_length() * *this;
    }

    void normalize() {
      *this = normalized();
    }

    [[nodiscard]]
    inline constexpr friend Vec2 operator - (const Vec2& rhs) {
      return {-rhs.x, -rhs.y};
    }

    [[nodiscard]]
    inline constexpr friend Vec2 operator * (const F32 lhs, const Vec2& rhs) {
      return {lhs * rhs.x, lhs * rhs.y};
    }

    [[nodiscard]]
    inline constexpr friend Vec2 operator * (const Vec2& lhs, const F32 rhs) {
      return {lhs.x * rhs, lhs.y * rhs};
    }

    [[nodiscard]]
    inline constexpr friend Vec2 operator / (const Vec2& lhs, const F32 rhs) {
      const F32 inverse_rhs = 1.0f / rhs;
      return {lhs.x * inverse_rhs, lhs.y * inverse_rhs};
    }

    [[nodiscard]]
    inline constexpr friend Vec2 operator + (const Vec2& lhs, const Vec2& rhs) {
      return {lhs.x + rhs.x, lhs.y + rhs.y};
    }

    [[nodiscard]]
    inline constexpr friend Vec2 operator - (const Vec2& lhs, const Vec2& rhs) {
      return {lhs.x - rhs.x, lhs.y - rhs.y};
    }

    [[nodiscard]]
    inline constexpr friend Vec2 operator * (const Vec2& lhs, const Vec2& rhs) {
      return {lhs.x * rhs.x, lhs.y * rhs.y};
    }

    [[nodiscard]]
    inline constexpr friend Vec2 operator / (const Vec2& lhs, const Vec2& rhs) {
      return {lhs.x / rhs.x, lhs.y / rhs.y};
    }
  };

  [[nodiscard]]
  inline constexpr F32 dot(const Vec2& lhs, const Vec2& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
  }

}
