#pragma once

#include <gtest/gtest.h>

#define EXPECT_VEC2_EQ(LHS, RHS)                                               \
  do {                                                                         \
    const Vec2 lhs = (LHS);                                                    \
    const Vec2 rhs = (RHS);                                                    \
    EXPECT_FLOAT_EQ(lhs.x, rhs.x);                                             \
    EXPECT_FLOAT_EQ(lhs.y, rhs.y);                                             \
  } while (false)

#define EXPECT_VEC3_EQ(LHS, RHS)                                               \
  do {                                                                         \
    const Vec3 lhs = (LHS);                                                    \
    const Vec3 rhs = (RHS);                                                    \
    EXPECT_FLOAT_EQ(lhs.x, rhs.x);                                             \
    EXPECT_FLOAT_EQ(lhs.y, rhs.y);                                             \
    EXPECT_FLOAT_EQ(lhs.z, rhs.z);                                             \
  } while (false)

#define EXPECT_VEC3_NEAR(LHS, RHS, EPSILON)                                    \
  do {                                                                         \
    const Vec3 lhs = (LHS);                                                    \
    const Vec3 rhs = (RHS);                                                    \
    EXPECT_NEAR(lhs.x, rhs.x, EPSILON);                                        \
    EXPECT_NEAR(lhs.y, rhs.y, EPSILON);                                        \
    EXPECT_NEAR(lhs.z, rhs.z, EPSILON);                                        \
  } while (false)

#define EXPECT_VEC4_EQ(LHS, RHS)                                               \
  do {                                                                         \
    const Vec4 lhs = (LHS);                                                    \
    const Vec4 rhs = (RHS);                                                    \
    EXPECT_FLOAT_EQ(lhs.x, rhs.x);                                             \
    EXPECT_FLOAT_EQ(lhs.y, rhs.y);                                             \
    EXPECT_FLOAT_EQ(lhs.z, rhs.z);                                             \
    EXPECT_FLOAT_EQ(lhs.w, rhs.w);                                             \
  } while (false)

#define EXPECT_MAT4X4_EQ(LHS, RHS)                                             \
  do {                                                                         \
    const Mat4x4 lhs = (LHS);                                                  \
    const Mat4x4 rhs = (RHS);                                                  \
    for (Index col = 0; col < 4; ++col) {                                      \
      for (Index row = 0; row < 4; ++row) {                                    \
        EXPECT_FLOAT_EQ(lhs.at(row, col), rhs.at(row, col));                   \
      }                                                                        \
    }                                                                          \
  } while (false)

