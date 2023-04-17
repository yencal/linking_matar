#include <stdio.h>

#include "matar.h"

using namespace mtr; // matar namespace

int main() {

    printf("Hello World\n");

    auto test = CArray <int> (5, 5);
#ifdef HAVE_KOKKOS
    auto test1 = CArrayKokkos <int> (5,5);
#endif
    return 0;
}
