// contestant.c
#include <stdint.h>
#include <string.h>

#include "cache.h"
#include "alloc.h"

// You may define your oawn structs and globals here.
// All dynamic memory must be allocated with cmalloc/cfree.
// Do NOT use malloc/calloc/realloc/free directly.

// Example: you might later declare:
// typedef struct { ... } Cache;
// static Cache *cache;

void cache_init(void) {
    // TODO: initialize your cache here using cmalloc, if needed.
    // Example:
    // cache = cmalloc(sizeof(Cache));
    // if (!cache) { /* handle allocation failure */ }
}

int16_t cache_get(const char *key) {
    // TODO: look up `key` in your cache and return:
    //  - the stored value (nonzero) on hit
    //  - 0 on miss
    //
    // NOTE: key is a null-terminated string of length <= KEY_MAX_LEN.
    // You must treat 0 as "miss" only; actual values are never 0.

    (void)key;  // suppress unused parameter warning in starter code

    // Baseline: always miss.
    return 0;
}

void cache_store(const char *key, int16_t value) {
    // TODO: store the (key, value) pair in your cache.
    // This is called only when cache_get(key) has just returned 0.
    // You may assume `value` is never 0.
    //
    // The memory limit (16 KiB) applies to the sum of all cmalloc'd blocks.

    (void)key;
    (void)value;
    // Baseline: do nothing.
}
