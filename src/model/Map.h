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
    struct Vector position;
    int height;
    unsigned char *tiles;
};

#endif
