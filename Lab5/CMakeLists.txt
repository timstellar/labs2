cmake_minimum_required(VERSION 3.31)

project(lab05)

file(GLOB_RECURSE SRC "src/*.cpp")
include_directories(include)
add_executable(lab05 ${SRC})
target_link_libraries(lab05)
