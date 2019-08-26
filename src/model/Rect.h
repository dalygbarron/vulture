#ifndef RECT_H
#define RECT_H

/**
 * Represents a rectangle made up of a position, which is basically the
 * distance in each dimension between the top left corner and the bottom right
 * corner.
 */
struct Rect {
    struct Vector pos;
    struct Vector size;
};

#endif
