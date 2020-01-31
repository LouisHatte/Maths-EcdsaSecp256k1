#pragma once

#include <gmp.h>

#include "secp256k1.h"

void    modinv(mpz_t value, mpz_t p, mpz_t res);
