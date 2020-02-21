#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "secp256k1.h"
#include "ECdouble.h"
#include "ECadd.h"

point_s elliptic_curve_multiply(secp256k1_s secp256k1, mpz_t privKey) {
    point_s pubKey;
    mpz_init_set_si(pubKey.x, 0);
    mpz_init_set_si(pubKey.y, 0);

    int cmp = mpz_cmp(privKey, secp256k1.n);

    if (cmp >= 0) {
        char *privKeyHex = malloc(sizeof(char) * (mpz_sizeinbase(privKey, 16) + 2));
        mpz_get_str(privKeyHex, 16, privKey);
        fprintf(stderr, "Invalid private key: %s\n", privKeyHex);
        return pubKey;
    }

    char *privKeyBin = malloc(sizeof(char) * (mpz_sizeinbase(privKey, 2) + 2));
    mpz_get_str(privKeyBin, 2, privKey);

    mpz_set(pubKey.x, secp256k1.g.x);
    mpz_set(pubKey.y, secp256k1.g.y);
    for (int i = 1; i < strlen(privKeyBin); i++) {
        pubKey = elliptic_curve_point_double(pubKey, secp256k1);
        if (privKeyBin[i] == '1') {
            pubKey = elliptic_curve_point_add(pubKey, secp256k1.g, secp256k1);
        }
    }

    free(privKeyBin);
    return pubKey;
}
