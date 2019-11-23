set(src Dot.cpp Game.cpp Map.cpp Snake.cpp)
set(head Dot.hpp Game.hpp Map.hpp Snake.hpp)

add_library(SDLlib STATIC ${src} ${head})

target_link_libraries(SDLib iGraphicLibrary dlloader)

target_include_directories(SDLlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../graphic/ ${CMAKE_CURRENT_SOURCE_DIR}/../other/)