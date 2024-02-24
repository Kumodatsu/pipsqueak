#include "pipsqueak/logging/LogSeverity.hpp"

#include <cassert>
#include <ostream>

namespace pipsqueak {

  std::ostream& operator << (std::ostream& stream, LogSeverity log_severity) {
    switch (log_severity) {
      case LogSeverity::Debug:   return stream << "Debug";
      case LogSeverity::Verbose: return stream << "Verbose";
      case LogSeverity::Info:    return stream << "Info";
      case LogSeverity::Warning: return stream << "Warning";
      case LogSeverity::Error:   return stream << "Error";
      case LogSeverity::Fatal:   return stream << "Fatal";
    }
    assert("Invalid LogSeverity value." && false);
    return stream;
  }

}
