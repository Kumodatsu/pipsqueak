#include "pipsqueak/Common.hpp"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

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

namespace pipsqueak {

  void test() {
    const int glfw_succeeded = glfwInit();
    if (glfw_succeeded == 0) {
      std::cout << "GLFW failed to initialize." << std::endl;
      return;
    }
    std::cout << "GLFW initialized." << std::endl;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(640, 480, "Pipsqueak", nullptr,
      nullptr);
    if (window == nullptr) {
      glfwTerminate();
      std::cout << "Failed to create window." << std::endl;
      return;
    }
    std::cout << "Window created." << std::endl;
    glfwMakeContextCurrent(window);
    const int glad_succeeded =
      gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
    if (glad_succeeded == 0) {
      std::cout << "Failed to initialize Glad." << std::endl;
      glfwDestroyWindow(window);
      glfwTerminate();
      return;
    }
    std::cout << "Glad initialized." << std::endl;
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(log_gl_debug_message, nullptr);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();
    std::cout << "Initialized Dear ImGui." << std::endl;

    while (!glfwWindowShouldClose(window)) {
      glClear(GL_COLOR_BUFFER_BIT);

      ImGui_ImplOpenGL3_NewFrame();
      ImGui_ImplGlfw_NewFrame();
      ImGui::NewFrame();

      ImGui::ShowDemoWindow();

      ImGui::Render();
      ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
      ImGui::UpdatePlatformWindows();
      ImGui::RenderPlatformWindowsDefault();

      glfwSwapBuffers(window);
      glfwPollEvents();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    std::cout << "Terminated Dear ImGui." << std::endl;

    glfwDestroyWindow(window);
    std::cout << "Destroyed window." << std::endl;
    glfwTerminate();
    std::cout << "Terminated Glad." << std::endl;
    std::cout << "Terminated GLFW." << std::endl;
  }

}
