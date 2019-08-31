#ifndef UTIL_H
#define UTIL_H

#include "model/Vector.h"
#include "model/Colour.h"
#include "model/Rect.h"

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
