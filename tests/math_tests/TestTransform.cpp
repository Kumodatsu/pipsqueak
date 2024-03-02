#include "Test.hpp"

#include <gtest/gtest.h>
#include <pipsqueak/math/Transform.hpp>

#include <limits>

using namespace pipsqueak;
using namespace pipsqueak::math;

// Some tests must be done with epsilon comparison instead of ULP comparison,
// due to issues with values near zero.
static constexpr F32 epsilon = std::numeric_limits<F32>::epsilon();

static constexpr Vec3
    positive_x { 1.0f,  0.0f,  0.0f},
    negative_x {-1.0f,  0.0f,  0.0f},
    positive_y { 0.0f,  1.0f,  0.0f},
    negative_y { 0.0f, -1.0f,  0.0f},
    positive_z { 0.0f,  0.0f,  1.0f},
    negative_z { 0.0f,  0.0f, -1.0f};

TEST(
  TestTransform,
  positive_x_rotated_half_pi_rad_around_x_results_in_positive_x
) {
  const auto transform = Transform
    ::euler_rotation_x(0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_x,
    transformed = transform.transform(vector),
    expected    = positive_x;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_x_rotated_negative_half_pi_rad_around_x_results_in_positive_x
) {
  const auto transform = Transform
    ::euler_rotation_x(-0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_x,
    transformed = transform.transform(vector),
    expected    = positive_x;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_y_rotated_half_pi_rad_around_x_results_in_negative_z
) {
  const auto transform = Transform
    ::euler_rotation_x(0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_y,
    transformed = transform.transform(vector),
    expected    = negative_z;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_y_rotated_negative_half_pi_rad_around_x_results_in_positive_z
) {
  const auto transform = Transform
    ::euler_rotation_x(-0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_y,
    transformed = transform.transform(vector),
    expected    = positive_z;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_z_rotated_half_pi_rad_around_x_results_in_positive_y
) {
  const auto transform = Transform
    ::euler_rotation_x(0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_z,
    transformed = transform.transform(vector),
    expected    = positive_y;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_z_rotated_negative_half_pi_rad_around_x_results_in_negative_y
) {
  const auto transform = Transform
    ::euler_rotation_x(-0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_z,
    transformed = transform.transform(vector),
    expected    = negative_y;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_y_rotated_around_positive_x_then_positive_y_results_in_negative_x
) {
  const auto transform
    =  Transform::euler_rotation_x(0.5f * constants::pi<F32>)
    >> Transform::euler_rotation_y(0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_y,
    transformed = transform.transform(vector),
    expected    = negative_x;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}
