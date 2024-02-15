#include <pipsqueak/Common.hpp>
#include <pipsqueak/Enum.hpp>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace pipsqueak;

enum UnscopedEnum : I32 {
  UnscopedNegativeOne = -1,
  UnscopedZero        =  0,
  UnscopedOne         =  1,
  UnscopedAnotherOne  =  UnscopedOne,
};

enum class ScopedEnum : I32 {
  NegativeOne = -1,
  Zero        =  0,
  One         =  1,
  AnotherOne  =  One,
};

TEST(EnumTest, unscoped_enum_satisfies_enum_concept) {
  ASSERT_TRUE(Enum<UnscopedEnum>);
}

TEST(EnumTest, scoped_enum_satisfies_enum_concept) {
  ASSERT_TRUE(Enum<ScopedEnum>);
}

TEST(EnumTest, non_enum_integral_type_does_not_satisfy_enum_concept) {
  ASSERT_FALSE(Enum<I32>);
}

TEST(
  EnumTest,
  result_of_underlying_cast_on_unscoped_enum_variant_is_underlying_value
) {
  EXPECT_EQ(underlying_cast(UnscopedNegativeOne), -1);
  EXPECT_EQ(underlying_cast(UnscopedZero),         0);
  EXPECT_EQ(underlying_cast(UnscopedOne),          1);
  EXPECT_EQ(underlying_cast(UnscopedAnotherOne),   1);
}

TEST(
  EnumTest,
  result_of_underlying_cast_on_scoped_enum_variant_is_underlying_value
) {
  EXPECT_EQ(underlying_cast(ScopedEnum::NegativeOne), -1);
  EXPECT_EQ(underlying_cast(ScopedEnum::Zero),         0);
  EXPECT_EQ(underlying_cast(ScopedEnum::One),          1);
  EXPECT_EQ(underlying_cast(ScopedEnum::AnotherOne),   1);
}
