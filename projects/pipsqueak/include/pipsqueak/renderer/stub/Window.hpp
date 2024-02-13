#pragma once

#include "pipsqueak/Window.hpp"

namespace pipsqueak::stub {

  class Window : public pipsqueak::Window {
  public:
    Window(const std::string& title, U16 width, U16 height);

    bool should_close() const override;
    void update() override;
    void swap_buffers() override;
    void poll_events() override;

    void request_close();
  private:
    bool m_should_close;
  };

}
