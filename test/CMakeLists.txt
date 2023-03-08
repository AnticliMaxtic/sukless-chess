cmake_minimum_required(VERSION 3.25.0)
set(CMAKE_CXX_STANDARD 20)

project(tests LANGUAGES CXX VERSION 0.0.0)

find_package(Catch2 REQUIRED)

include(CTest)
include(Catch)

add_executable(tests)
target_sources(tests PRIVATE test_Piece.cpp)
target_link_libraries(tests PRIVATE sukless::game Catch2::Catch2WithMain)

catch_discover_tests(tests)
