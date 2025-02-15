cmake_minimum_required(VERSION 3.31)

project(lab04)

file(GLOB_RECURSE SRC "src/*.cpp")
include_directories(include)
add_executable(lab04 ${SRC})
target_link_libraries(lab01)
