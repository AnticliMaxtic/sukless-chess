cmake_minimum_required(VERSION 3.25.0)
set(CMAKE_CXX_STANDARD 20)

project(chess LANGUAGES C CXX)

option(UNIT_TESTS "Build the unit tests" OFF)

add_subdirectory(app/chess)
add_subdirectory(lib)

if(UNIT_TESTS)
  add_subdirectory(test)
endif()

file(COPY resources DESTINATION ${PROJECT_BINARY_DIR})
