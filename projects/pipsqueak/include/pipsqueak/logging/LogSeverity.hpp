#pragma once

#include <compare>
#include <iosfwd>

#include "pipsqueak/Common.hpp"
#include "pipsqueak/Enum.hpp"

namespace pipsqueak {

  enum class LogSeverity : U8 {
    Verbose, // Extra messages that generally may be superfluous.
    Debug,   // Messages for debug purposes.
    Info,    // Regular log messages.
    Warning, // Messages indicating something might cause a problem.
    Error,   // Messages for recovarable errors.
    Fatal,   // Messages for non-recoverable errors. Will throw a runtime error. 
  };

  std::ostream& operator << (std::ostream& stream, LogSeverity log_severity);

  inline constexpr bool operator < (LogSeverity lhs, LogSeverity rhs) {
    return underlying_cast(lhs) < underlying_cast(rhs);
  }

  inline constexpr bool operator > (LogSeverity lhs, LogSeverity rhs) {
    return underlying_cast(lhs) > underlying_cast(rhs);
  }

  inline constexpr bool operator <= (LogSeverity lhs, LogSeverity rhs) {
    return underlying_cast(lhs) <= underlying_cast(rhs);
  }

  inline constexpr bool operator >= (LogSeverity lhs, LogSeverity rhs) {
    return underlying_cast(lhs) >= underlying_cast(rhs);
  }

  inline constexpr auto operator <=> (LogSeverity lhs, LogSeverity rhs) {
    return underlying_cast(lhs) <=> underlying_cast(rhs);
  }

}
