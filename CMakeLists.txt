cmake_minimum_required(VERSION 3.23.0)

option(ENABLE_TESTS     "Enables building the tests and test framework."    OFF)
option(FAIL_ON_WARNINGS "Makes the build fail if any warnings are emitted." OFF)

# Use a high warning level to help preventing some classes of bugs.
function(SetWarnings target)
  if (MSVC)
    target_compile_options(${target} PRIVATE /W4)
    if(FAIL_ON_WARNINGS)
      target_compile_options(${target} PRIVATE /WX)
    endif()
  else()
    target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
    if(FAIL_ON_WARNINGS)
      target_compile_options(${target} PRIVATE -Werror)
    endif()
  endif()
endfunction()

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
