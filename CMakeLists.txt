
cmake_minimum_required(VERSION 3.15)

project(fastiobench)

set(CMAKE_CXX_STANDARD 26)

if(DEFINED FAST_IO_DIR)
include_directories(${FAST_IO_DIR}/include)
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Windows" OR CMAKE_SYSTEM_NAME STREQUAL "Cygwin" OR CMAKE_SYSTEM_NAME STREQUAL "Msys")
link_libraries(ntdll)
endif()

include(CTest)

add_executable(iobuf_file src/0001.10million/iobuf_file.cc)
add_executable(iobuf_file_leb128 src/0001.10million/iobuf_file_leb128.cc)
add_executable(concat_string src/0002.concatstring/concat_string.cc)
add_executable(list_sort src/0003.list_sort/list_sort.cc)
add_executable(generate_graph src/0004.dijkstra/generate_graph.cc)
add_executable(dijkstra_optimize_fastio src/0004.dijkstra/dijkstra_optimize_fastio.cc)
add_executable(dijkstra_optimize_fastio_unchecked src/0004.dijkstra/dijkstra_optimize_fastio_unchecked.cc)
add_executable(sha512 src/0005.sha/sha512.cc)
add_executable(vector_push_back src/0006.vector_push_back/vector_push_back.cc)
add_executable(ibuf_white_hole_engine src/0007.random/ibuf_white_hole_engine.cc)


add_test(iobuf_file iobuf_file)
add_test(iobuf_file_leb128 iobuf_file_leb128)
add_test(concat_string concat_string)
add_test(list_sort list_sort)
add_test(generate_graph generate_graph)
add_test(dijkstra dijkstra_optimize_fastio)
add_test(dijkstra_unchecked dijkstra_optimize_fastio_unchecked)
add_test(sha512 sha512)
add_test(vec_push_back vector_push_back)
add_test(randpass ibuf_white_hole_engine)
