#ifndef UTIL_H
#define UTIL_H

#include "model/Vector.h"
#include "model/Colour.h"
#include "model/Rect.h"
#include "model/Dict.h"
#include <stddef.h>

/**
 * Tells you if the given character is whitespace or not.
 * @param c is the character to check.
 * @return 1 if it's whitespace, and 0 otherwise.
 */
int util_whitespace(char c);

/**
 * Returns the lesser of two values.
 * @param a is the first value.
 * @param b is the second value.
 * @return a if a < b, otherwise b.
 */
int util_min(int a, int b);

/**
 * Returns the greater of two values.
 * @param a is the first value.
 * @param b is the second value.
 * @return a if a > b, otherwise b.
 */
int util_max(int a, int b);

/**
 * Gives you the rect that fits just inside the given one.
 * @param rect is the rect to transform.
 * @return the smaller rect.
 */
struct Rect util_inner(struct Rect rect);

/**
 * hashes some arbitrary value into a nice int.
 * @param value is a pointer to the value to hash.
 * @param size  is the number of bytes in this value.
 * @return a nice hashed int.
 */
unsigned int util_hash(void const *value, size_t size);

/**
 * Sets up a dictionary with the needed buckets.
 * @param dict is the dictionary.
 * @param size is the number of buckets to give it.
 */
void util_initDict(struct Dict *dict, int size);

/**
 * Deletes all the stuff in the dictionary, but first calls a special deletion
 * function on each element.
 * @param dict    is the dictionary.
 * @param deletor is the function to call on each value before deletion.
 */
void util_freeDict(struct Dict *dict, void (*deletor)(void *));

/**
 * Makes a copy of a struct that is the same with freshly copies keys, but
 * links to the original value objects.
 * @param dict is the dictionary to copy.
 */
struct Dict *util_copyDict(struct Dict *dict);

/**
 * Adds an item to the dictionary.
 * @param dict  is the dictionary to add to.
 * @param key   is the key to add it under. this value is copied so you don't
 *              need to worry about freeDict deleting it from elsewhere.
 * @param value is the value to add to the dictionary.
 */ 
void util_addDict(struct Dict *dict, char const *key, void *value);

/**
 * Finds a value in a dictionary and gives it to you.
 * @param dict is the dictionary to look in.
 * @param key  is the key to look for.
 * @return the found value or a null pointer.
 */
void *util_findDict(struct Dict *dict, char const *key);

/**
 * Tells you if the given dictionary has the given key. Kind of important since
 * it does not handle duplicate keys, so if you added two of the same key it
 * would do a bit of weird stuff, though on the other hand it also would not be
 * the end of the world and it would not cause memory leaks or anything bad
 * like that. Would sort suck though.
 * @param dict is the dictionary to look in.
 * @param key  is the key to look for.
 */
int util_hasDict(struct Dict *dict, char const *key);

/**
 * Removes a key from a dictionary. Does no freeing of memory on the value, so
 * you must manage that yourself, it does free the key though.
 * @param dict is the dictionary to remove from.
 * @param key  is the key to remove.
 */
void util_removeDict(struct Dict *dict, char const *key);

/**
 * Creates a vector.
 * @param x is the x component.
 * @param y is the y component.
 * @return the new vector of (x, y).
 */
struct Vector util_v(int x, int y);

/**
 * Adds two vectors together and gives you the result.
 * @param a is the first vector.
 * @param b is the second vector.
 * @return a + b.
 */
struct Vector util_vAdd(struct Vector a, struct Vector b);

/**
 * Subtracts a vector from another and gives you the result.
 * @param a is the first vector.
 * @param b is the second vector.
 * @return a - b.
 */
struct Vector util_vSub(struct Vector a, struct Vector b);

/**
 * Multiplies two vectors together and returns the result.
 * @param a is the first vector.
 * @param b is the second vector.
 * @return ab.
 */
struct Vector util_vMult(struct Vector a, struct Vector b);

/**
 * Divides one vector by another and returns the result.
 * @param a is the first vector.
 * @param b is the second vector.
 * @return a / b.
 */
struct Vector util_vDiv(struct Vector a, struct Vector b);

/**
 * Moduluses one vector by another independently on each dimension.
 * @param a is the first vector.
 * @param b is the second vector.
 * @return a % b.
 */
struct Vector util_vMod(struct Vector a, struct Vector b);

/**
 * Adds two colours together.
 * @param a is the first colour.
 * @param b is the second colour.
 * @return a + b.
 */
struct Colour util_cAdd(struct Colour a, struct Colour b);

/**
 * Subtracts one colour from one another.
 * @param a is the first colour.
 * @param b is the second colour.
 * @return a - b.
 */
struct Colour util_cSub(struct Colour a, struct Colour b);

/**
 * Multiplies a colour by a fixed value.
 * @param a is the colour.
 * @param b is the value to multiply it by.
 * @return ab
 */
struct Colour util_cFMult(struct Colour a, float b);

/**
 * Divides a colour by a fixed value.
 * @param a is the colour.
 * @param b is the value to divide it by.
 * @return a / b.
 */
struct Colour util_cFDiv(struct Colour a, float b);

#endif
