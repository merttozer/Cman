cmake_minimum_required(VERSION 3.10)
project(CmanProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Automatically collect all .cpp files in the src directory and its subdirectories
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(CmanDemo ${SOURCES})
target_include_directories(CmanDemo PRIVATE src)
