#ifndef COLOUR_H
#define COLOUR_H

/**
 * Represents a nice 24 bit colour.
 */
struct Colour {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

struct Colour const Colour_RED = {255, 0, 0};
struct Colour const Colour_GREEN = {0, 255, 0};
struct Colour const Colour_BLUE = {0, 0, 255};
struct Colour const Colour_BLACK = {0, 0, 0};
struct Colour const Colour_WHITE = {255, 255, 255};

#endif
