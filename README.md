# linking_matar
## Description
`linking_matar` is an example on how to link new projects to MATAR and Kokkos

Assume that the project we want to linked to MATAR and Kokkos is called `some_project`.
In the `some_project\CMakeLists.txt` simply add
```
set(MATAR_PATH "../MATAR") # path to where you have MATAR downloaded
add_subdirectory(${MATAR_PATH} matar)
include_directories("${MATAR_PATH}/src")
```

Before you can build `some_project`, we need to specify an installation of Kokkos and a `Kokkos_DIR`. You can install Kokkos yourself or use one of the scripts in `MATAR/scripts/`. Lets us `../MATAR/scripts/kokkos-openmp`
```
cd ../MATAR/scripts/kokkos-openmp
source build-it.sh
```
Now set `Kokkos_DIR` as
```
export Kokkos_DIR=../MATAR/src/install-kokkos-openmp/kokkos/
```

You can build `some_project` using
```
cmake . -DKokkos=ON -DOPENMP=ON
make
```
