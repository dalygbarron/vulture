#ifndef WORLD_H
#define WORLD_H

#include "src/model/Vector.h"

/**
 * Represents the game world's current state.
 * TODO: All of the maps are meant to fit together in a 3d grid, but there is
 *       no point allocating all of the maps at the same time since they are
 *       only going to be 
 */
struct World {
    struct Map **maps;
    struct Creature *player;
    struct Vector playerMap;
};

#endif
