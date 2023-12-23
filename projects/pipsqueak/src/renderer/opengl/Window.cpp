#include "pipsqueak/renderer/opengl/Window.hpp"

#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <glad/glad.h>
#include <iostream>
#include <stdexcept>

static void APIENTRY log_gl_debug_message(
  GLenum        /*source*/,
  GLenum        /*type*/,
  GLuint        /*id*/,
  GLenum        severity,
  GLsizei       /*length*/,
  const GLchar* message,
  const void*   /*user_param*/
) {
  if (severity == GL_DEBUG_SEVERITY_NOTIFICATION) {
    return;
  }
  std::cout << "GL: " << message << std::endl;
}

namespace pipsqueak::opengl {

  Window::Window(const std::string& title, U16 width, U16 height)
    : pipsqueak::Window(title, width, height)
    , m_handle(nullptr)
  {
    initialize_glfw();
    initialize_window();
    initialize_glad();
    initialize_imgui();
  }

  Window::~Window() {
    // `m_handle` will be set to `nullptr` if this instance is moved from,
    // so only terminate if this instance still owns the handle.
    if (m_handle == nullptr) {
      return;
    }
    terminate();
  }

  Window::Window(Window&& other)
    : pipsqueak::Window(std::move(other))
    , m_handle(other.m_handle)
  {
    other.m_handle = nullptr;
  }

  Window& Window::operator = (Window&& other) {
    if (this == &other) {
      return *this;
    }
    terminate();
    pipsqueak::Window::operator = (std::move(other));
    m_handle       = other.m_handle;
    other.m_handle = nullptr;
    return *this;
  }

  bool Window::should_close() const {
    return glfwWindowShouldClose(m_handle);
  }

  void Window::update() {
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::ShowDemoWindow();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    ImGui::UpdatePlatformWindows();
    ImGui::RenderPlatformWindowsDefault();
  }

  void Window::swap_buffers() {
    glfwSwapBuffers(m_handle);
  }

  void Window::poll_events() {
    glfwPollEvents();
  }

  void Window::initialize_glfw() {
    const int glfw_succeeded = glfwInit();
    if (glfw_succeeded == 0) {
      throw std::runtime_error("GLFW failed to initialize");
    }
  }

  void Window::initialize_window() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    m_handle = glfwCreateWindow(m_width, m_height, m_title.c_str(),
      nullptr, nullptr);
    if (m_handle == nullptr) {
      glfwTerminate();
      throw std::runtime_error("Failed to create window");
    }
    glfwMakeContextCurrent(m_handle);
  }

  void Window::initialize_glad() {
    const int glad_succeeded =
      gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
    if (glad_succeeded == 0) {
      glfwDestroyWindow(m_handle);
      glfwTerminate();
      throw std::runtime_error("Failed to initialize Glad");
    }
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(log_gl_debug_message, nullptr);
  }

  void Window::initialize_imgui() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    ImGui_ImplGlfw_InitForOpenGL(m_handle, true);
    ImGui_ImplOpenGL3_Init();
  }

  void Window::terminate() {
    terminate_imgui();
    // Glad doesn't require termination.
    terminate_window();
    terminate_glfw();
  }

  void Window::terminate_imgui() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
  }

  void Window::terminate_window() {
    glfwDestroyWindow(m_handle);
  }

  void Window::terminate_glfw() {
    glfwTerminate();
  }

}
