set(src SDL.cpp)
set(head SDL.hpp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake_modules/")

# SDL2
set(SDL2_INCLUDE_DIR ~/.brew/Cellar/sdl2/2.0.9_1/include/SDL2/)
set(SDL2_LIBRARY ~/.brew/Cellar/sdl2/2.0.9_1/lib/)

# SDL2 Image
set(SDL2_IMAGE_INCLUDE_DIR ~/.brew/Cellar/sdl2_image/2.0.5/include/SDL2/)
set(SDL2_IMAGE_LIBRARY ~/.brew/Cellar/sdl2_image/2.0.5/lib/)
# SDL2 TTF
set(SDL2_TTF_INCLUDE_DIR ~/.brew/Cellar/sdl2_ttf/2.0.15/include/SDL2/)
set(SDL2_TTF_LIBRARY ~/.brew/Cellar/sdl2_ttf/2.0.15/lib/)

find_package(SDL2 REQUIRED)

include_directories(
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})
include_directories(INTERFACE "../" PUBLIC "../../game_logic/")

add_library(SDL_lib SHARED ${src} ${head})

target_link_libraries(SDL_lib PUBLIC ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2_IMAGE_LIBRARY} game_logic)

