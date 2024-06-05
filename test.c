#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "lib/st-hash.h"

void run_test (const char * input, uint32_t seed) {
    size_t hash;
    sizeTHash((void*)input, strlen(input), seed, &hash);
    printf("Input: \"%s\" | Seed: %u | Hash: %" PRIxMAX "\n", input, seed, (uintmax_t) hash);
}

int main() {
    char * inputs[] = { "Hello, World!", "Portable hashing algorithm.", "Murmur3", };
    uint32_t seeds[] = { 42, 0, 256, 1024, 2048, };

    size_t num_inputs = sizeof(inputs) / sizeof(inputs[0]);
    size_t num_seeds = sizeof(seeds) / sizeof(seeds[0]);

    for (size_t i = 0; i < num_inputs; i++) {
        for (size_t j = 0; j < num_seeds; j++) {
            run_test(inputs[i], seeds[j]);
        }
    }

    return 0;
}
