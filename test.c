#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>

#include "lib/st-hash.h"

#define INPUTS_COUNT 3
#define SEEDS_COUNT  5

int main() {
  char * inputs[INPUTS_COUNT] = { "Hello, World!", "Portable hashing algorithm.", "Murmur3", };
  uint32_t seeds[SEEDS_COUNT] = { 0, 42, 256, 1024, 2048, };
  size_t expectedHashes[INPUTS_COUNT][SEEDS_COUNT] = { 
#if __SIZEOF_SIZE_T__ == 8
    { 
      0xbd7fa1027c0a51b2, 0x779653b4eee47cb7, 
      0x79d7e14de5b33bd5, 0x345fa1238f40a3b3, 
      0xf700b541d9a92fb6, 
    }, 
    { 
      0x93cd1197c7af1e3a, 0x6b709d07b0c0da69, 
      0x4e91bb4cdf456720, 0xe3eb2c617213c434, 
      0x485ed2fda6d975d7,
    }, 
    { 
      0x51c8cdb6fd057307, 0x1e4c4d05931012f2, 
      0xde4eeb083bda0728, 0x4bc6c0790ec49e23, 
      0x406a92b6da48fd07,
    },
#else
    { 0x7c0a51b2, 0xeee47cb7, 0xe5b33bd5, 0x8f40a3b3, 0xd9a92fb6, }, 
    { 0xf016e107, 0xa45ce3c1, 0x3bde6c5, 0x9c2bf791, 0x95a24cdc, }, 
    { 0xfd057307, 0x931012f2, 0x3bda0728, 0xec49e23, 0xda48fd07, },
#endif
  };

  for (size_t i = 0; i < INPUTS_COUNT; i++) {
    printf("Input: \"%s\"\n", inputs[i]);

    for (size_t j = 0; j < SEEDS_COUNT; j++) {
      size_t expected = expectedHashes[i][j];
      size_t hash;

      sizeTHash((void*) inputs[i], strlen(inputs[i]), seeds[j], &hash);

      printf(
        "Seed: %u\t| Expected: %" PRIxMAX "\t| Hash: %" PRIxMAX "\n", 
        seeds[j], (uintmax_t) expected, (uintmax_t) hash
      );

      fflush(stdout);

      assert(hash == expected);
    }

    printf("\n");
  }

  printf("✅ All tests passed\n");

  return 0;
}
