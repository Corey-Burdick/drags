cmake_minimum_required(VERSION 4.0)
project(drags VERSION 0.1.06)

set(CMAKE_USE_RELATIVE_PATHS TRUE)

set(SOURCE_LIST src/main.cpp src/dragsiolib.cpp src/dragsortlib.cpp)

add_executable(drags ${SOURCE_LIST})
