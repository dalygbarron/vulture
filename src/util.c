#include "src/util.h"
#include "src/model/Dict.h"
#include "src/model/Bucket.h"
#include "src/log.h"
#include <stdlib.h>
#include <string.h>

int util_whitespace(char c) {
    return c == ' ' || c == '\n' || c == '\t';
}

int util_min(int a, int b) {
    return (a < b) ? a : b;
}

int util_max(int a, int b) {
    return (a > b) ? a : b;
}

struct Rect util_inner(struct Rect rect) {
    rect.pos.x++;
    rect.pos.y++;
    rect.size.x -= 2;
    rect.size.y -= 2;
    return rect;
}

unsigned int util_hash(void const *value, size_t size) {
    int total = 0;
    unsigned char *bytes = (unsigned char *)value;
    for (int i = 0; i < size; i++) {
        total ^= total << 5;
        total ^= bytes[i];
    }
    return total;
}

void util_initDict(struct Dict *dict, int size) {
    dict->size = size;
    dict->n = 0;
    dict->buckets = malloc(sizeof(struct Bucket) * size);
    for (int i = 0; i < size; i++) {
        dict->buckets[i].next = 0;
        dict->buckets[i].key = 0;
        dict->buckets[i].value = 0;
    }
}

void util_freeDict(struct Dict *dict, void (*deletor)(void *)) {
    for (int i = 0; i < dict->size; i++) {
        if (deletor) deletor(dict->buckets[i].value);
        struct Bucket *next = dict->buckets[i].next;
        while (next) {
            if (next->value && deletor) deletor(next->value);
            if (next->key) free(next->key);
            struct Bucket *old = next;
            next = next->next;
            free(old);
        }
    }
    free(dict->buckets);
}

void util_addDict(struct Dict *dict, char const *key, void *value) {
    int keyLength = strlen(key);
    int index = util_hash(key, keyLength) % dict->size;
    struct Bucket *bucket = dict->buckets + index;
    if (bucket->key) log_warn("collision on key '%s'", key);
    while (bucket->key && strcmp (bucket->key, key)) {
        bucket = bucket->next;
    }
    if (!bucket->key) {
        char *bucketKey = malloc(keyLength + 1);
        strcpy(bucketKey, key);
        bucket->key = bucketKey;
    }
    bucket->value = value;
}

void *util_findDict(struct Dict *dict, char const *key) {
    int index = util_hash(key, strlen(key)) % dict->size;
    struct Bucket *bucket = dict->buckets + index;
    while (bucket && bucket->key) {
        if (strcmp(bucket->key, key) == 0) return bucket->value;
        bucket = bucket->next;
    }
    log_error("Key '%s' not found in dictionary", key);
    return 0;
}

void util_removeDict(struct Dict *dict, char const *key) {

}

struct Vector util_v(int x, int y) {
    struct Vector vector = {x, y};
    return vector;
}

struct Vector util_vAdd(struct Vector a, struct Vector b) {
    a.x += b.x;
    a.y += b.y;
    return a;
}

struct Vector util_vSub(struct Vector a, struct Vector b) {
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

struct Vector util_vMult(struct Vector a, struct Vector b) {
    a.x *= b.x;
    a.y *= b.y;
    return a;
}

struct Vector util_vDiv(struct Vector a, struct Vector b) {
    a.x /= b.x;
    a.y /= b.y;
    return a;
}

struct Vector util_vMod(struct Vector a, struct Vector b) {
    a.x %= b.x;
    a.y %= b.y;
    return a;
}

struct Colour util_cAdd(struct Colour a, struct Colour b) {
    a.red += b.red;
    a.green += b.green;
    a.blue += b.blue;
    return a;
}

struct Colour util_cSub(struct Colour a, struct Colour b) {
    a.red -= b.red;
    a.green -= b.green;
    a.blue -= b.blue;
    return a;
}

struct Colour util_cMult(struct Colour a, struct Colour b) {
    a.red = (a.red * b.red) / 255;
    a.green = (a.green * b.green) / 255;
    a.blue = (a.blue * b.blue) / 255;
    return a;
}

struct Colour util_cFMult(struct Colour a, float b) {
    a.red = (float)a.red / 255.0 * b * 255;
    a.green = (float)a.green / 255.0 * b * 255;
    a.blue = (float)a.blue / 255.0 * b * 255;
    return a;
}

struct Colour util_cFDiv(struct Colour a, float b) {
    a.red = (float)a.red / 255.0 / b * 255;
    a.green = (float)a.green / 255.0 / b * 255;
    a.blue = (float)a.blue / 255.0 / b * 255;
    return a;
}
