cmake_minimum_required (VERSION 2.8)

project(alogrithm_test)

find_package(PkgConfig)
pkg_check_modules(CPPUTEST REQUIRED cpputest>=3.8)

include_directories(${PROJECT_SOURCE_DIR}/lib)

set(graph_test_sources graph_test.c)
add_executable(graph_test ${graph_test_sources})
target_link_libraries(graph_test alotrithms ${CPPUTEST_LDFLAGS})
add_test(graph_test -c -v)