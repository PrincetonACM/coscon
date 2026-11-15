// alloc.h
#ifndef ALLOC_H
#define ALLOC_H

#include <stddef.h>

// Allocate `size` bytes from a 16 KiB logical heap.
// Returns NULL if the allocation would exceed the limit or if the
// underlying malloc fails.
void *cmalloc(size_t size);

// Free a block previously allocated by cmalloc.
void cfree(void *ptr);

// Optional helpers (you can ignore these in contestant code).
size_t cheap_used(void);
size_t cheap_limit(void);

#endif
