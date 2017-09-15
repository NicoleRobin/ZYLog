cmake_minimum_required (VERSION 2.6)
project(example)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_C_COMPILER /usr/bin/gcc)


add_executable(example_1 ./example_1.cpp)
target_link_libraries(example_1 zylog pthread)

add_executable(example_2 ./example_2.cpp)
target_link_libraries(example_2 zylog pthread)
