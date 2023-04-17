#include <stdio.h>

#include "matar.h"

using namespace mtr; // matar namespace

int main() {

    printf("Hello World\n");

    auto test = CArray <int> (5, 5);

    auto test1 = CArrayKokkos <int> (5,5);

    return 0;
}
