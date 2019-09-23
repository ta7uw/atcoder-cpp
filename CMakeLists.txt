cmake_minimum_required(VERSION 3.14)
project(atcoder-cpp)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D__DEBUG")
set(CMAKE_BUILD_TYPE Debug)

#　実行用
add_executable(main run/main.cpp)
add_executable(c run/c.cpp)
add_executable(b run/b.cpp)
add_executable(a run/a.cpp)

add_executable(bellman_ford lib/graph/bellman_ford.cpp)
