cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_FLAGS "{CMAKE_CXX_FLAGS} -std=c++14")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

project(nibbler)

add_subdirectory("src")