cmake_minimum_required(VERSION 3.15)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Fix behavior of CMAKE_CXX_STANDARD when targeting macOS
if (POLICY CMP0025)
  cmake_policy(SET CMP0025 NEW)
endif ()

project(nibbler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory("src")