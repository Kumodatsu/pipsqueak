#include <gtest/gtest.h>
#include <pipsqueak/common/ForceEvaluation.hpp>
#include <pipsqueak/math/Functions.hpp>

#include <array>

using namespace pipsqueak;
using namespace pipsqueak::math;

template <auto Begin, auto End, auto Increment, typename Function>
static constexpr void for_constexpr(Function&& function) {
  if constexpr (Begin < End) {
    function(std::integral_constant<decltype(Begin), Begin>());
    for_constexpr<Begin + Increment, End, Increment>(function);
  }
}

TEST(TestFunctions, sine_of_half_pi_is_one) {
  const F32 sine = math::sin(0.5f * math::pi<F32>);
  EXPECT_FLOAT_EQ(sine, 1.0f);
}

TEST(TestFunctions, sqrt_of_25_equals_5) {
  const F32 result = math::sqrt(25.0f);
  EXPECT_FLOAT_EQ(result, 5.0f);
}

TEST(TestFunctions, consteval_sqrt_yields_same_result_as_runtime_sqrt) {
  static constexpr std::array<F32, 16> inputs {{
    25.0f, 0.0f, 1500.0f, 0.005f,
    65535.0f, 32138209.21480f, 129408.2893f, 2374814.0f,
    0.003420f, 32499.0f, 32948.0f, 23804.0f,
    10.0e8f, 10.0e-8f, 3503940.348f, 754224.3532f
  }};
  for_constexpr<0, inputs.size(), 1>([](auto i) {
    constexpr F32 input = inputs.at(i);
  	const F32 consteval_result = force_consteval(math::sqrt<F32>, input);
    const F32 runtime_result   = force_runtime(math::sqrt<F32>, input);
    EXPECT_FLOAT_EQ(consteval_result, runtime_result) << "Input: " << input;
  });
}
