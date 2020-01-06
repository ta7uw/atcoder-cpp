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

# ライブラリ検証用
add_executable(bellman_ford lib/graph/bellman_ford.cpp)
add_executable(dag lib/graph/dag.cpp)

add_executable(warshall_floyd lib/graph/warshall_floyd.cpp)

add_executable(dijkstra lib/graph/dijkstra.cpp)

add_executable(binary_indexed_tree lib/tree/binary_indexed_tree.cpp)

add_executable(binary_indexed_tree_2d lib/tree/binary_indexed_tree_2d.cpp)

add_executable(kruskal lib/tree/kruskal.cpp)

add_executable(prim lib/tree/prim.cpp)

add_executable(bipartite_graph lib/graph/bipartite_graph.cpp)

add_executable(weighted_union_find lib/tree/weighted_union_find.cpp)

add_executable(rolling_hash lib/string/rolling_hash.cpp)

add_executable(compress_value lib/util/compress_value.cpp)

add_executable(segment_tree lib/tree/segment_tree.cpp)

add_executable(lazy_segment_tree lib/tree/lazy_segment_tree.cpp)

add_executable(mod_inverse lib/number/mod_inverse.cpp)
