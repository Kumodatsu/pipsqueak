#include "Test.hpp"

#include <gtest/gtest.h>
#include <pipsqueak/math/Vec3.hpp>

#include <sstream>

using namespace pipsqueak;
using namespace pipsqueak::math;

TEST(TestVec3, vec3_has_cardinality_three) {
  EXPECT_EQ(Vec3::cardinality, 3);
}

TEST(TestVec3, vectors_with_equal_components_are_equal) {
  const Vec3 vec_a(1.0f, 2.0f, 3.0f);
  const Vec3 vec_b(1.0f, 2.0f, 3.0f);
  EXPECT_TRUE(vec_a == vec_b);
}

TEST(TestVec3, vectors_with_unequal_components_are_not_equal) {
  const Vec3 vec_a(1.0f, 2.0f, 3.0f);
  const Vec3 vec_b(2.0f, 2.0f, 3.0f);
  EXPECT_FALSE(vec_a == vec_b);
}

TEST(TestVec3, vectors_with_equal_components_are_not_unequal) {
  const Vec3 vec_a(1.0f, 2.0f, 3.0f);
  const Vec3 vec_b(1.0f, 2.0f, 3.0f);
  EXPECT_FALSE(vec_a != vec_b);
}

TEST(TestVec3, vectors_with_unequal_components_are_unequal) {
  const Vec3 vec_a(1.0f, 2.0f, 3.0f);
  const Vec3 vec_b(2.0f, 2.0f, 3.0f);
  EXPECT_TRUE(vec_a != vec_b);
}

TEST(TestVec3, can_get_vector_element_by_index) {
  const Vec3 vec(1.0f, 2.0f, 3.0f);
  EXPECT_EQ(vec[0], 1.0f);
  EXPECT_EQ(vec[1], 2.0f);
  EXPECT_EQ(vec[2], 3.0f);
}

TEST(TestVec3, zero_creates_vector_with_all_elements_zero) {
  const Vec3 zero = Vec3::zero();
  EXPECT_EQ(zero.x, 0.0f);
  EXPECT_EQ(zero.y, 0.0f);
  EXPECT_EQ(zero.z, 0.0f);
}

TEST(TestVec3, squared_length_is_square_of_length) {
  const Vec3 vec(1.0f, 2.0f, 3.0f);
  const F32  squared_length = vec.squared_length();
  const F32  length         = vec.length();
  EXPECT_FLOAT_EQ(squared_length, length * length);
}

TEST(TestVec3, squared_length_is_dot_product_with_self) {
  const Vec3 vec(1.0f, 2.0f, 3.0f);
  const F32  squared_length = vec.squared_length();
  const F32  dot_product    = dot(vec, vec);
  EXPECT_FLOAT_EQ(squared_length, dot_product);
}

TEST(TestVec3, normalized_length_is_one) {
  const Vec3 vec(1.0f, 2.0f, 3.0f);
  const F32  normalized_length = vec.normalized().length();
  EXPECT_FLOAT_EQ(normalized_length, 1.0f);
}

TEST(TestVec3, normalizing_vector_has_same_result_as_normalized_vector) {
  Vec3 vec(1.0f, 2.0f, 3.0f);
  const Vec3 normalized = vec.normalized();
  vec.normalize();
  EXPECT_VEC3_EQ(vec, normalized);
}

TEST(TestVec3, dot_product_of_parallel_unit_vectors_in_same_direction_is_one) {
  const Vec3 vec_a(1.0f, 0.0f, 0.0f);
  const Vec3 vec_b(1.0f, 0.0f, 0.0f);
  const F32  dot_product = dot(vec_a, vec_b);
  EXPECT_FLOAT_EQ(dot_product, 1.0f);
}

TEST(TestVec3, dot_product_of_orthogonal_unit_vectors_is_zero) {
  const Vec3 vec_a(1.0f, 0.0f, 0.0f);
  const Vec3 vec_b(0.0f, 1.0f, 0.0f);
  const F32  dot_product = dot(vec_a, vec_b);
  EXPECT_FLOAT_EQ(dot_product, 0.0f);
}

TEST(
  TestVec3,
  dot_product_of_parallel_unit_vectors_in_opposite_direction_is_negative_one
) {
  const Vec3 vec_a( 1.0f, 0.0f, 0.0f);
  const Vec3 vec_b(-1.0f, 0.0f, 0.0f);
  const F32  dot_product = dot(vec_a, vec_b);
  EXPECT_FLOAT_EQ(dot_product, -1.0f);
}

