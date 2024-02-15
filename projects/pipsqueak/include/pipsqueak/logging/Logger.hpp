#pragma once

#include <chrono>
#include <mutex>
#include <string>

#include "pipsqueak/logging/LogSeverity.hpp"
#include "pipsqueak/logging/LogMessage.hpp"

namespace pipsqueak {

  class Logger {
  public:
    Logger(std::ostream& output_stream, LogSeverity log_severity);

    inline LogSeverity log_severity() const {
      return m_log_severity;
    }

    inline void log_severity(LogSeverity log_severity) {
      m_log_severity = log_severity;
    }

    Logger& log(const LogEntry& entry);

    LogMessage log_message(
      LogSeverity          log_severity,
      std::source_location source_location = std::source_location::current()
    );

    LogMessage verbose(
      std::source_location source_location = std::source_location::current()
    );

    LogMessage debug(
      std::source_location source_location = std::source_location::current()
    );

    LogMessage info(
      std::source_location source_location = std::source_location::current()
    );

    LogMessage warning(
      std::source_location source_location = std::source_location::current()
    );

    LogMessage error(
      std::source_location source_location = std::source_location::current()
    );
    
    LogMessage fatal(
      std::source_location source_location = std::source_location::current()
    );
  private:
    std::ostream& m_output_stream;
    std::mutex    m_mutex;
    LogSeverity   m_log_severity;
  };

}
