set(head
    DyLibLoad.hpp
	terminal_colors.hpp
)

set(src 
	DyLibLoad.cpp
)

add_library(dlloader STATIC ${src} ${head})

target_link_libraries(dlloader PUBLIC iGraphicLibrary)

target_include_directories(dlloader PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/../graphic/")