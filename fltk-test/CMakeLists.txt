cmake_minimum_required(VERSION 3.6)
project(fltk_test)

find_package(fltk REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")

set(SOURCE_FILES main.cpp)
add_executable(fltk_test ${SOURCE_FILES})

target_link_libraries(fltk_test "-lfltk")