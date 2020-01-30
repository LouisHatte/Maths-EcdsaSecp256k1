#include <stdio.h>

#include "secp256k1.h"

int main(void) {
    secp256k1_s secp256k1;

    init_secp256k1(&secp256k1);
    dump_secp256k1(secp256k1);
    return 0;
}
