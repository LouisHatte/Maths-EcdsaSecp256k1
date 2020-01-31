#include "secp256k1.h"

void    init_secp256k1(secp256k1_s *secp256k1) {
    mpz_init_set_si(secp256k1->a, 0);
    mpz_init_set_si(secp256k1->b, 7);
    mpz_init_set_str(secp256k1->p, "fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f", 16);

    mpz_init_set_str(secp256k1->g.x, "79BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798", 16);
    mpz_init_set_str(secp256k1->g.y, "483ADA7726A3C4655DA4FBFC0E1108A8FD17B448A68554199C47D08FFB10D4B8", 16);

    mpz_init_set_str(secp256k1->n, "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364141", 16);
}

void    clear_secp256k1(secp256k1_s secp256k1) {
    mpz_clear(secp256k1.a);
    mpz_clear(secp256k1.b);
    mpz_clear(secp256k1.p);

    mpz_clear(secp256k1.g.x);
    mpz_clear(secp256k1.g.y);

    mpz_clear(secp256k1.n);
}

void    dump_secp256k1(secp256k1_s secp256k1) {
    gmp_printf("a = %Zd\n", secp256k1.a);
    gmp_printf("b = %Zd\n", secp256k1.b);
    gmp_printf("p = %Zd\n\n", secp256k1.p);

    gmp_printf("g.x = %Zd\n", secp256k1.g.x);
    gmp_printf("g.y = %Zd\n\n", secp256k1.g.y);

    gmp_printf("n = %Zd\n\n", secp256k1.n);
}
