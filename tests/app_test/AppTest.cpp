#include <gtest/gtest.h>
#include <pipsqueak/App.hpp>
#include <pipsqueak/renderer/stub/Window.hpp>

using namespace testing;
using namespace pipsqueak;

TEST(AppTest, app_works) {
  App app(std::make_unique<stub::Window>("Test Window", static_cast<U16>(640),
    static_cast<U16>(480)));
}
