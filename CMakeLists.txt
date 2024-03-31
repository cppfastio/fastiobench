
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

add_test(NAME 10mint COMMAND ${CMAKE_CROSSCOMPILING_EMULATOR} $<TARGET_FILE:iobuf_file>)
add_test(NAME leb128 COMMAND ${CMAKE_CROSSCOMPILING_EMULATOR} $<TARGET_FILE:iobuf_file_leb128>)
add_test(NAME concat_string COMMAND ${CMAKE_CROSSCOMPILING_EMULATOR} $<TARGET_FILE:concat_string>)
add_test(NAME list_sort COMMAND ${CMAKE_CROSSCOMPILING_EMULATOR} $<TARGET_FILE:list_sort>)
add_test(NAME generate_graph COMMAND ${CMAKE_CROSSCOMPILING_EMULATOR} $<TARGET_FILE:generate_graph>)
add_test(NAME dijkstra COMMAND ${CMAKE_CROSSCOMPILING_EMULATOR} $<TARGET_FILE:dijkstra_optimize_fastio>)
add_test(NAME dijkstra_unchecked COMMAND ${CMAKE_CROSSCOMPILING_EMULATOR} $<TARGET_FILE:dijkstra_optimize_fastio_unchecked>)
set_tests_properties(dijkstra PROPERTIES DEPENDS "generate_graph")
set_tests_properties(dijkstra_unchecked PROPERTIES DEPENDS "generate_graph")
add_test(NAME sha512 COMMAND ${CMAKE_CROSSCOMPILING_EMULATOR} $<TARGET_FILE:sha512>)
add_test(NAME vec_push_back COMMAND ${CMAKE_CROSSCOMPILING_EMULATOR} $<TARGET_FILE:vector_push_back>)
add_test(NAME randpass COMMAND ${CMAKE_CROSSCOMPILING_EMULATOR} $<TARGET_FILE:ibuf_white_hole_engine>)
