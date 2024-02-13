#pragma once

#include <chrono>

#include "pipsqueak/Common.hpp"
#include "pipsqueak/Window.hpp"

namespace pipsqueak {

  class App {
  public:
    App(std::unique_ptr<Window> window);
    virtual ~App() = default;

    void run();
  protected:
    virtual void on_update(std::chrono::duration<F32> /*delta*/) {}
  private:
    std::unique_ptr<Window> m_window;
  };

}
