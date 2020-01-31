# pragma once

#include "secp256k1.h"

point_s elliptic_curve_point_add(point_s p, point_s q, secp256k1_s secp256k1);