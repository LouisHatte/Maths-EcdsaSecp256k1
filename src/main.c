#include "modinv.h"
#include "secp256k1.h"
#include "ECdouble.h"
#include "ECadd.h"
#include "ECmultiply.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void    printPubKey(point_s pubKey) {
    char *x = malloc(sizeof(char) * (mpz_sizeinbase(pubKey.x, 16) + 2));
    char *y = malloc(sizeof(char) * (mpz_sizeinbase(pubKey.y, 16) + 2));
    mpz_get_str(x, 16, pubKey.x);
    mpz_get_str(y, 16, pubKey.y);

    int pubKeyLen = strlen(x) + strlen(y);

    printf("Your public key is:\n0x");
    for (int i = 128 - pubKeyLen; i > 0; i--) {
        printf("0");
    }
    gmp_printf("%Zx%Zx\n", pubKey.x, pubKey.y);

    free(x);
    free(y);
}

bool    isPrivKey(char *privKey) {
    if (strlen(privKey) != 64) {
        fprintf(stderr, "Invalid length of private key, expected 32 bytes length without '0x' prefix\n");
        return false;
    }

    for (int i = 0; i < strlen(privKey); i++) {
        if (isxdigit(privKey[i]) == 0) {
            fprintf(stderr, "Invalid private key\n");
            return false;
        }
    }

    return true;
}

int main(int ac, char **av) {
    secp256k1_s secp256k1;
    mpz_t privKey;
    point_s pubKey;

    if (ac != 2) {
        fprintf(stderr, "Please use: %s yourPrivateKey\n", av[0]);
        return 1;
    }

    if (isPrivKey(av[1]) == false) {
        return 1;
    }

    init_secp256k1(&secp256k1);
    mpz_init_set_str(privKey, av[1], 16);

    pubKey = elliptic_curve_multiply(secp256k1, privKey);

    printPubKey(pubKey);

    clear_secp256k1(secp256k1);
    mpz_clear(privKey);
    mpz_clear(pubKey.x);
    mpz_clear(pubKey.y);

    return 0;
}
