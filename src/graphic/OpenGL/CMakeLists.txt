set(src OpenGL.cpp)
set(head OpenGL.hpp)

find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
include_directories(INTERFACE "../" PUBLIC "../../game_logic/")

add_library(OpenGL_lib SHARED ${src} ${head})

target_link_libraries(OpenGL_lib PUBLIC ${OPENGL_gl_LIBRARY} glfw game_logic)
target_include_directories(OpenGL_lib PUBLIC ${OPENGL_INCLUDE_DIR})