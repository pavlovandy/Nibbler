set(src SFML_sound.cpp)
set(head SFML_sound.hpp)

find_package(SFML 2.5 REQUIRED system window audio)
include_directories(INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/../")

add_library(SFML_audioLib SHARED ${src} ${head})

target_link_libraries(SFML_lib sfml-audio sfml-window sfml-system)

