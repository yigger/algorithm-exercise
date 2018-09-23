cmake_minimum_required (VERSION 2.8)

project(alogrithm_test)

find_package(PkgConfig)
pkg_check_modules(CPPUTEST REQUIRED cpputest>=3.2)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CPPUTEST_C_FLAGS}")

set(graph_test_sources graph_test.c graphTest.cpp)
set(stack_test_sources stack_test.c stackTest.cpp)
set(deque_test_sources deque_test.c deque_test.cpp)

include_directories(${PROJECT_SOURCE_DIR}/include ${alotrithm_lib_INCLUDE_DIRS} ${CPPUTEST_INCLUDE_DIRS})

add_executable(graph_test ${graph_test_sources})
add_executable(stack_test ${stack_test_sources})
add_executable(deque_test ${stack_test_sources})

target_link_libraries(graph_test alotrithm_lib ${CPPUTEST_LDFLAGS})
target_link_libraries(stack_test alotrithm_lib ${CPPUTEST_LDFLAGS})
target_link_libraries(deque_test alotrithm_lib ${CPPUTEST_LDFLAGS})

add_test(GraphTest graph_test -c -v)
add_test(StackTest stack_test -c -v)
add_test(DequeTest deque_test -c -v)