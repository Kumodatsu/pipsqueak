#include "pipsqueak/logging/Logger.hpp"

#include <filesystem>
#include <format>

#include "pipsqueak/Common.hpp"
#include "pipsqueak/Time.hpp"

namespace pipsqueak {

  Logger::Logger(std::ostream& output_stream, LogSeverity log_severity)
    : m_output_stream(output_stream)
    , m_mutex()
    , m_log_severity(log_severity)
  {}

  Logger& Logger::log(const LogEntry& entry) {
    if (entry.info.severity < m_log_severity) {
      return *this;
    }
    
    // `7` is the longest length of a log level name ("Warning").
    static constexpr size_t longest_log_level_name_length = 7;

    const auto  local_time  = time::get_current_local_time();
    const auto& location    = entry.info.source_location;
    const auto  file_name   = std::filesystem::path(location.file_name())
      .filename()
      .string();

    std::lock_guard<decltype(m_mutex)> lock(m_mutex);
    m_output_stream
      << "["
      << std::format("{:%H:%M:%OS}", local_time)
      << " " << std::left << std::setw(longest_log_level_name_length)
      << entry.info.severity
      << "] "
      << "("
      << file_name << ":" << location.line()
      << ") "
      << entry.message
      << std::endl;

    return *this;
  }

  LogMessage Logger::log_message(
    LogSeverity          log_severity,
    std::source_location source_location
  ) {
    return LogMessage(*this, {
      .severity        = log_severity,
      .time            = time::get_current_local_time(),
      .source_location = source_location,
    });
  }

  LogMessage Logger::verbose(std::source_location source_location) {
    return log_message(LogSeverity::Verbose, source_location);
  }

  LogMessage Logger::debug(std::source_location source_location) {
    return log_message(LogSeverity::Debug, source_location);
  }

  LogMessage Logger::info(std::source_location source_location) {
    return log_message(LogSeverity::Info, source_location);
  }

  LogMessage Logger::warning(std::source_location source_location) {
    return log_message(LogSeverity::Warning, source_location);
  }

  LogMessage Logger::error(std::source_location source_location) {
    return log_message(LogSeverity::Error, source_location);
  }

  LogMessage Logger::fatal(std::source_location source_location) {
    return log_message(LogSeverity::Fatal, source_location);
  }

}
