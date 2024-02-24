cmake_minimum_required(VERSION 3.28.0)

project(
  moduletest
  VERSION     0.1.0
  DESCRIPTION "Module Test"
  LANGUAGES   CXX
)

add_executable(
  moduletest
    "src/Main.cpp"
)

target_sources(
  moduletest
  PRIVATE FILE_SET CXX_MODULES FILES
      "src/Math.ixx"
)

set_target_properties(
  moduletest
  PROPERTIES
    CXX_STANDARD 20
)
