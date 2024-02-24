#pragma once

#include "pipsqueak/Common.hpp"
#include "pipsqueak/math/Vec4.hpp"

#include <array>
#include <iosfwd>

namespace pipsqueak::math {

  struct alignas(16 * sizeof(F32)) Mat4x4 {
    inline static constexpr Count
      row_count    = 4,
      column_count = 4;

    std::array<Vec4, 4> columns;

    Mat4x4() = default;
    
    constexpr Mat4x4(
      F32 m00, F32 m01, F32 m02, F32 m03,
      F32 m10, F32 m11, F32 m12, F32 m13,
      F32 m20, F32 m21, F32 m22, F32 m23,
      F32 m30, F32 m31, F32 m32, F32 m33
    )
      : columns {{
        {m00, m10, m20, m30},
        {m01, m11, m21, m31},
        {m02, m12, m22, m32},
        {m03, m13, m23, m33},
      }}
    {}

    [[nodiscard]]
    static inline constexpr Mat4x4 zero() {
      return {
        0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,
      };
    }

    [[nodiscard]]
    static inline constexpr Mat4x4 identity() {
      return {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
      };
    }

    [[nodiscard]]
    inline constexpr F32& at(Index row, Index column) {
      return columns[column][row];
    }

    [[nodiscard]]
    inline constexpr F32 at(Index row, Index column) const {
      return columns[column][row];
    }

    [[nodiscard]]
    inline constexpr F32& operator () (Index row, Index column) {
      return at(row, column);
    }

    [[nodiscard]]
    inline constexpr F32 operator () (Index row, Index column) const {
      return at(row, column);
    }

    [[nodiscard]]
    inline constexpr Mat4x4 transposed() const {
      return {
        at(0, 0), at(1, 0), at(2, 0), at(3, 0),
        at(0, 1), at(1, 1), at(2, 1), at(3, 1),
        at(0, 2), at(1, 2), at(2, 2), at(3, 2),
        at(0, 3), at(1, 3), at(2, 3), at(3, 3),
      };
    }

    inline constexpr void transpose() {
      *this = transposed();
    }

    [[nodiscard]]
    inline constexpr friend bool operator == (
      const Mat4x4& lhs, const Mat4x4& rhs
    ) {
      return lhs.columns == rhs.columns;
    }

    [[nodiscard]]
    inline constexpr friend bool operator != (
      const Mat4x4& lhs, const Mat4x4& rhs
    ) {
      return lhs.columns != rhs.columns;
    }

    [[nodiscard]]
    inline constexpr friend Mat4x4 operator - (const Mat4x4& rhs) {
      return {
        -rhs(0, 0), -rhs(0, 1), -rhs(0, 2), -rhs(0, 3),
        -rhs(1, 0), -rhs(1, 1), -rhs(1, 2), -rhs(1, 3),
        -rhs(2, 0), -rhs(2, 1), -rhs(2, 2), -rhs(2, 3),
        -rhs(3, 0), -rhs(3, 1), -rhs(3, 2), -rhs(3, 3),
      };
    }

    [[nodiscard]]
    inline constexpr friend Mat4x4 operator * (
      const F32 lhs, const Mat4x4& rhs
    ) {
      return {
        lhs * rhs(0, 0), lhs * rhs(0, 1), lhs * rhs(0, 2), lhs * rhs(0, 3),
        lhs * rhs(1, 0), lhs * rhs(1, 1), lhs * rhs(1, 2), lhs * rhs(1, 3),
        lhs * rhs(2, 0), lhs * rhs(2, 1), lhs * rhs(2, 2), lhs * rhs(2, 3),
        lhs * rhs(3, 0), lhs * rhs(3, 1), lhs * rhs(3, 2), lhs * rhs(3, 3),
      };
    }

    [[nodiscard]]
    inline constexpr friend Mat4x4 operator * (
      const Mat4x4& lhs, const F32 rhs
    ) {
      return {
        lhs(0, 0) * rhs, lhs(0, 1) * rhs, lhs(0, 2) * rhs, lhs(0, 3) * rhs,
        lhs(1, 0) * rhs, lhs(1, 1) * rhs, lhs(1, 2) * rhs, lhs(1, 3) * rhs,
        lhs(2, 0) * rhs, lhs(2, 1) * rhs, lhs(2, 2) * rhs, lhs(2, 3) * rhs,
        lhs(3, 0) * rhs, lhs(3, 1) * rhs, lhs(3, 2) * rhs, lhs(3, 3) * rhs,
      };
    }

    [[nodiscard]]
    inline constexpr friend Mat4x4 operator / (
      const Mat4x4& lhs, const F32 rhs
    ) {
      const F32 inverse_rhs = 1.0f / rhs;
      return lhs * inverse_rhs;
    }

    [[nodiscard]]
    inline constexpr friend Mat4x4 operator + (
      const Mat4x4& lhs, const Mat4x4& rhs
    ) {
      return {
        lhs(0, 0) + rhs(0, 0), lhs(0, 1) + rhs(0, 1), lhs(0, 2) + rhs(0, 2),
          lhs(0, 3) + rhs(0, 3),
        lhs(1, 0) + rhs(1, 0), lhs(1, 1) + rhs(1, 1), lhs(1, 2) + rhs(1, 2),
          lhs(1, 3) + rhs(1, 3),
        lhs(2, 0) + rhs(2, 0), lhs(2, 1) + rhs(2, 1), lhs(2, 2) + rhs(2, 2),
          lhs(2, 3) + rhs(2, 3),
        lhs(3, 0) + rhs(3, 0), lhs(3, 1) + rhs(3, 1), lhs(3, 2) + rhs(3, 2),
          lhs(3, 3) + rhs(3, 3),
      };
    }

    [[nodiscard]]
    inline constexpr friend Mat4x4 operator - (
      const Mat4x4& lhs, const Mat4x4& rhs
    ) {
      return lhs + -rhs;
    }

    [[nodiscard]]
    inline constexpr friend Mat4x4 operator * (
      const Mat4x4& lhs, const Mat4x4& rhs
    ) {
      const auto transpose = lhs.transposed();
      Mat4x4 result;
      for (Index row = 0; row < Mat4x4::row_count; ++row) {
        for (Index col = 0; col < Mat4x4::column_count; ++col) {
          result(row, col) = dot(transpose.columns[row], rhs.columns[col]);  
        }
      }
      return result;
    }

    [[nodiscard]]
    inline constexpr friend Vec4 operator * (
      const Mat4x4& lhs, const Vec4& rhs
    ) {
      const auto transpose = lhs.transposed();
      return {
        dot(transpose.columns[0], rhs),
        dot(transpose.columns[1], rhs),
        dot(transpose.columns[2], rhs),
        dot(transpose.columns[3], rhs),
      };
    }
  };

  static_assert(sizeof(Mat4x4) == 16 * sizeof(F32));

  std::ostream& operator << (std::ostream& stream, const Mat4x4& matrix);

}
