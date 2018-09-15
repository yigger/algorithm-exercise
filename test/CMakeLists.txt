cmake_minimum_required (VERSION 2.8)

project(alogrithm_test)

find_package(PkgConfig)
pkg_check_modules(CPPUTEST REQUIRED cpputest>=3.8)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CPPUTEST_CXX_FLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CPPUTEST_C_FLAGS}")

set(graph_test_sources graph_test.c graphTest.cpp)

include_directories(${PROJECT_SOURCE_DIR}/include ${CPPUTEST_INCLUDE_DIRS})

add_executable(graph_test ${graph_test_sources})

target_link_libraries(graph_test ${CPPUTEST_LDFLAGS})

add_test(GraphTest graph_test -c -v)