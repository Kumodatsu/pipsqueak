cmake_minimum_required(VERSION 3.23.0)

project(
  pipsqueak
  VERSION     0.1.0
  DESCRIPTION "An insignificant engine for insignificant applications."
  LANGUAGES   CXX
)

add_subdirectory("projects/glad")
add_subdirectory("projects/glfw")
add_subdirectory("projects/pipsqueak")
add_subdirectory("projects/playground")
