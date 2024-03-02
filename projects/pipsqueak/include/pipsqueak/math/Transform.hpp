#pragma once

#include "pipsqueak/math/Mat4x4.hpp"
#include "pipsqueak/math/Vec2.hpp"
#include "pipsqueak/math/Vec3.hpp"

namespace pipsqueak::math {

  struct Transform {
    Transform() = default;

    explicit constexpr Transform(const Mat4x4& matrix)
      : m_matrix(matrix)
    {}

    [[nodiscard]]
    inline constexpr const Mat4x4& matrix() const {
      return m_matrix;
    }

    [[nodiscard]]
    inline static constexpr Transform translation(const Vec3& translation) {
      return Transform({
        {1.0f, 0.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 1.0f, 0.0f},
        {translation.x, translation.y, translation.z, 1.0f},
      });
    }

    [[nodiscard]]
    inline static constexpr Transform scale(F32 scalar) {
      return Transform(scalar * Mat4x4::identity());
    }

    [[nodiscard]]
    inline static constexpr Transform scale(const Vec3& scales) {
      return Transform({
        scales.x, 0.0f,     0.0f,     0.0f,
        0.0f,     scales.y, 0.0f,     0.0f,
        0.0f,     0.0f,     scales.z, 0.0f,
        0.0f,     0.0f,     0.0f,     0.0f,
      });
    }

    [[nodiscard]]
    inline static Transform euler_rotation_x(F32 angle) {
      const F32 cos = math::cos(angle);
      const F32 sin = math::sin(angle);
      return Transform({
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f,  cos,  sin, 0.0f,
        0.0f, -sin,  cos, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
      });
    }

    [[nodiscard]]
    inline static Transform euler_rotation_y(F32 angle) {
      const F32 cos = math::cos(angle);
      const F32 sin = math::sin(angle);
      return Transform({
         cos, 0.0f, -sin, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
         sin, 0.0f,  cos, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
      });
    }

    [[nodiscard]]
    inline static Transform euler_rotation_z(F32 angle) {
      const F32 cos = math::cos(angle);
      const F32 sin = math::sin(angle);
      return Transform({
         cos,  sin, 0.0f, 0.0f,
        -sin,  cos, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
      });
    }

    [[nodiscard]]
    inline Vec2 transform(const Vec2& vector) const {
      const Vec4 transformed = m_matrix * Vec4{vector.x, vector.y, 0.0f, 1.0f};
      return {transformed.x, transformed.y};
    }

    [[nodiscard]]
    inline Vec3 transform(const Vec3& vector) const {
      const Vec4 transformed =
        m_matrix * Vec4{vector.x, vector.y, vector.z, 1.0f};
      return {transformed.x, transformed.y, transformed.z};
    }

    [[nodiscard]]
    inline friend Transform operator >> (const Transform& lhs, const Transform& rhs) {
        return Transform(rhs.matrix() * lhs.matrix());
    } 
  private:
    Mat4x4 m_matrix;
  };

}
