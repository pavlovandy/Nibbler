set(src SFML.cpp)
set(head SFML.hpp)
set(SFML_DIR ../../../cmake_modules/)
find_package(SFML 2.5 REQUIRED system window graphics)
include_directories(INTERFACE "../" PUBLIC "../../game_logic/")

add_library(SFML_lib SHARED ${src} ${head})

target_link_libraries(SFML_lib sfml-graphics sfml-window sfml-system game_logic)

