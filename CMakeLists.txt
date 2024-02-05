cmake_minimum_required(VERSION 3.10)
project(CmanProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CmanDemo src/main.cpp src/complex/complex.cpp)
target_include_directories(CmanDemo PRIVATE src)
