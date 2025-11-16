// cache.h
#ifndef CACHE_H
#define CACHE_H

#include <stdint.h>

#define KEY_MAX_LEN 64

// Called once before any queries.
void cache_init(void);

// Called for each key.
// - key: null-terminated string, length <= KEY_MAX_LEN
// - Return value:
//     * 0      => cache miss (0 is never a valid true value)
//     * nonzero => cache hit, must be the correct value for this key
int16_t cache_get(const char *key);

// Called after cache_get() returned 0 for this key.
// - key: same key as in cache_get()
// - value: the true value associated with key (nonzero)
void cache_store(const char *key, int16_t value);

#endif
