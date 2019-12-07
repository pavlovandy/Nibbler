set(src SFML.cpp)
set(head SFML.hpp)

find_package(SFML 2.5 REQUIRED system window graphics)
include_directories(INTERFACE "../" PUBLIC "../../game_logic/")

add_library(SFML_lib SHARED ${src} ${head})

target_link_libraries(SFML_lib sfml-graphics sfml-window sfml-system game_logic)

