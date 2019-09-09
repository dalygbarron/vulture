#ifndef MAP_H
#define MAP_H

#include "src/model/Vector.h"

/**
 * Represents a single area of play for the game. 
 */
struct Map {
    int active;
    int accessed;
    int saved;
    struct Vector dimensions;
    struct Vector3 position;
    unsigned char *tiles;
};

#endif
