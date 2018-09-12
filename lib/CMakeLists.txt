cmake_minimum_required(VERSION 2.8)

project(alotrithms)

file(GLOB source_files "*.c")
file(GLOB header_files "*.h")

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

# 生成链接库
# add_library(COMMONFUNC ${DIR_LIB_SRCS})

add_library(${PROJECT_NAME} SHARED ${source_files})
add_library(${PROJECT_NAME}_static STATIC ${source_files})