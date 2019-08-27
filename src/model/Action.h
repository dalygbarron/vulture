#ifndef ACTION_H
#define ACTION_H

/**
 * Represents an action that can be taken by a creature in the game world.
 */
struct Action {
    enum {
        Action_DROP,
        Action_EQUIP,
        Action_USE,
        Action_WALK
    } type;
    int value;
    int target;
};

#endif
