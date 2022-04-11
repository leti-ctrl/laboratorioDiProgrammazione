cmake_minimum_required(VERSION 3.15)
project(laboratorioDiProgrammazione)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILE Account.cpp Account.h Transaction.cpp Transaction.h)
add_executable(unit_testing main.cpp )
add_library(core ${SOURCE_FILE})
target_link_libraries(unit_testing core)