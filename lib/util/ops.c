#include "util/ops.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

void util_ops_bswap(uint8_t* data, size_t size) {
    for (size_t i = 0; i < size / 2; i++) {
        data[i] ^= data[size - i - 1];
        data[size - i - 1] ^= data[i];
        data[i] ^= data[size - i - 1];
    }
}

extern inline bool util_ops_ispowertwo(unsigned x);

int util_ops_min(int a, int b) {
    return a > b ? b : a;
}


int util_ops_max(int a, int b) {
    return a > b ? a : b;
}