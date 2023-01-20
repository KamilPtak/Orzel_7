cmake_minimum_required(VERSION 3.13)
project(Orzel_7 VERSION 0.1)
set(CMAKE_CXX_STANDARD 14)
find_package(Threads REQUIRED)


enable_testing()

include_directories(${inc})
include_directories(${src})

add_executable("${PROJECT_NAME}"    src/main.cpp
                                    src/vechicle.cpp
                                    src/TCPconnection.cpp
                                    src/PID.cpp
                                    src/MPU6050.cpp
                                    # src/imuTest.cpp
                                    
                                    inc/vechicle.hpp
                                    inc/myExceptions.hpp
                                    inc/TCPconnection.hpp
                                    inc/PID.hpp
                                    inc/MPU6050.h
                                    )

target_link_libraries("${PROJECT_NAME}"  pthread )
target_link_libraries("${PROJECT_NAME}" i2c)
target_include_directories("${PROJECT_NAME}" PRIVATE scr inc)

