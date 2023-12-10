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
    "src/Common.cpp"
)

set_target_properties(
  pipsqueak
  PROPERTIES
    CXX_STANDARD 20
)

# Use a high warning level to help preventing some classes of bugs.
if (MSVC)
  target_compile_options(pipsqueak PRIVATE /W4)
else()
  target_compile_options(pipsqueak PRIVATE -Wall -Wextra -Wpedantic)
endif()

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
)

target_link_libraries(
  pipsqueak
  PRIVATE
    "glad"
    "glfw"
)
