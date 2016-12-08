cmake_minimum_required (VERSION 2.6)
project(zylog)

include_directories(./include)
add_library(zylog ./src/ZYLog.cpp)
