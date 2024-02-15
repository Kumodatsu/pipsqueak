#include "pipsqueak/App.hpp"

namespace pipsqueak {

  App::App(
    std::unique_ptr<Window> window,
    std::unique_ptr<Logger> logger
  )
    : m_window(std::move(window))
    , m_logger(std::move(logger))
  {}

  void App::run() {
    m_logger->info() << "App started.";
    auto now = std::chrono::steady_clock::now();
    while (!m_window->should_close()) {
      const auto last_update_time = now;
      now = std::chrono::steady_clock::now();
      const std::chrono::duration<F32> delta = now - last_update_time;

      on_update(delta);

      m_window->update();
      m_window->swap_buffers();
      m_window->poll_events();
    }
    m_logger->info() << "App stopped.";
  }

}
