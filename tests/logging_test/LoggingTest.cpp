#include <pipsqueak/logging/Logging.hpp>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <regex>

using namespace pipsqueak;
using namespace testing;

class LoggingTest : public Test {
protected:
  std::stringstream m_stream;
  Logger            m_logger;

  LoggingTest()
    : m_stream()
    , m_logger(m_stream, LogSeverity::Verbose)
  {}
};

static void assert_string_matches_regex(
  const std::string& string,
  const std::string& regex
) {
  ASSERT_TRUE(std::regex_search(string, std::regex(regex)))
    << "string: " << string;
}

TEST_F(
  LoggingTest,
  info_message_has_correct_format
) {
  m_logger.info() << "Peekaboo!";
  
  const auto message = m_stream.str();
  
  assert_string_matches_regex(
    message,
    R"#(^\[\d\d:\d\d:\d\d Info   \] \(.*?:\d+\) Peekaboo!\n$)#"
  );
}

TEST_F(
  LoggingTest,
  verbose_message_is_not_logged_when_log_severity_is_set_to_info
) {
  m_logger.log_severity(LogSeverity::Info);

  m_logger.verbose() << "Peekaboo!";

  ASSERT_EQ(m_stream.str(), "");
}

TEST_F(
  LoggingTest,
  log_message_can_accept_multiple_stream_inputs
) {
  m_logger.info() << "Peekaboo" << "!";

  const auto message = m_stream.str();
  
  assert_string_matches_regex(
    message,
    R"#(^\[\d\d:\d\d:\d\d Info   \] \(.*?:\d+\) Peekaboo!\n$)#"
  );
}

TEST_F(
  LoggingTest,
  log_message_can_accept_numbers
) {
  m_logger.info() << "P" << 33 << "k" << 4 << 8 << 0 << 0 << "!";

  const auto message = m_stream.str();

  assert_string_matches_regex(
    message,
    R"#(^\[\d\d:\d\d:\d\d Info   \] \(.*?:\d+\) P33k4800!\n$)#"
  );
}

TEST_F(
  LoggingTest,
  multiple_log_expressions_result_in_multiple_log_entries_in_output
) {
  m_logger.info() << "Peekaboo!";
  m_logger.info() << "Oobakeep!";

  const auto message = m_stream.str();

  assert_string_matches_regex(
    message,
    "^"
    R"#(\[\d\d:\d\d:\d\d Info   \] \(.*?:\d+\) Peekaboo!\n)#"
    R"#(\[\d\d:\d\d:\d\d Info   \] \(.*?:\d+\) Oobakeep!\n)#"
    "$"
  );
}
