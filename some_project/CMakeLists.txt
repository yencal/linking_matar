cmake_minimum_required(VERSION 3.8)

project (some_project)

if (KOKKOS)
  add_definitions(-DHAVE_KOKKOS=1)
  if (CUDA)
    add_definitions(-DHAVE_CUDA=1)
  elseif (HIP)
    add_definitions(-DHAVE_HIP=1)
  elseif (OPENMP)
    add_definitions(-DHAVE_OPENMP=1)
  elseif (THREADS)
    add_definitions(-DHAVE_THREADS=1)
  #else ()
  endif()
endif()

set(MATAR_PATH "../MATAR")
add_subdirectory(${MATAR_PATH} matar)
include_directories("${MATAR_PATH}/src")

add_executable(some_project main.cpp)
target_link_libraries(some_project matar)
