set(src SDL.cpp)
set(head SDL.hpp)

set(SDL2_PATH "~/.brew/Cellar/sdl2/")
set(SDL2_TTF_PATH "~/.brew/Cellar/sdl2_ttf/")
set(SDL2_IMAGE_PATH "~/.brew/Cellar/sdl2_image/")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/")

# SDL2
set(SDL2_INCLUDE_DIR ~/.brew/Cellar/sdl2/2.0.10/include/SDL2/)
set(SDL2_LIBRARY ~/.brew/Cellar/sdl2/2.0.10/lib/)
# SDL2 Image
set(SDL2_IMAGE_INCLUDE_DIR ~/.brew/Cellar/sdl2_image/2.0.5/include/SDL2/)
set(SDL2_IMAGE_LIBRARY ~/.brew/Cellar/sdl2_image/2.0.5/lib/)
# SDL2 TTF
set(SDL2_TTF_INCLUDE_DIR ~/.brew/Cellar/sdl2_ttf/2.0.15/include/SDL2/)
set(SDL2_TTF_LIBRARY ~/.brew/Cellar/sdl2_ttf/2.0.15/lib/)

include_directories(INTERFACE "../" PUBLIC "../../game_logic/")

include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR})

link_directories(
            ${SDL2_LIBRARY}
            ${SDL2_IMAGE_LIBRARY}
            ${SDL2_TTF_LIBRARY})

add_library(SDL_lib SHARED ${src} ${head})

target_link_libraries(SDL_lib PUBLIC -lSDL2 -lSDL2_image -lSDL2_ttf game_logic)


