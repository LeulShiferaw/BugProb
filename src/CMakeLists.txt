cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_BINARY_DIR}/src)

add_library(bug bug.cc)
add_library(cell cell.cc)
add_library(instruction instruction.cc)
add_library(marker marker.cc)
add_library(world world.cc)
