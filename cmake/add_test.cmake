function(AddTest)
  cmake_parse_arguments(
    ARG
    ""
    "TARGET"
    "SOURCES;INCLUDES;LINKS"
    ${ARGN}
  )
  if(NOT ARG_TARGET)
      message(FATAL_ERROR "AddTest requires the target name to be specified.")
  endif()
  if(NOT ARG_SOURCES)
      message(FATAL_ERROR "AddTest requires source files to be specified.")
  endif()

  add_executable(${ARG_TARGET} ${ARG_SOURCES})

  set_target_properties(
    ${ARG_TARGET}
    PROPERTIES
      CXX_STANDARD 20
  )

  SetWarnings(${ARG_TARGET})

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
