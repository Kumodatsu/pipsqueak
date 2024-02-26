#include "Test.hpp"

#include <gtest/gtest.h>
#include <pipsqueak/math/Transform.hpp>

#include <limits>

using namespace pipsqueak;
using namespace pipsqueak::math;

// Some tests must be done with epsilon comparison instead of ULP comparison,
// due to issues with values near zero.
static constexpr F32 epsilon = std::numeric_limits<F32>::epsilon();

TEST(
  TestTransform,
  positive_y_rotated_half_pi_rad_around_x_results_in_negative_z
) {
  const auto transform = Transform
    ::euler_rotation_x(0.5f * constants::pi<F32>);
  const Vec3 vector {0.0f, 1.0f, 0.0f};
  const Vec3 transformed = transform.transform(vector);
  const Vec3 expected {0.0f, 0.0f, -1.0f};
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_y_rotated_negative_half_pi_rad_around_x_results_in_positive_z
) {
  const auto transform = Transform
    ::euler_rotation_x(-0.5f * constants::pi<F32>);
  const Vec3 vector {0.0f, 1.0f, 0.0f};
  const Vec3 transformed = transform.transform(vector);
  const Vec3 expected {0.0f, 0.0f, 1.0f};
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}
