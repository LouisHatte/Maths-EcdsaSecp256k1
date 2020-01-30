#include "secp256k1.h"

void    init_secp256k1(secp256k1_s *secp256k1) {
    mpf_init_set_si(secp256k1->a, 0);
    mpf_init_set_si(secp256k1->b, 7);
    mpf_init_set_str(secp256k1->p, "115792089237316195423570985008687907853269984665640564039457584007908834671663", 10);

    mpf_init_set_str(secp256k1->g.x, "79BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798", 16);
    mpf_init_set_str(secp256k1->g.y, "483ADA7726A3C4655DA4FBFC0E1108A8FD17B448A68554199C47D08FFB10D4B8", 16);

    mpf_init_set_str(secp256k1->n, "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364141", 16);
}

void    clear_secp256k1(secp256k1_s secp256k1) {
    mpf_clear(secp256k1.a);
    mpf_clear(secp256k1.b);
    mpf_clear(secp256k1.p);

    mpf_clear(secp256k1.g.x);
    mpf_clear(secp256k1.g.y);

    mpf_clear(secp256k1.n);
}

void    dump_secp256k1(secp256k1_s secp256k1) {
    gmp_printf ("a = %Ff\n", secp256k1.a);
    gmp_printf ("b = %Ff\n", secp256k1.b);
    gmp_printf ("p = %Ff\n\n", secp256k1.p);

    gmp_printf ("g.x = %Ff\n", secp256k1.g.x);
    gmp_printf ("g.x = %Ff\n\n", secp256k1.g.y);

    gmp_printf ("g.x = %Ff\n\n", secp256k1.n);
}
