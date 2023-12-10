cmake_minimum_required(VERSION 3.23.0)

option(ENABLE_TESTS "Enables building the tests and test framework." OFF)

project(
  pipsqueak
  VERSION     0.1.0
  DESCRIPTION "An insignificant engine for insignificant applications."
  LANGUAGES   CXX
)

add_subdirectory("projects/glad")
add_subdirectory("projects/glfw")
add_subdirectory("projects/imgui")
add_subdirectory("projects/pipsqueak")
add_subdirectory("projects/playground")

if(ENABLE_TESTS)
  enable_testing()
  add_subdirectory("projects/googletest")
  add_subdirectory("tests")
endif()
