#include "pipsqueak/logging/LogMessage.hpp"
#include "pipsqueak/logging/Logger.hpp"

#include <ostream>

namespace pipsqueak {

  LogMessage::LogMessage(Logger& logger, const LogEntryInfo& info)
    : m_logger(logger)
    , m_info(info)
    , m_buffer_stream()
  {}

  LogMessage::~LogMessage() {
    m_logger.log({
      .info    = m_info,
      .message = message(),
    });
  }

}
