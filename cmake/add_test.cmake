# Add a target to be included as a test suite, usable with ctest.
# Requires a TARGET to be specified, as well as lists of SOURCES, INCLUDES, and
# LINKS.
# googletest and pipsqueak are automatically added as dependencies so they don't
# have to be listed explicitly.
# Example usage:
# pipsqueak_add_test(
#   TARGET some_test
#   SOURCES
#     "some_test/SomeTest.cpp"
#   INCLUDES
#     "path_to_some_library/include"
#     "some_test"
#   LINKS
#     "some_library_target"
# )
function(pipsqueak_add_test)
  cmake_parse_arguments(
    ARG
    ""
    "TARGET"
    "SOURCES;INCLUDES;LINKS"
    ${ARGN}
  )
  if(NOT ARG_TARGET)
      message(FATAL_ERROR "pipsqueak_add_test requires the target name to be specified.")
  endif()
  if(NOT ARG_SOURCES)
      message(FATAL_ERROR "pipsqueak_add_test requires source files to be specified.")
  endif()

  add_executable(${ARG_TARGET} ${ARG_SOURCES})

  set_target_properties(
    ${ARG_TARGET}
    PROPERTIES
      CXX_STANDARD 20
  )

  pipsqueak_set_warnings(${ARG_TARGET})

  target_include_directories(
    ${ARG_TARGET}
    PRIVATE
      "${CMAKE_SOURCE_DIR}/projects/googletest/googletest/googletest/include"
      "${CMAKE_SOURCE_DIR}/projects/googletest/googletest/googlemock/include"
      "${CMAKE_SOURCE_DIR}/projects/pipsqueak/include"
      ${ARG_INCLUDES}
  )

  target_link_libraries(
    ${ARG_TARGET}
    PRIVATE
      gtest
      gmock
      gtest_main
      pipsqueak
      ${ARG_LINKS}
  )

  add_test(
    NAME    ${ARG_TARGET}
    COMMAND ${ARG_TARGET}
  )
endfunction()
