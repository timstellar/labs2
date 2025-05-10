cmake_minimum_required(VERSION 3.31)

project(hw)

file(GLOB_RECURSE SRC "src/*.cpp")
include_directories(include)
add_executable(hw ${SRC})
target_link_libraries(hw)
