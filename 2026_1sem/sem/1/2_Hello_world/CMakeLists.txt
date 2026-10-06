cmake_minimum_required(VERSION 3.20)
# ^ Minimal of version of CMake you need to begin the build

set(CMAKE_C_COMPILER gcc)
# ^ Variable of or path to C compiler
set(CMAKE_CXX_COMPILER g++)
# ^ Variable of or path to C++ compiler
project(HelloWorldProject)
# ^ Name of project

message(INFO:\ ${HelloWorldProject_SOURCE_DIR})
# ^ Log message
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${HelloWorldProject_SOURCE_DIR}/bin)
# ^ Directory where store build of project

add_executable(HelloWorldProjectMain main.cpp) 
# ^ Create executable with sources