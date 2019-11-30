add_library(iGraphicLib INTERFACE)

target_sources(iGraphicLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/IGraphicLibrary.hpp)

target_link_libraries(iGraphicLib INTERFACE gameLogic)

target_include_directories(iGraphicLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(iGraphicLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../game_logic/)

add_subdirectory("SDL")
add_subdirectory("SFML")
#add_subdirectory("OpenGL") add this