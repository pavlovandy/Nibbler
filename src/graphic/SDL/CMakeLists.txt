
set(src SDL.cpp)
set(head SDL.hpp)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake_modules")
find_package(SDL2  REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(INTERFACE "../" PUBLIC "../../game_logic/")

add_library(SDL_lib SHARED ${src} ${head})

target_link_libraries(SDL_lib PUBLIC ${SDL2_LIBRARIES} game_logic)

