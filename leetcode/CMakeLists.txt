cmake_minimum_required(VERSION 3.15)
project(leetcode C)

set(CMAKE_C_STANDARD 11)

add_executable(leetcode
        src/main.c src/candy.c src/circle.c src/leetcode_common.h)

add_executable(leetcode_libuv
        test/iotest/libuvmain.c)

include_directories(${CMAKE_SOURCE_DIR}/include/libuv)

include_directories(${CMAKE_SOURCE_DIR}/include/uthash)

find_library(TEST_LIB libuv.a ${CMAKE_SOURCE_DIR}/lib)

target_link_libraries(leetcode_libuv LINK_PUBLIC ${TEST_LIB})