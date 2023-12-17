#include "pipsqueak/Time.hpp"

namespace pipsqueak::time {

  LocalTime get_current_local_time() {
    return {
      std::chrono::current_zone(),
      std::chrono::system_clock::now()
    };
  }

}
