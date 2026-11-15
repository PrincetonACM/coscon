// alloc.c
#include "alloc.h"
#include <stdlib.h>
#include <stdint.h>

#define HEAP_LIMIT (16 * 1024)  // 16 KiB

static size_t used = 0;

/*
 * Layout in underlying malloc:
 *   [ size_t stored_size ][ user bytes ... ]
 * cmalloc returns pointer to the user bytes.
 */
void *cmalloc(size_t size) {
    if (size == 0) {
        return NULL;
    }

    if (used + size > HEAP_LIMIT) {
        return NULL;  // would exceed logical heap budget
    }

    size_t total = size + sizeof(size_t);
    size_t *raw = (size_t *)malloc(total);
    if (!raw) {
        return NULL;  // real OOM
    }

    *raw = size;     // store user-requested size
    used += size;

    return (void *)(raw + 1);
}

void cfree(void *ptr) {
    if (!ptr) return;

    size_t *raw = ((size_t *)ptr) - 1;
    size_t size = *raw;

    if (used >= size) {
        used -= size;
    } else {
        used = 0;  // shouldn't happen, but be safe
    }

    free(raw);
}

size_t cheap_used(void) {
    return used;
}

size_t cheap_limit(void) {
    return HEAP_LIMIT;
}
