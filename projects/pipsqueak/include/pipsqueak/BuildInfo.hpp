#pragma once

#include <iosfwd>

#include "pipsqueak/Common.hpp"

namespace pipsqueak::build_info {

  enum class System : U8 {
    Linux,
    Windows,
  };

  std::ostream& operator << (std::ostream& stream, System system);

  enum class Configuration : U8 {
    Debug,
    Release,
    MinSizeRel,
    RelWithDebInfo,
  };

  std::ostream& operator << (std::ostream& stream, Configuration configuration);

  inline constexpr System target_system =
    #if defined(__linux__)
    System::Linux
    #elif defined(_WIN32) || defined(_WIN64)
    System::Windows
    #else
    #error Unsupported operating system.
    System::Linux
    #endif
  ;

  inline constexpr Configuration target_configuration =
    #if defined(NDEBUG)
    Configuration::Release
    #else
    Configuration::Debug
    #endif
  ;

  inline constexpr bool debug = target_configuration == Configuration::Debug;

}
