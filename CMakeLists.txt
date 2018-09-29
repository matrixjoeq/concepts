cmake_minimum_required(VERSION 3.4.0)
project(stl-concepts)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/compiler_options.cmake)

include_directories(inc)

add_subdirectory(boost-cmake)
add_subdirectory(src)
