#pragma once

#include <gmp.h>

typedef struct point {
    mpf_t x;
    mpf_t y;
} point_s;

typedef struct secp256k1 {
    mpf_t a;
    mpf_t b;
    mpf_t p;
    point_s g;
    mpf_t n;
} secp256k1_s;

void    init_secp256k1(secp256k1_s *secp256k1);
void    clear_secp256k1(secp256k1_s secp256k1);
void    dump_secp256k1(secp256k1_s secp256k1);
