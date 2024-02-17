pipsqueak_add_test(
  TARGET app_test
  SOURCES
    "app_test/AppTest.cpp"
  INCLUDES
    "app_test"
  LINKS
)

pipsqueak_add_test(
  TARGET enum_test
  SOURCES
    "enum_test/EnumTest.cpp"
  INCLUDES
    "enum_test"
  LINKS
)

pipsqueak_add_test(
  TARGET logging_test
  SOURCES
    "logging_test/LoggingTest.cpp"
  INCLUDES
    "logging_test"
  LINKS
)

pipsqueak_add_test(
  TARGET math_tests
  SOURCES
    "math_tests/TestVec2.cpp"
  INCLUDES
    "math_tests"
)
