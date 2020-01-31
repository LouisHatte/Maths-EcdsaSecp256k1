#include "modinv.h"
#include "secp256k1.h"
#include "ECdouble.h"
#include "ECadd.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    secp256k1_s secp256k1;
    // mpz_t r;
    point_s p;
    point_s q;
    mpz_t zTmp1;
    mpz_t zTmp2;
    mpz_t zTmp3;
    mpz_init_set_si(zTmp1, 0);
    mpz_init_set_si(zTmp2, 0);
    mpz_init_set_si(zTmp3, 0);

    init_secp256k1(&secp256k1);
    // dump_secp256k1(secp256k1);

    // mpz_init_set_si(r, 1);
    // modinv(secp256k1.g.x, secp256k1.p, r);
    // gmp_printf("r = %Zd\n", r);

    p = elliptic_curve_point_double(secp256k1.g, secp256k1);
    // gmp_printf("p.x = %Zd\n", p.x);
    // gmp_printf("p.y = %Zd\n", p.y);

    q = elliptic_curve_point_add(secp256k1.g, p, secp256k1);
    // gmp_printf("q.x = %Zd\n", q.x);
    // gmp_printf("q.y = %Zd\n", q.y);

    // mpz_mul(zTmp1, p.x, p.x);
    // mpz_mul(zTmp2, zTmp1, p.x);
    // mpz_add(zTmp1, zTmp2, secp256k1.b);
    // mpz_mul(zTmp2, p.y, p.y);
    // mpz_sub(zTmp3, zTmp1, zTmp2);
    // mpz_fdiv_r(zTmp1, zTmp3, secp256k1.p);
    // gmp_printf("0 = %Zd\n", zTmp1);

    // mpz_mul(zTmp1, q.x, q.x);
    // mpz_mul(zTmp2, zTmp1, q.x);
    // mpz_add(zTmp1, zTmp2, secp256k1.b);
    // mpz_mul(zTmp2, q.y, q.y);
    // mpz_sub(zTmp3, zTmp1, zTmp2);
    // mpz_fdiv_r(zTmp1, zTmp3, secp256k1.p);
    // gmp_printf("0 = %Zd\n", zTmp1);

    clear_secp256k1(secp256k1);
    // mpz_clear(r);
    mpz_clear(zTmp1);
    mpz_clear(zTmp2);
    mpz_clear(zTmp3);
    mpz_clear(p.x);
    mpz_clear(p.y);
    mpz_clear(q.x);
    mpz_clear(q.y);

    return 0;
}
