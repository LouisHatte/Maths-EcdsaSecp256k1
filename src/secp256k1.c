#include "secp256k1.h"

void    init_secp256k1(secp256k1_s *secp256k1) {
    mpz_init_set_si(secp256k1->a, 0);
    mpz_init_set_si(secp256k1->b, 7);
    mpz_init_set_str(secp256k1->p, "fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f", 16);

    mpz_init_set_str(secp256k1->g.x, "79be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798", 16);
    mpz_init_set_str(secp256k1->g.y, "483ada7726a3c4655da4fbfc0e1108a8fd17b448a68554199c47d08ffb10d4b8", 16);

    mpz_init_set_str(secp256k1->n, "fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141", 16);
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
