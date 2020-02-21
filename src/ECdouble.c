#include "ECdouble.h"
#include "modinv.h"

point_s elliptic_curve_point_double(point_s p, secp256k1_s secp256k1) {
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

    mpz_mul(zTmp1, p.x, p.x);
    mpz_mul_si(zTmp2, zTmp1, 3);
    mpz_add(zTmp1, zTmp2, secp256k1.a);
    mpz_mul_si(zTmp2, p.y, 2);
    modinv(zTmp2, secp256k1.p, zTmp3);
    mpz_mul(zTmp2, zTmp1, zTmp3);
    mpz_fdiv_r(s, zTmp2, secp256k1.p);

    mpz_mul(zTmp1, s, s);
    mpz_mul_si(zTmp2, p.x, 2);
    mpz_sub(zTmp3, zTmp1, zTmp2);
    mpz_fdiv_r(res.x, zTmp3, secp256k1.p);

    mpz_sub(zTmp1, p.x, res.x);
    mpz_mul(zTmp2, s, zTmp1);
    mpz_sub(zTmp1, zTmp2, p.y);
    mpz_fdiv_r(res.y, zTmp1, secp256k1.p);

    mpz_clear(zTmp1);
    mpz_clear(zTmp2);
    mpz_clear(zTmp3);
    mpz_clear(s);

    mpz_clear(p.x);
    mpz_clear(p.y);

    return res;
}
