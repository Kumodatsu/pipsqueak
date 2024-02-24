#include <gtest/gtest.h>
#include <pipsqueak/App.hpp>
#include <pipsqueak/renderer/stub/Window.hpp>
#include <pipsqueak/logging/MockStream.hpp>

using namespace testing;
using namespace pipsqueak;

TEST(AppTest, app_works) {
  MockStream stream;
  App app(
    std::make_unique<stub::Window>(
      "Test Window", static_cast<U16>(640), static_cast<U16>(480)
    ),
    std::make_unique<Logger>(stream, LogSeverity::Verbose)
  );
}
