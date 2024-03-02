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
  identity_transformation_does_not_transform_vector
) {
  const auto transform = Transform::identity();
  const Vec3
    vector {1.0f, -2.0f, 3.0f},
    transformed = transform.transform(vector);
  EXPECT_EQ(transformed, vector);
}

TEST(
  TestTransform,
  translation_moves_vector
) {
  const auto transform = Transform::translation({5.0f, -3.0f, 10.0f});
  const Vec3
    vector {1.0f, 2.0f, -3.0f},
    transformed = transform.transform(vector),
    expected {6.0f, -1.0f, 7.0f};
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  scale_with_scalar_transforms_vector_uniformly
) {
  const auto transform = Transform::scale(3.0f);
  const Vec3
    vector {1.0f, -2.0f, 3.0f},
    transformed = transform.transform(vector),
    expected {3.0f, -6.0f, 9.0f};
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  scale_with_vector_transforms_vector_componentwise
) {
  const auto transform = Transform::scale({10.0f, 20.0f, 30.0f});
  const Vec3
    vector {1.0f, -2.0f, 3.0f},
    transformed = transform.transform(vector),
    expected {10.0f, -40.0f, 90.0f};
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

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
  positive_y_rotated_half_pi_rad_around_x_results_in_positive_z
) {
  const auto transform = Transform
    ::euler_rotation_x(0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_y,
    transformed = transform.transform(vector),
    expected    = positive_z;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_y_rotated_negative_half_pi_rad_around_x_results_in_negative_z
) {
  const auto transform = Transform
    ::euler_rotation_x(-0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_y,
    transformed = transform.transform(vector),
    expected    = negative_z;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_z_rotated_half_pi_rad_around_x_results_in_negative_y
) {
  const auto transform = Transform
    ::euler_rotation_x(0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_z,
    transformed = transform.transform(vector),
    expected    = negative_y;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_z_rotated_negative_half_pi_rad_around_x_results_in_positive_y
) {
  const auto transform = Transform
    ::euler_rotation_x(-0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_z,
    transformed = transform.transform(vector),
    expected    = positive_y;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_x_rotated_half_pi_rad_around_y_results_in_negative_z
) {
  const auto transform = Transform
    ::euler_rotation_y(0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_x,
    transformed = transform.transform(vector),
    expected    = negative_z;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_x_rotated_negative_half_pi_rad_around_y_results_in_positive_z
) {
  const auto transform = Transform
    ::euler_rotation_y(-0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_x,
    transformed = transform.transform(vector),
    expected    = positive_z;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_y_rotated_half_pi_rad_around_y_results_in_positive_y
) {
  const auto transform = Transform
    ::euler_rotation_y(0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_y,
    transformed = transform.transform(vector),
    expected    = positive_y;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_y_rotated_negative_half_pi_rad_around_y_results_in_positive_y
) {
  const auto transform = Transform
    ::euler_rotation_y(-0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_y,
    transformed = transform.transform(vector),
    expected    = positive_y;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_z_rotated_half_pi_rad_around_y_results_in_positive_x
) {
  const auto transform = Transform
    ::euler_rotation_y(0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_z,
    transformed = transform.transform(vector),
    expected    = positive_x;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_z_rotated_negative_half_pi_rad_around_y_results_in_negative_x
) {
  const auto transform = Transform
    ::euler_rotation_y(-0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_z,
    transformed = transform.transform(vector),
    expected    = negative_x;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_x_rotated_half_pi_rad_around_z_results_in_positive_y
) {
  const auto transform = Transform
    ::euler_rotation_z(0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_x,
    transformed = transform.transform(vector),
    expected    = positive_y;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_x_rotated_negative_half_pi_rad_around_z_results_in_negative_y
) {
  const auto transform = Transform
    ::euler_rotation_z(-0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_x,
    transformed = transform.transform(vector),
    expected    = negative_y;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_y_rotated_half_pi_rad_around_z_results_in_negative_x
) {
  const auto transform = Transform
    ::euler_rotation_z(0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_y,
    transformed = transform.transform(vector),
    expected    = negative_x;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_y_rotated_negative_half_pi_rad_around_z_results_in_positive_x
) {
  const auto transform = Transform
    ::euler_rotation_z(-0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_y,
    transformed = transform.transform(vector),
    expected    = positive_x;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_z_rotated_half_pi_rad_around_z_results_in_positive_z
) {
  const auto transform = Transform
    ::euler_rotation_z(0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_z,
    transformed = transform.transform(vector),
    expected    = positive_z;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  positive_z_rotated_negative_half_pi_rad_around_z_results_in_positive_z
) {
  const auto transform = Transform
    ::euler_rotation_z(-0.5f * constants::pi<F32>);
  const Vec3
    vector      = positive_z,
    transformed = transform.transform(vector),
    expected    = positive_z;
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  points_transformed_by_orthographic_projection
) {
  const auto transform = Transform
    ::orthographic({-1.0f, -1.0f, -1.0f}, {1.0f, 1.0f, 1.0f});
  const Vec3
    vector      = {0.5f, 0.5f, 0.5f},
    transformed = transform.transform(vector),
    expected    = vector;
  EXPECT_VEC3_NEAR(vector, expected, epsilon);
}

TEST(
  TestTransform,
  composition_with_operator_of_two_transformations_composes_left_to_right
) {
  const auto transform
    =  Transform::identity()
    >> Transform::euler_rotation_x(0.5f  * constants::pi<F32>)
    >> Transform::translation({1.0f, 1.0f, 0.0f})
    >> Transform::scale(-0.5f);
  const Vec3
    vector      = positive_y,
    transformed = transform.transform(vector),
    expected    = {-0.5f, -0.5f, -0.5f};
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}

TEST(
  TestTransform,
  composition_with_then_of_two_transformations_composes_left_to_right
) {
  const auto transform
    = Transform::identity()
    .then(Transform::euler_rotation_x(0.5f  * constants::pi<F32>))
    .then(Transform::translation({1.0f, 1.0f, 0.0f}))
    .then(Transform::scale(-0.5f));
  const Vec3
    vector      = positive_y,
    transformed = transform.transform(vector),
    expected    = {-0.5f, -0.5f, -0.5f};
  EXPECT_VEC3_NEAR(transformed, expected, epsilon);
}
