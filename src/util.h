#ifndef UTIL_H
#define UTIL_H

#include "model/Vector.h"

/**
 * Adds two vectors together and gives you the result.
 * @param a is the first vector.
 * @param b is the second vector.
 * @return a + b.
 */
struct Vector vAdd(struct Vector a, struct Vector b);

/**
 * Subtracts a vector from another and gives you the result.
 * @param a is the first vector.
 * @param b is the second vector.
 * @return a - b.
 */
struct Vector vSub(struct Vector a, struct Vector b);

/**
 * Multiplies two vectors together and returns the result.
 * @param a is the first vector.
 * @param b is the second vector.
 * @return ab
 */
struct Vector vMult(struct Vector a, struct Vector b);

/**
 * Divides one vector by another and returns the result.
 * @param a is the first vector.
 * @param b is the second vector.
 * @return a / b.
 */
struct Vector vDiv(struct Vector a, struct Vector b);

/**
 * Moduluses one vector by another independently on each dimension.
 * @param a is the first vector.
 * @param b is the second vector.
 * @return a % b.
 */
struct Vector vMod(struct Vector a, struct Vector b);

#endif
