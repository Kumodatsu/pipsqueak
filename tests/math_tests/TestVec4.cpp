#include <gtest/gtest.h>
#include <pipsqueak/math/Vec4.hpp>

#include <sstream>

using namespace pipsqueak;
using namespace pipsqueak::math;

#define EXPECT_VEC4_EQ(LHS, RHS)                                               \
  do {                                                                         \
    const Vec4 lhs = (LHS);                                                    \
    const Vec4 rhs = (RHS);                                                    \
    EXPECT_FLOAT_EQ(lhs.x, rhs.x);                                             \
    EXPECT_FLOAT_EQ(lhs.y, rhs.y);                                             \
    EXPECT_FLOAT_EQ(lhs.z, rhs.z);                                             \
    EXPECT_FLOAT_EQ(lhs.w, rhs.w);                                             \
  } while (false)

TEST(TestVec4, vec4_has_cardinality_four) {
  EXPECT_EQ(Vec4::cardinality, 4);
}

TEST(TestVec4, can_get_vector_element_by_index) {
  const Vec4 vec(1.0f, 2.0f, 3.0f, 4.0f);
  EXPECT_EQ(vec[0], 1.0f);
  EXPECT_EQ(vec[1], 2.0f);
  EXPECT_EQ(vec[2], 3.0f);
  EXPECT_EQ(vec[3], 4.0f);
}

TEST(TestVec4, squared_length_is_square_of_length) {
  const Vec4 vec(1.0f, 2.0f, 3.0f, 4.0f);
  const F32  squared_length = vec.squared_length();
  const F32  length         = vec.length();
  EXPECT_FLOAT_EQ(squared_length, length * length);
}

TEST(TestVec4, squared_length_is_dot_product_with_self) {
  const Vec4 vec(1.0f, 2.0f, 3.0f, 4.0f);
  const F32  squared_length = vec.squared_length();
  const F32  dot_product    = dot(vec, vec);
  EXPECT_FLOAT_EQ(squared_length, dot_product);
}

TEST(TestVec4, normalized_length_is_one) {
  const Vec4 vec(1.0f, 2.0f, 3.0f, 4.0f);
  const F32  normalized_length = vec.normalized().length();
  EXPECT_FLOAT_EQ(normalized_length, 1.0f);
}

TEST(TestVec4, normalizing_vector_has_same_result_as_normalized_vector) {
  Vec4 vec(1.0f, 2.0f, 3.0f, 4.0f);
  const Vec4 normalized = vec.normalized();
  vec.normalize();
  EXPECT_VEC4_EQ(vec, normalized);
}

TEST(TestVec4, dot_product_of_parallel_unit_vectors_in_same_direction_is_one) {
  const Vec4 vec_a(1.0f, 0.0f, 0.0f, 0.0f);
  const Vec4 vec_b(1.0f, 0.0f, 0.0f, 0.0f);
  const F32  dot_product = dot(vec_a, vec_b);
  EXPECT_FLOAT_EQ(dot_product, 1.0f);
}

TEST(TestVec4, dot_product_of_orthogonal_unit_vectors_is_zero) {
  const Vec4 vec_a(1.0f, 0.0f, 0.0f, 0.0f);
  const Vec4 vec_b(0.0f, 1.0f, 0.0f, 0.0f);
  const F32  dot_product = dot(vec_a, vec_b);
  EXPECT_FLOAT_EQ(dot_product, 0.0f);
}

TEST(
  TestVec4,
  dot_product_of_parallel_unit_vectors_in_opposite_direction_is_negative_one
) {
  const Vec4 vec_a( 1.0f, 0.0f, 0.0f, 0.0f);
  const Vec4 vec_b(-1.0f, 0.0f, 0.0f, 0.0f);
  const F32  dot_product = dot(vec_a, vec_b);
  EXPECT_FLOAT_EQ(dot_product, -1.0f);
}

TEST(TestVec4, unary_minus_negates_vector) {
  const Vec4 vec(1.0f, -2.0f, 3.0f, -4.0f);
  const Vec4 negated_vec = -vec;
  const Vec4 expected(-1.0f, 2.0f, -3.0f, 4.0f);
  EXPECT_VEC4_EQ(negated_vec, expected);
}

