cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(CmanProject VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES
     src/*.cpp
)
add_executable(CmanDemo ${SOURCES})
