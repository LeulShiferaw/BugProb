cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE debug)
set (CMAKE_CXX_STANDARD 11)

project(Bug_World)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
