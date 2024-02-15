#pragma once

#include <chrono>

#include "pipsqueak/Common.hpp"
#include "pipsqueak/Window.hpp"
#include "pipsqueak/logging/Logging.hpp"

namespace pipsqueak {

  class App {
  public:
    App(
      std::unique_ptr<Window> window,
      std::unique_ptr<Logger> logger
    );
    virtual ~App() = default;

    void run();
  protected:
    virtual void on_update(std::chrono::duration<F32> /*delta*/) {}

    inline Logger& logger() {
      return *m_logger.get();
    }
  private:
    std::unique_ptr<Window> m_window;
    std::unique_ptr<Logger> m_logger;
  };

}
