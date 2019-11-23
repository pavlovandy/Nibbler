set(src SFML.cpp)
set(head SFML.hpp)

find_package(SFML 2.5 REQUIRED system window graphics)

add_library(LibSFML SHARED ${src} ${head})

target_link_libraries(LibSFML sfml-graphics sfml-window sfml-system)

target_include_directories(LibSFML PUBLIC ../game_logic/)
target_include_directories(LibSFML PUBLIC ../)
