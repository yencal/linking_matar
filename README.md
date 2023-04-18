# linking_matar
## Description
`linking_matar` is an example on how to link new projects to MATAR and Kokkos. To follow alone with the example clone the repo
```
git clone --recursive https://github.com/yencal/linking_matar.git
```

Assume that the project we want to linked to MATAR and Kokkos is called `some_project`.
In the `some_project\CMakeLists.txt` simply add
```
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
set(MATAR_PATH "../MATAR") # path to where you have MATAR downloaded
add_subdirectory(${MATAR_PATH} matar)
include_directories("${MATAR_PATH}/src")
```

## OpenMP build
Before you can build `some_project`, we need to specify an installation of Kokkos and a `Kokkos_DIR`. You can install Kokkos yourself or use one of the scripts in `MATAR/scripts/`. Lets use `../MATAR/scripts/kokkos-openmp`
* Step 1:
```
cd ../MATAR/scripts/kokkos-openmp
source build-it.sh
```

* Step 2:
Now set `Kokkos_DIR` as
```
export Kokkos_DIR=../MATAR/src/install-kokkos-openmp/kokkos/
```

* Step 3:
You can build `some_project` using
```
cmake . -DKOKKOS=ON -DOPENMP=ON
make
```

## CUDA build
If you would like to do a `CUDA`, `HIP`, or `THREADS` build, make sure you have the correct version of Kokkos installed then follow the same steps as the OpenMP build. Lets do a `CUDA` build for example
* Step 1:
```
cd ../MATAR/scripts/kokkos-cuda
source build-it.sh
```

* Step 2:
```
export Kokkos_DIR=../MATAR/src/install-kokkos-cuda/kokkos/
```

* Step 3:
```
cmake . -DKOKKOS=ON -DCUDA=ON
make
```
