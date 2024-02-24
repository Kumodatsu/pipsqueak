#include <gtest/gtest.h>
#include <pipsqueak/math/Mat4x4.hpp>

#include <sstream>

using namespace pipsqueak;
using namespace pipsqueak::math;

#define EXPECT_MAT4X4_EQ(LHS, RHS)                                             \
  do {                                                                         \
    const Mat4x4 lhs = (LHS);                                                  \
    const Mat4x4 rhs = (RHS);                                                  \
    for (Index col = 0; col < 4; ++col) {                                      \
      for (Index row = 0; row < 4; ++row) {                                    \
        EXPECT_FLOAT_EQ(lhs.at(row, col), rhs.at(row, col))                    \
          << "row = " << row << "\n"                                           \
          << "col = " << col << "\n"                                           \
          << "lhs = " << lhs << "\n"                                           \
          << "rhs = " << rhs;                                                  \
      }                                                                        \
    }                                                                          \
  } while (false)

TEST(TestMat4x4, mat4x4_has_row_count_four) {
  EXPECT_EQ(Mat4x4::row_count, 4);
}

TEST(TestMat4x4, mat4x4_has_column_count_four) {
  EXPECT_EQ(Mat4x4::column_count, 4);
}

TEST(TestMat4x4, matrices_with_equal_elements_are_equal) {
  const Mat4x4 matrix_a {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  const Mat4x4 matrix_b {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  EXPECT_TRUE(matrix_a == matrix_b);
}

TEST(TestMat4x4, matrices_with_unequal_elements_are_not_equal) {
  const Mat4x4 matrix_a {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  const Mat4x4 matrix_b {
     2.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  EXPECT_FALSE(matrix_a == matrix_b);
}

TEST(TestMat4x4, matrices_with_equal_elements_are_not_unequal) {
  const Mat4x4 matrix_a {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  const Mat4x4 matrix_b {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  EXPECT_FALSE(matrix_a != matrix_b);
}

TEST(TestMat4x4, matrices_with_unequal_elements_are_unequal) {
  const Mat4x4 matrix_a {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  const Mat4x4 matrix_b {
     2.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  EXPECT_TRUE(matrix_a != matrix_b);
}

TEST(TestMat4x4, zero_creates_matrix_with_all_elements_zero) {
  const Mat4x4 zero = Mat4x4::zero();
  const Mat4x4 expected {
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
  };
  EXPECT_EQ(zero, expected);
}

TEST(TestMat4x4, identity_creates_identity_matrix) {
  const Mat4x4 identity = Mat4x4::identity();
  const Mat4x4 expected {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f,
  };
  EXPECT_EQ(identity, expected);
}

TEST(TestMat4x4, can_get_matrix_element_by_indices) {
  const Mat4x4 matrix {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  EXPECT_EQ(matrix.at(0, 0),  1.0f);
  EXPECT_EQ(matrix.at(0, 1),  2.0f);
  EXPECT_EQ(matrix.at(0, 2),  3.0f);
  EXPECT_EQ(matrix.at(0, 3),  4.0f);
  EXPECT_EQ(matrix.at(1, 0),  5.0f);
  EXPECT_EQ(matrix.at(1, 1),  6.0f);
  EXPECT_EQ(matrix.at(1, 2),  7.0f);
  EXPECT_EQ(matrix.at(1, 3),  8.0f);
  EXPECT_EQ(matrix.at(2, 0),  9.0f);
  EXPECT_EQ(matrix.at(2, 1), 10.0f);
  EXPECT_EQ(matrix.at(2, 2), 11.0f);
  EXPECT_EQ(matrix.at(2, 3), 12.0f);
  EXPECT_EQ(matrix.at(3, 0), 13.0f);
  EXPECT_EQ(matrix.at(3, 1), 14.0f);
  EXPECT_EQ(matrix.at(3, 2), 15.0f);
  EXPECT_EQ(matrix.at(3, 3), 16.0f);
}

TEST(TestMat4x4, can_set_matrix_element_by_indices) {
  Mat4x4 matrix {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  EXPECT_EQ(matrix.at(0, 0), 1.0f);
  matrix.at(0, 0) = 100.0f;
  EXPECT_EQ(matrix.at(0, 0), 100.0f);
}

TEST(TestMat4x4, transposed_gives_transpose_of_matrix) {
  const Mat4x4 matrix {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  const Mat4x4 transposed = matrix.transposed();
  const Mat4x4 expected {
     1.0f, 5.0f,  9.0f, 13.0f,
     2.0f, 6.0f, 10.0f, 14.0f,
     3.0f, 7.0f, 11.0f, 15.0f,
     4.0f, 8.0f, 12.0f, 16.0f,
  };
  EXPECT_EQ(transposed, expected);
}

TEST(TestMat4x4, transpose_transposes_matrix) {
  Mat4x4 matrix {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  matrix.transpose();
  const Mat4x4 expected {
     1.0f, 5.0f,  9.0f, 13.0f,
     2.0f, 6.0f, 10.0f, 14.0f,
     3.0f, 7.0f, 11.0f, 15.0f,
     4.0f, 8.0f, 12.0f, 16.0f,
  };
  EXPECT_EQ(matrix, expected);
}

TEST(TestMat4x4, unary_minus_negates_matrix) {
  const Mat4x4 matrix {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  const Mat4x4 negated = -matrix;
  const Mat4x4 expected {
     -1.0f,  -2.0f,  -3.0f,  -4.0f,
     -5.0f,  -6.0f,  -7.0f,  -8.0f,
     -9.0f, -10.0f, -11.0f, -12.0f,
    -13.0f, -14.0f, -15.0f, -16.0f,
  };
  EXPECT_MAT4X4_EQ(negated, expected);
}

TEST(TestMat4x4, scalar_matrix_product_scales_up_matrix) {
  const Mat4x4 matrix {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  const F32 scalar = 5.0f;
  const Mat4x4 scaled_matrix = scalar * matrix;
  const Mat4x4 expected {
     5.0f, 10.0f, 15.0f, 20.0f,
    25.0f, 30.0f, 35.0f, 40.0f,
    45.0f, 50.0f, 55.0f, 60.0f,
    65.0f, 70.0f, 75.0f, 80.0f,
  };
  EXPECT_MAT4X4_EQ(scaled_matrix, expected);
}

TEST(TestMat4x4, matrix_scalar_product_scales_up_matrix) {
  const Mat4x4 matrix {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  const F32 scalar = 5.0f;
  const Mat4x4 scaled_matrix = matrix * scalar;
  const Mat4x4 expected {
     5.0f, 10.0f, 15.0f, 20.0f,
    25.0f, 30.0f, 35.0f, 40.0f,
    45.0f, 50.0f, 55.0f, 60.0f,
    65.0f, 70.0f, 75.0f, 80.0f,
  };
  EXPECT_MAT4X4_EQ(scaled_matrix, expected);
}

TEST(TestMat4x4, matrix_scalar_quotient_scales_down_matrix) {
  const Mat4x4 matrix {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  const F32 scalar = 5.0f;
  const Mat4x4 scaled_matrix = matrix / scalar;
  const Mat4x4 expected {
     0.2f, 0.4f, 0.6f, 0.8f,
     1.0f, 1.2f, 1.4f, 1.6f,
     1.8f, 2.0f, 2.2f, 2.4f,
     2.6f, 2.8f, 3.0f, 3.2f,
  };
  EXPECT_MAT4X4_EQ(scaled_matrix, expected);
}

TEST(TestMat4x4, matrix_addition_adds_elements_componentwise) {
  const Mat4x4 matrix_a {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  const Mat4x4 matrix_b {
     8.0f, -4.0f,  3.0f, 10.5f,
     1.0f,  6.0f, -7.0f,  0.0f,
    -1.0f, 10.0f,  8.0f,  2.0f,
     4.0f, -4.0f,  0.0f, 16.0f,
  };
  const Mat4x4 actual = matrix_a + matrix_b;
  const Mat4x4 expected {
      9.0f, -2.0f,  6.0f, 14.5f,
      6.0f, 12.0f,  0.0f,  8.0f,
      8.0f, 20.0f, 19.0f, 14.0f,
     17.0f, 10.0f, 15.0f, 32.0f,
  };
  EXPECT_MAT4X4_EQ(actual, expected);
}

TEST(TestMat4x4, matrix_addition_is_commutative) {
  const Mat4x4 matrix_a {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  const Mat4x4 matrix_b {
     8.0f, -4.0f,  3.0f, 10.5f,
     1.0f,  6.0f, -7.0f,  0.0f,
    -1.0f, 10.0f,  8.0f,  2.0f,
     4.0f, -4.0f,  0.0f, 16.0f,
  };
  EXPECT_MAT4X4_EQ(matrix_a + matrix_b, matrix_b + matrix_a);
}

TEST(TestMat4x4, matrix_subtraction_subtracts_elements_componentwise) {
  const Mat4x4 matrix_a {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  const Mat4x4 matrix_b {
     8.0f, -4.0f,  3.0f, 10.5f,
     1.0f,  6.0f, -7.0f,  0.0f,
    -1.0f, 10.0f,  8.0f,  2.0f,
     4.0f, -4.0f,  0.0f, 16.0f,
  };
  const Mat4x4 actual = matrix_a - matrix_b;
  const Mat4x4 expected {
     -7.0f,  6.0f,  0.0f, -6.5f,
      4.0f,  0.0f, 14.0f,  8.0f,
     10.0f,  0.0f,  3.0f, 10.0f,
      9.0f, 18.0f, 15.0f,  0.0f,
  };
  EXPECT_MAT4X4_EQ(actual, expected);
}

TEST(TestMat4x4, matrix_subtraction_is_anticommutative) {
  const Mat4x4 matrix_a {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  const Mat4x4 matrix_b {
     8.0f, -4.0f,  3.0f, 10.5f,
     1.0f,  6.0f, -7.0f,  0.0f,
    -1.0f, 10.0f,  8.0f,  2.0f,
     4.0f, -4.0f,  0.0f, 16.0f,
  };
  EXPECT_MAT4X4_EQ(matrix_a - matrix_b, -(matrix_b - matrix_a));
}

TEST(TestMat4x4, matrix_multiplication_yields_mathematical_matrix_product) {
  const Mat4x4 matrix_a {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  const Mat4x4 matrix_b {
     8.0f, -4.0f,  3.0f, 10.5f,
     1.0f,  6.0f, -7.0f,  0.0f,
    -1.0f, 10.0f,  8.0f,  2.0f,
     4.0f, -4.0f,  0.0f, 16.0f,
  };
  const Mat4x4 product = matrix_a * matrix_b;
  const Mat4x4 expected {
    23.0f,   22.0f, 13.0f,  80.5f,
    71.0f,   54.0f, 29.0f, 194.5f,
    119.0f,  86.0f, 45.0f, 308.5f,
    167.0f, 118.0f, 61.0f, 422.5f,
  };
  EXPECT_MAT4X4_EQ(product, expected);
}

TEST(TestMat4x4, identity_matrix_is_identity_for_matrix_multiplication) {
  const Mat4x4 matrix {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  const Mat4x4 identity = Mat4x4::identity();
  EXPECT_EQ(matrix * identity, matrix);
  EXPECT_EQ(identity * matrix, matrix);
}

TEST(TestMat4x4, vector_is_one_column_matrix_for_matrix_vector_multiplication) {
  const Mat4x4 matrix {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  const Vec4 vector {1.0f, 2.0f, 3.0f, 4.0f};
  const Vec4 product = matrix * vector;
  const Vec4 expected {30.0f, 70.0f, 110.0f, 150.0f};
  EXPECT_EQ(product, expected);
}

TEST(TestMat4x4, matrix_string_representation_is_rows_separated_by_bars) {
  const Mat4x4 matrix {
     1.0f,  2.0f,  3.0f,  4.0f,
     5.0f,  6.0f,  7.0f,  8.0f,
     9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  const std::string
    actual   = (std::stringstream() << matrix).str(),
    expected = "| 1 2 3 4 | 5 6 7 8 | 9 10 11 12 | 13 14 15 16 |";
  EXPECT_EQ(actual, expected);
}
