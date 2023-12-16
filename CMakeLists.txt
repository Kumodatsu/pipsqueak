cmake_minimum_required(VERSION 3.23.0)

option(BUILD_TESTS      "Enables building the tests and test framework."    OFF)
option(BUILD_EXAMPLES   "Enables building the example projects."            OFF)
option(FAIL_ON_WARNINGS "Makes the build fail if any warnings are emitted." OFF)

include("cmake/set_warnings.cmake")

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

if(BUILD_EXAMPLES)
  add_subdirectory("projects/playground")
endif()

if(BUILD_TESTS)
  enable_testing()
  include("cmake/add_test.cmake")
  add_subdirectory("projects/googletest")
  add_subdirectory("tests")
endif()
