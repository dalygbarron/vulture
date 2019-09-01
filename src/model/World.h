#ifndef WORLD_H
#define WORLD_H

#include "src/model/Vector.h"

/**
 * Represents the game world's current state.
 */
struct World {
    char const *name;
    struct Map *maps[30];
    struct Creature *player;
    struct Vector playerMap;
};

#endif
