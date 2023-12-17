#pragma once

#include <cstdint>
#include <cstddef>

namespace pipsqueak {

  using Int8    = int8_t;
  using Int16   = int16_t;
  using Int32   = int32_t;
  using Int64   = int64_t;
  using UInt8   = uint8_t;
  using UInt16  = uint16_t;
  using UInt32  = uint32_t;
  using UInt64  = uint64_t;
  using Float32 = float;
  using Float64 = double;

  using Index   = size_t;
  using Count   = size_t;
  using Size    = size_t;

  static_assert(sizeof(Int8)    == 1);
  static_assert(sizeof(Int16)   == 2);
  static_assert(sizeof(Int32)   == 4);
  static_assert(sizeof(Int64)   == 8);
  static_assert(sizeof(UInt8)   == 1);
  static_assert(sizeof(UInt16)  == 2);
  static_assert(sizeof(UInt32)  == 4);
  static_assert(sizeof(UInt64)  == 8);
  static_assert(sizeof(Float32) == 4);
  static_assert(sizeof(Float64) == 8);
  static_assert(sizeof(Index)   == sizeof(size_t));
  static_assert(sizeof(Count)   == sizeof(size_t));
  static_assert(sizeof(Size)    == sizeof(size_t));

  void test();

}
