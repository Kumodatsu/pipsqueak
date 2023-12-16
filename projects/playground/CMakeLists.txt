cmake_minimum_required(VERSION 3.23.0)

project(
  playground
  VERSION     0.1.0
  DESCRIPTION "Test project for Pipsqueak."
  LANGUAGES   CXX
)

add_executable(
  playground
    "src/Main.cpp"
)

set_target_properties(
  playground
  PROPERTIES
    CXX_STANDARD 20
)

pipsqueak_set_warnings(playground)

target_include_directories(
  playground
  PRIVATE
    "src"
    "${CMAKE_SOURCE_DIR}/projects/pipsqueak/include"
)

target_link_libraries(
  playground
  PRIVATE
    "pipsqueak"
)
