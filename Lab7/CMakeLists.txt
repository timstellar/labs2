cmake_minimum_required(VERSION 3.31)

project(lab07)

file(GLOB_RECURSE SRC "src/*.cpp")
include_directories(include)
add_executable(lab07 ${SRC})
target_link_libraries(lab01)
