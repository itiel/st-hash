// st-hash.h

#ifndef _ST_HASH_H_
#define _ST_HASH_H_ 

#include <stdint.h>
#include <stddef.h>

void sizeTHash (void * key, size_t keyLen, uint32_t seed, size_t * hash);

#endif /* _ST_HASH_H_ */