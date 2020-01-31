#include "ECadd.h"
#include "modinv.h"

point_s elliptic_curve_point_add(point_s p, point_s q, secp256k1_s secp256k1) {
    mpz_t zTmp1;
    mpz_t zTmp2;
    mpz_t zTmp3;
    mpz_init_set_si(zTmp1, 0);
    mpz_init_set_si(zTmp2, 0);
    mpz_init_set_si(zTmp3, 0);

    mpz_t   s;
    mpz_init_set_si(s, 0);

    point_s res;
    mpz_init_set_si(res.x, 0);
    mpz_init_set_si(res.y, 0);

    mpz_sub(zTmp1, q.y, p.y);
    mpz_sub(zTmp2, q.x, p.x);
    modinv(zTmp2, secp256k1.p, zTmp3);
    mpz_mul(zTmp2, zTmp1, zTmp3);
    mpz_fdiv_r(s, zTmp2, secp256k1.p);
    // gmp_printf ("s = %Zd\n", s);

    mpz_mul(zTmp1, s, s);
    mpz_sub(zTmp2, zTmp1, p.x);
    mpz_sub(zTmp1, zTmp2, q.x);
    mpz_fdiv_r(res.x, zTmp1, secp256k1.p);
    // gmp_printf ("x = %Zd\n", res.x);

    mpz_sub(zTmp1, p.x, res.x);
    mpz_mul(zTmp2, s, zTmp1);
    mpz_sub(zTmp1, zTmp2, p.y);
    mpz_fdiv_r(res.y, zTmp1, secp256k1.p);
    // gmp_printf ("y = %Zd\n", res.y);

    mpz_clear(zTmp1);
    mpz_clear(zTmp2);
    mpz_clear(zTmp3);
    mpz_clear(s);

    return res;
}
