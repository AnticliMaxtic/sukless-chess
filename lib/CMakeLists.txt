cmake_minimum_required(VERSION 3.25.0)
set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)

add_library(util INTERFACE)
target_sources(util INTERFACE util/common_enums.h)
target_include_directories(util INTERFACE util)
add_library(sukless::util ALIAS util)

add_library(game)
target_sources(game PRIVATE Game/Game.cpp Game/Piece.cpp)
target_include_directories(game PUBLIC Game)

if(WIN32)
  find_package(SDL2_image REQUIRED)
  target_link_libraries(
    game
    PUBLIC
      $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
      $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
      $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
  )
else()
  find_package(sdl2-image REQUIRED)
  target_link_libraries(game PUBLIC SDL2::SDL2)
endif()

target_link_libraries(
  game
  PUBLIC
    $<IF:$<TARGET_EXISTS:SDL2_mixer::SDL2_mixer>,SDL2_mixer::SDL2_mixer,SDL2_mixer::SDL2_mixer-static>
    sukless::util
)

add_library(sukless::game ALIAS game)

add_library(AI)
target_sources(AI PRIVATE AI/AI.cpp)
target_include_directories(AI PUBLIC AI)
target_link_libraries(
  AI
  PUBLIC sukless::util
         #TODO (Max): break this dependency
         sukless::game
)
add_library(sukless::AI ALIAS AI)