TEST(
  TestVec3, cross_product_of_orthogonal_unit_vectors_is_orthogonal_to_both
) {
  const Vec3 vec_a(1.0f, 0.0f, 0.0f);
  const Vec3 vec_b(0.0f, 1.0f, 0.0f);
  const Vec3 cross_product = cross(vec_a, vec_b);
  const Vec3 expected(0.0f, 0.0f, 1.0f);
  EXPECT_VEC3_EQ(cross_product, expected);
}

TEST(TestVec3, unary_minus_negates_vector) {
  const Vec3 vec(1.0f, -2.0f, 3.0f);
  const Vec3 negated_vec = -vec;
  const Vec3 expected(-1.0f, 2.0f, -3.0f);
  EXPECT_VEC3_EQ(negated_vec, expected);
}

TEST(TestVec3, scalar_vector_product_scales_up_vector) {
  const Vec3 vec(1.0f, -2.0f, 3.0f);
  const F32  scalar = 5.0f;
  const Vec3 scaled_vec = scalar * vec;
  const Vec3 expected(5.0f, -10.0f, 15.0f);
  EXPECT_VEC3_EQ(scaled_vec, expected);
}

TEST(TestVec3, vector_scalar_product_scales_up_vector) {
  const Vec3 vec(1.0f, -2.0f, 3.0f);
  const F32  scalar = 5.0f;
  const Vec3 scaled_vec = vec * scalar;
  const Vec3 expected(5.0f, -10.0f, 15.0f);
  EXPECT_VEC3_EQ(scaled_vec, expected);
}

TEST(TestVec3, scalar_vector_quotient_scales_down_vector) {
  const Vec3 vec(1.0f, -2.0f, 3.0f);
  const F32  scalar = 5.0f;
  const Vec3 scaled_vec = vec / scalar;
  const Vec3 expected(0.2f, -0.4f, 0.6f);
  EXPECT_VEC3_EQ(scaled_vec, expected);
}

TEST(TestVec3, vector_addition_adds_elements_componentwise) {
  const Vec3 vec_a(1.0f, -2.0f,  3.0f);
  const Vec3 vec_b(5.0f, 10.0f, 15.0f);
  const Vec3 actual = vec_a + vec_b;
  const Vec3 expected(6.0f, 8.0f, 18.0f);
  EXPECT_VEC3_EQ(actual, expected);
}

TEST(TestVec3, vector_addition_is_commutative) {
  const Vec3 vec_a(1.0f, -2.0f,  3.0f);
  const Vec3 vec_b(5.0f, 10.0f, 15.0f);
  EXPECT_VEC3_EQ(vec_a + vec_b, vec_b + vec_a);
}

TEST(TestVec3, vector_subtraction_subtracts_elements_componentwise) {
  const Vec3 vec_a(5.0f, -2.0f,  3.0f);
  const Vec3 vec_b(1.0f, 10.0f, 15.0f);
  const Vec3 actual = vec_a - vec_b;
  const Vec3 expected(4.0f, -12.0f, -12.0f);
  EXPECT_VEC3_EQ(actual, expected);
}

TEST(TestVec3, vector_subtraction_is_anticommutative) {
  const Vec3 vec_a(5.0f, -2.0f,  3.0f);
  const Vec3 vec_b(1.0f, 10.0f, 15.0f);
  EXPECT_VEC3_EQ(vec_a - vec_b, -(vec_b - vec_a));
}

TEST(TestVec3, vector_multiplication_multiplies_elements_componentwise) {
  const Vec3 vec_a(5.0f, -2.0f,  3.0f);
  const Vec3 vec_b(1.0f, 10.0f, 15.0f);
  const Vec3 actual = vec_a * vec_b;
  const Vec3 expected(5.0f, -20.0f, 45.0f);
  EXPECT_VEC3_EQ(actual, expected);
}

TEST(TestVec3, vector_multiplication_is_commutative) {
  const Vec3 vec_a(5.0f, -2.0f,  3.0f);
  const Vec3 vec_b(1.0f, 10.0f, 15.0f);
  EXPECT_VEC3_EQ(vec_a * vec_b, vec_b * vec_a);
}

TEST(TestVec3, vector_division_divides_elements_componentwise) {
  const Vec3 vec_a(5.0f, -2.0f,  3.0f);
  const Vec3 vec_b(1.0f, 10.0f, 15.0f);
  const Vec3 actual = vec_a / vec_b;
  const Vec3 expected(5.0f, -0.2f, 0.2f);
  EXPECT_VEC3_EQ(actual, expected);
}

TEST(TestVec3, vector_string_representation_is_parenthesized_components) {
  const Vec3 vec(5.0f, -2.0f, 3.0f);
  const std::string actual   = (std::stringstream() << vec).str();
  const std::string expected = "(5, -2, 3)";
  EXPECT_EQ(actual, expected);
}
