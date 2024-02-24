#pragma once

#include <concepts>
#include <type_traits>

namespace pipsqueak {

  template <typename T>
  concept Enum = std::is_enum_v<T>;

  inline constexpr auto underlying_cast(Enum auto value) {
    return static_cast<std::underlying_type_t<decltype(value)>>(value);
  }

}
