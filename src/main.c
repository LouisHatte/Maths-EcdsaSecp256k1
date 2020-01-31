#include "modinv.h"
#include "secp256k1.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    secp256k1_s secp256k1;
    mpz_t r;

    init_secp256k1(&secp256k1);
    // dump_secp256k1(secp256k1);

    mpz_init_set_si(r, 1);
    modinv(secp256k1.g.x, secp256k1.p, r);
    gmp_printf("r = %Zd\n", r);

    clear_secp256k1(secp256k1);
    mpz_clear(r);

    return 0;
}
