cmake_minimum_required(VERSION 3.23)
project(smuggling_problem)

set(CMAKE_CXX_STANDARD 20)

add_executable(smuggling_problem main.cpp smuggle.cpp smuggle.h)

string(APPEND CMAKE_CXX_FLAGS " -O2 -pipe -march=native")
string(APPEND CMAKE_C_FLAGS " -O2 -pipe -march=native")
add_compile_options(-O2 -pipe -march=native)
