# 项目信息
project (algorithm)

# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

enable_language(C)

set(CFLAGS "-Wall -Werror")
set(MODELFLAGS "-std=c99")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CFLAGS} ${MODELFLAGS}")
set(CMAKE_MACOSX_RPATH TRUE)
enable_testing()

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(example)
add_subdirectory(leetcode)
