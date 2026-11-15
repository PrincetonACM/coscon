// Very simple starter cache for the special case where each key is exactly
// 1 character. The key's byte value (0..255) is used as the index.
//
// This is NOT a full solution for the real problem, but it gives you:
//   - a tiny example of using cmalloc
//   - how to return hits/misses

#include <stdint.h>
#include <string.h>

#include "cache.h"
#include "alloc.h"

static int16_t *table = NULL;  // table[256]
static int ready = 0;

void cache_init(void) {
    // Allocate a 256-element table for values.
    // Each entry is an int16_t, so this uses only 512 bytes.
    table = (int16_t *)cmalloc(256 * sizeof(int16_t));

    if (!table) {
        // Allocation failed — no caching will be done.
        ready = 0;
        return;
    }

    // Mark all entries as "not in cache yet".
    for (int i = 0; i < 256; i++) {
        table[i] = 0;
    }

    ready = 1;
}

int16_t cache_get(const char *key) {
    if (!ready)
        return 0;   // no table, always miss

    // This simple starter only handles 1-character keys.
    // Anything longer is treated as a miss.
    if (!key || key[0] == '\0' || key[1] != '\0')
        return 0;

    unsigned char c = (unsigned char)key[0];  // 0..255

    // table[c] == 0 -> miss
    // table[c] != 0 -> hit
    return table[c];
}

void cache_store(const char *key, int16_t value) {
    if (!ready)
        return;

    // Again, only handle 1-character keys in this starter.
    if (!key || key[0] == '\0' || key[1] != '\0')
        return;

    unsigned char c = (unsigned char)key[0];

    // Store the value; grader guarantees value != 0.
    table[c] = value;
}
