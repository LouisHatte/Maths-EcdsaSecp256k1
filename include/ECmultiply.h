#pragma once

#include "secp256k1.h"

point_s elliptic_curve_multiply(secp256k1_s secp256k1, mpz_t privKey);
