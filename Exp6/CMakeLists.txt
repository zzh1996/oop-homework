cmake_minimum_required(VERSION 3.6)
project(Exp6)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")

set(SOURCE_FILES main.cpp)
add_executable(Exp6 ${SOURCE_FILES})

target_link_libraries(Exp6 "-lfltk -mwindows")