// demo.c

#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "lib/st-hash.h"

int main (int argc, char ** argv) {
  size_t hash;
  uint32_t seed = 42;

  if (argc != 2) {
    printf("usage: %s <string to hash>\n", argv[0]);
    return -1;
  }

  printf("Input: \"%s\"\n", argv[1]);

  getSizeTHash(argv[1], strlen(argv[1]), seed, &hash);

  printf("Hash: %" PRIxMAX "\n", (uintmax_t) hash);

  return 0;
}