TEST(TestVec4, scalar_vector_product_scales_up_vector) {
  const Vec4 vec(1.0f, -2.0f, 3.0f, -4.0f);
  const F32  scalar = 5.0f;
  const Vec4 scaled_vec = scalar * vec;
  const Vec4 expected(5.0f, -10.0f, 15.0f, -20.0f);
  EXPECT_VEC4_EQ(scaled_vec, expected);
}

TEST(TestVec4, vector_scalar_product_scales_up_vector) {
  const Vec4 vec(1.0f, -2.0f, 3.0f, -4.0f);
  const F32  scalar = 5.0f;
  const Vec4 scaled_vec = vec * scalar;
  const Vec4 expected(5.0f, -10.0f, 15.0f, -20.0f);
  EXPECT_VEC4_EQ(scaled_vec, expected);
}

TEST(TestVec4, scalar_vector_quotient_scales_down_vector) {
  const Vec4 vec(1.0f, -2.0f, 3.0f, -4.0f);
  const F32  scalar = 5.0f;
  const Vec4 scaled_vec = vec / scalar;
  const Vec4 expected(0.2f, -0.4f, 0.6f, -0.8f);
  EXPECT_VEC4_EQ(scaled_vec, expected);
}

TEST(TestVec4, vector_addition_adds_elements_componentwise) {
  const Vec4 vec_a(1.0f, -2.0f,  3.0f, -4.0f);
  const Vec4 vec_b(5.0f, 10.0f, 15.0f, 20.0f);
  const Vec4 actual = vec_a + vec_b;
  const Vec4 expected(6.0f, 8.0f, 18.0f, 16.0f);
  EXPECT_VEC4_EQ(actual, expected);
}

TEST(TestVec4, vector_addition_is_commutative) {
  const Vec4 vec_a(1.0f, -2.0f,  3.0f, -4.0f);
  const Vec4 vec_b(5.0f, 10.0f, 15.0f, 20.0f);
  EXPECT_VEC4_EQ(vec_a + vec_b, vec_b + vec_a);
}

TEST(TestVec4, vector_subtraction_subtracts_elements_componentwise) {
  const Vec4 vec_a(5.0f, -2.0f,  3.0f, -4.0f);
  const Vec4 vec_b(1.0f, 10.0f, 15.0f, 20.0f);
  const Vec4 actual = vec_a - vec_b;
  const Vec4 expected(4.0f, -12.0f, -12.0f, -24.0f);
  EXPECT_VEC4_EQ(actual, expected);
}

TEST(TestVec4, vector_subtraction_is_anticommutative) {
  const Vec4 vec_a(1.0f, -2.0f,  3.0f, -4.0f);
  const Vec4 vec_b(5.0f, 10.0f, 15.0f, 20.0f);
  EXPECT_VEC4_EQ(vec_a - vec_b, -(vec_b - vec_a));
}

TEST(TestVec4, vector_multiplication_multiplies_elements_componentwise) {
  const Vec4 vec_a(1.0f, -2.0f,  3.0f, -4.0f);
  const Vec4 vec_b(5.0f, 10.0f, 15.0f, 20.0f);
  const Vec4 actual = vec_a * vec_b;
  const Vec4 expected(5.0f, -20.0f, 45.0f, -80.0f);
  EXPECT_VEC4_EQ(actual, expected);
}

TEST(TestVec4, vector_multiplication_is_commutative) {
  const Vec4 vec_a(1.0f, -2.0f,  3.0f, -4.0f);
  const Vec4 vec_b(5.0f, 10.0f, 15.0f, 20.0f);
  EXPECT_VEC4_EQ(vec_a * vec_b, vec_b * vec_a);
}

TEST(TestVec4, vector_division_divides_elements_componentwise) {
  const Vec4 vec_a(5.0f, -2.0f,  3.0f, -4.0f);
  const Vec4 vec_b(1.0f, 10.0f, 15.0f, 20.0f);
  const Vec4 actual = vec_a / vec_b;
  const Vec4 expected(5.0f, -0.2f, 0.2f, -0.2f);
  EXPECT_VEC4_EQ(actual, expected);
}

TEST(TestVec4, vector_string_representation_is_parenthesized_components) {
  const Vec4 vec(5.0f, -2.0f, 3.0f, -4.0f);
  const std::string actual   = (std::stringstream() << vec).str();
  const std::string expected = "(5, -2, 3, -4)";
  EXPECT_EQ(actual, expected);
}
