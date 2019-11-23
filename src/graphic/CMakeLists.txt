add_library(iGraphicLib INTERFACE)

target_sources(IGraphicLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/IGraphicLibrary.hpp)

target_include_directories(IGraphicLib PUBLIC gameLogic ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory("SDL")
add_subdirectory("SFML")
#add_subdirectory("OpenGL") add this