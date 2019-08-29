#ifndef STATE_H
#define STATE_H

#include "src/model/Mode.h"
#include "src/model/World.h"
#include "src/model/Vector.h"

#define State_S_SIZE 256

/**
 * Represents the game program's current state.
 */
struct State {
    enum Mode mode;
    struct World *world;
    int a;
    int b;
    int c;
    struct Vector va;
    struct Vector vb;
    char sa[State_S_SIZE];
    char sb[State_S_SIZE];
};

#endif
