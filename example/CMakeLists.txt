project(Example)

include_directories(${PROJECT_NAME}_INCLUDE_DIRS ${alotrithm_lib_INCLUDE_DIRS})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CPPUTEST_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_executable(stack stack.c)
add_executable(deque deque.c)
add_executable(tree binaryTree.c)
add_executable(link link.c)
add_executable(dict dict.c)
add_executable(redblacktree redblackTree.c)
add_executable(graph graph.c)
add_executable(array array.c)

target_link_libraries(stack alotrithm_lib)
target_link_libraries(tree alotrithm_lib)
target_link_libraries(link alotrithm_lib)
target_link_libraries(dict alotrithm_lib)
target_link_libraries(graph alotrithm_lib)
target_link_libraries(deque alotrithm_lib)
target_link_libraries(array alotrithm_lib)
