cmake_minimum_required(VERSION 3.8)
project(mtclub-it-quest3)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -g")
aux_source_directory(${PROJECT_SOURCE_DIR} DIR_SRCS)
include_directories(${PROJECT_SOURCE_DIR})

add_executable(mtclub-it-quest3 main.c list.c)