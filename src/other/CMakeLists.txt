set(head
    DyLibLoad.hpp
	terminal_colors.hpp
)

set(src 
	DyLibLoad.cpp
)

add_library(dlloader PUBLIC ${src} ${head})

target_include_directories(dlloader PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"/ "${CMAKE_CURRENT_SOURCE_DIR}")