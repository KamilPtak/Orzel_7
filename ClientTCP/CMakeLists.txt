cmake_minimum_required(VERSION 3.13)
project(Client VERSION 0.1)
set(CMAKE_CXX_STANDARD 14)

enable_testing()

include_directories(${inc})
include_directories(${src})

add_executable("${PROJECT_NAME}"    src/main.cpp
                                    src/TCPconnection.cpp
                                    inc/myExceptions.hpp
                                    inc/userTypeDefs.hpp
                                    inc/TCPconnection.hpp
                                    )
                                    
target_include_directories("${PROJECT_NAME}" PRIVATE scr inc)

