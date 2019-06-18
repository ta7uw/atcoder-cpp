cmake_minimum_required(VERSION 3.14)
project(atcoder)

set(CMAKE_CXX_STANDARD 14)

add_executable(atcoder run/main.cpp)
add_executable(combination lib/combination.cpp)
add_executable(c run/c.cpp)
add_executable(b run/b.cpp)
add_executable(a run/a.cpp)