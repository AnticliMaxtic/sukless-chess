cmake_minimum_required(VERSION 3.25.0)
set(CMAKE_CXX_STANDARD 20)

project(chess LANGUAGES C CXX)

add_executable(chess)
target_sources(chess PRIVATE main.cpp App.cpp)
target_include_directories(chess PRIVATE ${PROJECT_SOURCE_DIR})

target_link_libraries(chess PRIVATE sukless::game sukless::AI)
