#pragma once

#include <concepts>
#include <functional>
#include <iosfwd>
#include <source_location>
#include <sstream>

#include "pipsqueak/Time.hpp"
#include "pipsqueak/logging/LogSeverity.hpp"

namespace pipsqueak {

  class Logger;

  template <typename T>
  concept Loggable = requires(std::ostream& stream, T value) {
    { stream << value } -> std::same_as<std::ostream&>;
  };

  struct LogEntryInfo {
    LogSeverity          severity;
    time::LocalTime      time;
    std::source_location source_location;
  };

  struct LogEntry {
    LogEntryInfo info;
    std::string  message;
  };

  class LogMessage {
  public:
    LogMessage(Logger& logger, const LogEntryInfo& info);
    ~LogMessage();
    LogMessage(const LogMessage& other) = delete;
    LogMessage& operator = (const LogMessage& other) = delete;

    LogMessage& operator << (Loggable auto value) {
      m_buffer_stream << value;
      return *this;
    }

    inline std::string message() const {
      return m_buffer_stream.str();
    }
  private:
    Logger& m_logger;

    LogEntryInfo      m_info;
    std::stringstream m_buffer_stream;
  };

}
