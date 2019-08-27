#ifndef STATE_H
#define STATE_H

/**
 * Represents the game's current state.
 * TODO: All of the maps are meant to fit together in a 3d grid, but there is
 *       no point allocating all of the maps at the same time since they are
 *       only going to be 
 */
struct State {
    struct Map **maps;
    struct Creature *player;
    int playerMap;
};

#endif
