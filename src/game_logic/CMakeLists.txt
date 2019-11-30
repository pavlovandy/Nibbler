set(src Game.cpp Map.cpp Snake.cpp)
set(head Dot.hpp Game.hpp Map.hpp Snake.hpp)

add_library(gameLogic STATIC ${src} ${head})

target_link_libraries(gameLogic iGraphicLibrary dlloader)

target_include_directories(gameLogic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(gameLogic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../graphic/)
target_include_directories(gameLogic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../other/)