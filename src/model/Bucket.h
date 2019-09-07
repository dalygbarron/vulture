#ifndef BUCKET_H
#define BUCKET_H

/**
 * An single item in a dictionary list of matching keys by hash.
 */
struct Bucket {
    struct Bucket *next;
    char const *key;
    void *value;
};

#endif
