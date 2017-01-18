cmake_minimum_required(VERSION 2.6)
project(zylog)
	
set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_C_COMPILER /usr/bin/gcc)

add_library(zylog ./ZYLog.cpp)
