add_executable(
  testing_test
    "testing_test/TestingTest.cpp"
)

set_target_properties(
  testing_test
  PROPERTIES
    CXX_STANDARD 20
)

SetWarnings(testing_test)

target_include_directories(
  testing_test
  PRIVATE
    "${CMAKE_SOURCE_DIR}/projects/googletest/googletest/googletest/include"
    "${CMAKE_SOURCE_DIR}/projects/googletest/googletest/googlemock/include"
    "testing_test"
    "${CMAKE_SOURCE_DIR}/projects/pipsqueak/include"
)

target_link_libraries(
  testing_test
  PRIVATE
    gtest
    gmock
    gtest_main
    pipsqueak
)

add_test(
  NAME    "testing_test"
  COMMAND "testing_test"
)
