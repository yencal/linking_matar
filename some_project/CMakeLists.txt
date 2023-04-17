cmake_minimum_required(VERSION 3.8)

project (some_project)

set(MATAR_PATH "../MATAR")
add_subdirectory(${MATAR_PATH} matar)
include_directories("${MATAR_PATH}/src")

add_executable(some_project main.cpp)
target_link_libraries(some_project matar)
