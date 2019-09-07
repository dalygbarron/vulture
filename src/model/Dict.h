#ifndef DICT_H
#define DICT_H

/**
 * Associates strings to pointers to stuff.
 */
struct Dict {
    struct Bucket *buckets;
    int n;
    int size;
};

#endif
