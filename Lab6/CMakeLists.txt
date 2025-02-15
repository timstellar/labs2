cmake_minimum_required(VERSION 3.31)

project(lab06)

file(GLOB_RECURSE SRC "src/*.cpp")
include_directories(include)
add_executable(lab06 ${SRC})
target_link_libraries(lab01)
