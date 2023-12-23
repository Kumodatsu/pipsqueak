#pragma once

#include <GLFW/glfw3.h>

#include "pipsqueak/Window.hpp"

namespace pipsqueak::opengl {

  class Window : public pipsqueak::Window {
  public:
    Window(const std::string& title, U16 width, U16 height);
    ~Window() override;

    Window(Window&& other);
    Window& operator = (Window&& other);

    bool should_close() const override;
    void update() override;
    void swap_buffers() override;
    void poll_events() override;
  private:
    GLFWwindow* m_handle;

    void initialize_glfw();
    void initialize_window();
    void initialize_glad();
    void initialize_imgui();

    void terminate();
    void terminate_imgui();
    void terminate_window();
    void terminate_glfw();
  };

}
