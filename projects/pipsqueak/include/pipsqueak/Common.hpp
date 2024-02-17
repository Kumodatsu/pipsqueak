#pragma once

#include <concepts>
#include <cstddef>
#include <cstdint>

namespace pipsqueak {

  using I8  = int8_t;
  using I16 = int16_t;
  using I32 = int32_t;
  using I64 = int64_t;
  using U8  = uint8_t;
  using U16 = uint16_t;
  using U32 = uint32_t;
  using U64 = uint64_t;
  using F32 = float;
  using F64 = double;

  using Index = size_t;
  using Count = size_t;
  using Size  = size_t;

  template <typename T>
  concept Integer = std::integral<T>;

  template <typename T>
  concept Natural = std::unsigned_integral<T>;

  template <typename T>
  concept Real = std::floating_point<T>;

}
