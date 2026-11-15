// grader.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

#include "cache.h"
#include "alloc.h"

typedef struct {
    char    key[KEY_MAX_LEN + 1];
    int16_t value;
} KVPair;

int main(void) {
    int Q;
    if (scanf("%d", &Q) != 1) {
        fprintf(stderr, "Failed to read Q\n");
        return 1;
    }

    KVPair *pairs = (KVPair *)malloc((size_t)Q * sizeof(KVPair));
    if (!pairs) {
        fprintf(stderr, "Failed to allocate pairs\n");
        return 1;
    }

    for (int i = 0; i < Q; i++) {
        char buf[KEY_MAX_LEN + 5];
        int v;
        if (scanf("%64s %d", buf, &v) != 2) {
            fprintf(stderr, "Failed to read pair %d\n", i);
            free(pairs);
            return 1;
        }
        buf[KEY_MAX_LEN] = '\0';
        strncpy(pairs[i].key, buf, KEY_MAX_LEN + 1);

        if (v == 0 || v < -32768 || v > 32767) {
            fprintf(stderr, "Invalid value %d at index %d\n", v, i);
            free(pairs);
            return 1;
        }
        pairs[i].value = (int16_t)v;
    }

    // Initialize contestant cache.
    cache_init();

    int64_t misses = 0;

    for (int i = 0; i < Q; i++) {
        const char *key = pairs[i].key;
        int16_t ans = cache_get(key);

        if (ans == 0) {
            // Miss.
            misses++;
            cache_store(key, pairs[i].value);
        } else {
            // Hit; check correctness.
            if (ans != pairs[i].value) {
                fprintf(stderr,
                        "Wrong value for key \"%s\": got %d, expected %d\n",
                        key, (int)ans, (int)pairs[i].value);
                free(pairs);
                return 1;  // or treat as score 0
            }
        }
    }

    free(pairs);

    // Output the number of misses as the "score".
    printf("%" PRId64 "\n", misses);

    return 0;
}
