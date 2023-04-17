cmake_minimum_required(VERSION 3.8)

project (some_project)

add_subdirectory(../MATAR matar)
include_directories(../MATAR/src)

add_executable(some_project main.cpp)
target_link_libraries(some_project matar)
