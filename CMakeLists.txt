cmake_minimum_required(VERSION 3.13)
project(Orzel_7)
set(CMAKE_CXX_STANDARD 14)

include_directories(${inc})
include_directories(${src})

add_executable("${PROJECT_NAME}" main.cpp)
target_include_directories("${PROJECT_NAME}" PRIVATE scr inc)

