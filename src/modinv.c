#include "modinv.h"

#include <stdio.h>
#include <stdlib.h>

void    modinv(mpz_t value, mpz_t p, mpz_t res) {
    mpz_t zTmp1;
    mpz_init_set_si(zTmp1, 0);

    mpz_t lm;
    mpz_t hm;
    mpz_init_set_si(lm, 1);
    mpz_init_set_si(hm, 0);

    mpz_t low;
    mpz_t high;
    mpz_init(low);
    mpz_fdiv_r(low, value, p);
    mpz_init_set(high, p);

    mpz_t ratio;
    mpz_init_set_si(ratio, 0);

    mpz_t nm;
    mpz_t new;
    mpz_init_set_si(nm, 0);
    mpz_init_set_si(new, 0);

    int cmp = -1;

    // gmp_printf ("value: %Zd\n", value);
    // gmp_printf ("p: %Zd\n", p);
    // gmp_printf ("lm: %Zd\n", lm);
    // gmp_printf ("hm: %Zd\n", hm);
    // gmp_printf ("low: %Zd\n", low);
    // gmp_printf ("high: %Zd\n", high);

    while ((cmp = mpz_cmp_si(low, 1)) > 0) {
        mpz_fdiv_q(ratio, high, low);
        // gmp_printf ("ratio = %.10Zd\n", ratio);

        mpz_mul(zTmp1, lm, ratio);
        mpz_sub(nm, hm, zTmp1);
        // gmp_printf ("nm = %.10Zd\n", nm);

        mpz_mul(zTmp1, low, ratio);
        mpz_sub(new, high, zTmp1);
        // gmp_printf ("new = %Zd\n", new);

        mpz_set(high, low);
        mpz_set(hm, lm);
        mpz_set(low, new);
        mpz_set(lm, nm);
        // gmp_printf ("lm: %Zd\n", lm);
        // gmp_printf ("hm: %Zd\n", hm);
        // gmp_printf ("low: %Zd\n", low);
        // gmp_printf ("high: %Zd\n", high);
    }
    mpz_fdiv_r(res, lm, p);
    // gmp_printf ("lm: %Zd\n", lm);
    // gmp_printf ("p: %Zd\n", p);
    // gmp_printf ("res: %Zd\n", res);
    mpz_clear(zTmp1);
    mpz_clear(lm);
    mpz_clear(hm);
    mpz_clear(low);
    mpz_clear(high);
    mpz_clear(ratio);
    mpz_clear(nm);
    mpz_clear(new);
}
