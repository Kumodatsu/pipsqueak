cmake_minimum_required(VERSION 3.23.0)

project(
  pipsqueak
  VERSION     0.1.0
  DESCRIPTION "An insignificant engine for insignificant applications."
  LANGUAGES   CXX
)

add_library(
  pipsqueak
  STATIC
    "src/App.cpp"
    "src/Window.cpp"
    "src/renderer/opengl/Window.cpp"
    "src/renderer/stub/Window.cpp"
    "src/BuildInfo.cpp"
    "src/Time.cpp"
    "src/logging/LogSeverity.cpp"
    "src/logging/LogMessage.cpp"
    "src/logging/Logger.cpp"
    "src/math/Vec2.cpp"
    "src/math/Vec3.cpp"
)

set_target_properties(
  pipsqueak
  PROPERTIES
    CXX_STANDARD 20
)

pipsqueak_set_warnings(pipsqueak)

target_compile_definitions(
  pipsqueak
  PRIVATE
    "GLFW_INCLUDE_NONE"
)

target_include_directories(
  pipsqueak
  PUBLIC
    "include"
  PRIVATE
    "src"
    "${CMAKE_SOURCE_DIR}/projects/glad/glad/include"
    "${CMAKE_SOURCE_DIR}/projects/glfw/glfw/include"
    "${CMAKE_SOURCE_DIR}/projects/imgui/imgui"
)

target_link_libraries(
  pipsqueak
  PRIVATE
    "glad"
    "glfw"
    "imgui"
)
