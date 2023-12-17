#pragma once

#include <chrono>

namespace pipsqueak::time {

  using LocalTime =
    std::chrono::zoned_time<std::chrono::system_clock::duration>;

  LocalTime get_current_local_time();

}
