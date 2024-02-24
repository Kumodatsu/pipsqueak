#pragma once

#include <utility>
#include <type_traits>

namespace pipsqueak {

  // Forces a function to be evaluated at compile time.
  // If this is not possible, this results in a compile time error.
  // The main application of this function is for testing, to ensure that a
  // compile time evaluation of some expression has the same result as a runtime
  // evaluation.
  consteval auto force_consteval(auto function, auto&&... args) {
    return function(std::forward<decltype(args)>(args)...);
  }

  // Forces a function to be evaluated at runtime.
  // This adds some overhead compared to when the expression would already be
  // evaluated at runtime without a call to this function.
  // This overhead is needed to force a runtime dependency.
  // The main application of this function is for testing, to ensure that a
  // compile time evaluation of some expression has the same result as a runtime
  // evaluation.
  inline auto force_runtime(auto function, auto&&... args) {
    static volatile struct {} runtime_dependency;
    runtime_dependency;
    return function(std::forward<decltype(args)>(args)...);
  }

}
