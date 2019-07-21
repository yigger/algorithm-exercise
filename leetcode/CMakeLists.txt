project(LeetCode)

include_directories(${PROJECT_NAME}_INCLUDE_DIRS ${alotrithm_lib_INCLUDE_DIRS})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CPPUTEST_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_executable(leetcodeLink link.c)

target_link_libraries(leetcodeLink alotrithm_lib)
