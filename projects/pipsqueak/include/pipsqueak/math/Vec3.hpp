#pragma once

#include "pipsqueak/Common.hpp"
#include "pipsqueak/math/Functions.hpp"

#include <iosfwd>

namespace pipsqueak::math {

  struct alignas(4 * sizeof(F32)) Vec3 {
    inline static constexpr Count cardinality = 3;

    F32 x, y, z;

    Vec3() = default;
    constexpr Vec3(F32 x, F32 y, F32 z) : x(x), y(y), z(z), m_padding() {}

    [[nodiscard]]
    static inline constexpr Vec3 zero() {
      return {0.0f, 0.0f, 0.0f};
    }

    [[nodiscard]]
    inline constexpr F32& operator [] (Index i) { return *(&x + i); }
    
    [[nodiscard]]
    inline constexpr F32 operator [] (Index i) const { return *(&x + i); }

    [[nodiscard]]
    inline constexpr F32 squared_length() const {
      return x * x + y * y + z * z;
    }

    [[nodiscard]]
    inline constexpr F32 length() const {
      return math::sqrt(squared_length());
    }

    [[nodiscard]]
    inline constexpr F32 inverse_length() const {
      return 1.0f / length();
    }

    [[nodiscard]]
    inline constexpr Vec3 normalized() const {
      return inverse_length() * *this;
    }

    inline constexpr void normalize() {
      *this = normalized();
    }

    [[nodiscard]]
    inline constexpr friend bool operator == (const Vec3& lhs, const Vec3& rhs) {
      return lhs.x == rhs.x
        && lhs.y == rhs.y
        && lhs.z == rhs.z;
    }

    [[nodiscard]]
    inline constexpr friend bool operator != (const Vec3& lhs, const Vec3& rhs) {
      return lhs.x != rhs.x
        || lhs.y != rhs.y
        || lhs.z != rhs.z;
    }

    [[nodiscard]]
    inline constexpr friend Vec3 operator - (const Vec3& rhs) {
      return {-rhs.x, -rhs.y, -rhs.z};
    }

    [[nodiscard]]
    inline constexpr friend Vec3 operator * (const F32 lhs, const Vec3& rhs) {
      return {lhs * rhs.x, lhs * rhs.y, lhs * rhs.z};
    }

    [[nodiscard]]
    inline constexpr friend Vec3 operator * (const Vec3& lhs, const F32 rhs) {
      return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
    }

    [[nodiscard]]
    inline constexpr friend Vec3 operator / (const Vec3& lhs, const F32 rhs) {
      const F32 inverse_rhs = 1.0f / rhs;
      return {lhs.x * inverse_rhs, lhs.y * inverse_rhs, lhs.z * inverse_rhs};
    }

    [[nodiscard]]
    inline constexpr friend Vec3 operator + (const Vec3& lhs, const Vec3& rhs) {
      return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
    }

    [[nodiscard]]
    inline constexpr friend Vec3 operator - (const Vec3& lhs, const Vec3& rhs) {
      return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
    }

    [[nodiscard]]
    inline constexpr friend Vec3 operator * (const Vec3& lhs, const Vec3& rhs) {
      return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z};
    }

    [[nodiscard]]
    inline constexpr friend Vec3 operator / (const Vec3& lhs, const Vec3& rhs) {
      return {lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z};
    }
  private:
    F32 m_padding;
  };

  [[nodiscard]]
  inline constexpr F32 dot(const Vec3& lhs, const Vec3& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
  }

  [[nodiscard]]
  inline constexpr Vec3 cross(const Vec3& lhs, const Vec3& rhs) {
    return {
      lhs.y * rhs.z - lhs.z * rhs.y,
      lhs.z * rhs.x - lhs.x * rhs.z,
      lhs.x * rhs.y - lhs.y * rhs.x,
    };
  }

  std::ostream& operator << (std::ostream& stream, const Vec3& vector);

}
