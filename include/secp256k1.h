#pragma once

#include <gmp.h>

typedef struct point {
    mpz_t x;
    mpz_t y;
} point_s;

typedef struct secp256k1 {
    mpz_t a;
    mpz_t b;
    mpz_t p;
    point_s g;
    mpz_t n;
} secp256k1_s;

void    init_secp256k1(secp256k1_s* secp256k1);
void    clear_secp256k1(secp256k1_s secp256k1);
void    dump_secp256k1(secp256k1_s secp256k1);
