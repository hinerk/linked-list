cmake_minimum_required(VERSION 3.14.1)
project(cp2105_programming C)

set(CMAKE_C_STANDARD 11)


add_library(linked-list linked-list.c)
add_executable(linked-list-tests tests.c)
target_link_libraries(linked-list-tests linked-list)
