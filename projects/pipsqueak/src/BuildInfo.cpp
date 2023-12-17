#include "pipsqueak/BuildInfo.hpp"

#include <cassert>
#include <ostream>

namespace pipsqueak::build_info {

  std::ostream& operator << (std::ostream& stream, System system) {
    switch (system) {
      case System::Linux:   return stream << "Linux";
      case System::Windows: return stream << "Windows";
    }
    assert("Invalid System value." && false);
    return stream;
  }

  std::ostream& operator << (std::ostream& stream, Configuration configuration) {
    switch (configuration) {
      case Configuration::Debug:          return stream << "Debug";
      case Configuration::Release:        return stream << "Release";
      case Configuration::MinSizeRel:     return stream << "MinSizeRel";
      case Configuration::RelWithDebInfo: return stream << "RelWithDebInfo";
    }
    assert("Invalid Configuration value" && false);
    return stream;
  }

}
