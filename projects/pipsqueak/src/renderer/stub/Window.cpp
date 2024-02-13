#include "pipsqueak/renderer/stub/Window.hpp"

namespace pipsqueak::stub {

  Window::Window(const std::string& title, U16 width, U16 height)
    : pipsqueak::Window(title, width, height)
    , m_should_close(false)
  {}

  bool Window::should_close() const {
    return m_should_close;
  }

  void Window::update() {}

  void Window::swap_buffers() {}

  void Window::poll_events() {}

  void Window::request_close() {
    m_should_close = true;
  }

}
