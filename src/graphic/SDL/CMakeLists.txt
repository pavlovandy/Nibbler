set(src SDL.cpp)
set(head SDL.hpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_library(SDLlib SHARED ${src} ${head})

target_link_libraries(SDLlib gameLogic iGraphicLibrary ${SDL2_LIBRARIES})

target_include_directories(SDLlib PUBLIC ../game_logic/)
target_include_directories(SDLlib PUBLIC ../)
