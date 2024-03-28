
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
add_test(iobuf_file iobuf_file)

add_executable(iobuf_file_leb128 src/0001.10million/iobuf_file_leb128.cc)
add_test(iobuf_file_leb128 iobuf_file_leb128)

add_executable(concat_string src/0002.concatstring/concat_string.cc)
add_test(concat_string concat_string)

add_executable(list_sort src/0003.list_sort/list_sort.cc)
add_test(list_sort list_sort)

add_executable(dijkstra_optimize_fastio src/0004.dijkstra/dijkstra_optimize_fastio.cc)
add_test(dijkstra_optimize_fastio dijkstra_optimize_fastio)

add_executable(dijkstra_optimize_fastio_unchecked src/0004.dijkstra/dijkstra_optimize_fastio_unchecked.cc)
add_test(dijkstra_optimize_fastio_unchecked dijkstra_optimize_fastio_unchecked)