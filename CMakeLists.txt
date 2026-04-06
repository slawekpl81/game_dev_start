cmake_minimum_required(VERSION 3.31)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(game_dev_1)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(libs/slk_raylib_basics)

include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)
FetchContent_MakeAvailable(raylib)

add_executable(game_dev_1 main.cpp)
target_link_libraries(game_dev_1 PRIVATE raylib)
target_link_libraries(game_dev_1 PRIVATE slk_raylib_basics)
