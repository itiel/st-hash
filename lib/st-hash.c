// st-hash.c

// Based on https://github.com/PeterScott/murmur3

#include <stdint.h>
#include <stddef.h>

#include "st-hash.h"

#define C1 ((uint32_t) 0x239b961b)
#define C2 ((uint32_t) 0xab0e9789)
#define C3 ((uint32_t) 0x561ccd1b)
#define C4 ((uint32_t) 0x0bcaa747)
#define C5 ((uint32_t) 0x85ebca6b)
#define C6 ((uint32_t) 0xc2b2ae35)

#define ROTL(x, r) \
  ((((uint32_t) (x)) << (r)) | (((uint32_t) (x)) >> (32 - (r))))

#define FMIX(h) \
  ({ \
    uint32_t __h = h; \
    __h ^= __h >> 16; \
    __h *= C5; \
    __h ^= __h >> 13; \
    __h *= C6; \
    __h ^= __h >> 16; \
    __h; \
  })

void sizeTHash (void * key, size_t keyLen, uint32_t seed, size_t * hash) {
  uint8_t * data = (uint8_t *) key;
  size_t nblocks = keyLen / 8;

  uint32_t h1 = seed;
  uint32_t h2 = seed;

  uint32_t * blocks = (uint32_t *) (data + nblocks * 8);

  for (size_t i = 0; i < nblocks; i++) {
    uint32_t k1 = blocks[i * 2 + 0];
    uint32_t k2 = blocks[i * 2 + 1];

    k1 *= C1;
    k1 = ROTL(k1, 15);
    k1 *= C2;
    h1 ^= k1;

    h1 = ROTL(h1, 19);
    h1 += h2;
    h1 = h1 * 5 + C3;

    k2 *= C2;
    k2 = ROTL(k2, 16);
    k2 *= C1;
    h2 ^= k2;

    h2 = ROTL(h2, 17);
    h2 += h1;
    h2 = h2 * 5 + C4;
  }

  uint8_t * tail = (uint8_t *) (data + nblocks * 8);

  uint32_t k1 = 0;
  uint32_t k2 = 0;

  switch (keyLen & 7) {
  case 7: 
    k2 ^= tail[6] << 16;
  case 6: 
    k2 ^= tail[5] << 8;
  case 5: 
    k2 ^= tail[4] << 0;
    k2 *= C2;
    k2 = ROTL(k2, 16);
    k2 *= C1;
    h2 ^= k2;
  case 4: 
    k1 ^= tail[3] << 24;
  case 3: 
    k1 ^= tail[2] << 16;
  case 2: 
    k1 ^= tail[1] << 8;
  case 1: 
    k1 ^= tail[0] << 0;
    k1 *= C1;
    k1 = ROTL(k1, 15);
    k1 *= C2;
    h1 ^= k1;
  }

  h1 ^= (uint32_t) keyLen;
  h2 ^= (uint32_t) keyLen;

  h1 += h2;
  h2 += h1;

  h1 = FMIX(h1);
  h2 = FMIX(h2);

  h1 += h2;
  h2 += h1;

#if __SIZEOF_SIZE_T__ == 8
  *hash = (size_t) ((((size_t) h1) << 32) | ((size_t) h2));
#else
  *hash = (size_t) h2;
#endif
}