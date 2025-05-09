cmake_minimum_required(VERSION 3.31)

project(lab03)

file(GLOB_RECURSE SRC "src/*.cpp")
add_executable(lab03 ${SRC})
target_link_libraries(lab03)
