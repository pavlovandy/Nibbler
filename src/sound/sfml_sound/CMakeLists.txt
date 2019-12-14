set(src SFML_sound.cpp)
set(head SFML_sound.hpp)

find_package(SFML 2.5 REQUIRED system audio)
include_directories(INTERFACE "../")

add_library(SFML_audioLib SHARED ${src} ${head})

target_link_libraries(SFML_audioLib sfml-system sfml-audio)

