cmake_minimum_required(VERSION 3.14)
project(Nibbler)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/game_logic)
include_directories(src/graphic)
include_directories(src/other)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_library(game_logic STATIC src/game_logic/Dot.hpp
        src/game_logic/Map.cpp
        src/game_logic/Map.hpp
        src/game_logic/Snake.cpp
        src/game_logic/Snake.hpp
        src/graphic/IGraphicLibrary.hpp
        src/other/DyLibLoad.cpp
        src/other/DyLibLoad.hpp
        src/game_logic/Game.cpp
        src/game_logic/Game.hpp
        src/other/terminal_colors.hpp)

set_property(TARGET game_logic PROPERTY POSITION_INDEPENDENT_CODE ON)

add_executable(${PROJECT_NAME}
        src/main.cpp)

target_link_libraries(${PROJECT_NAME} game_logic ${CMAKE_DL_LIBS})

add_subdirectory(src/graphic/SDL)
add_subdirectory(src/graphic/SFML)
add_subdirectory(src/graphic/OpenGL)