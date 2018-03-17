cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/src)

enable_testing()
find_package(GTest REQUIRED)

set(LIBS bug cell instruction marker world)

add_executable(gtest-bug gtest-bug.cc)
target_link_libraries(gtest-bug GTest::GTest GTest::Main ${LIBS})

add_test(Buggy gtest-bug)
