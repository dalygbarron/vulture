#ifndef GEN_H
#define GEN_H

/**
 * Generates a new map and returns it.
 * @param origin is the point where the originating passageway is.
 * @param height is the height of the new map.
 * @param previous is the map this map is branching off from.
 * @param type     is a string for the type of map to create and should
 *                 generally be inherited from the previous map unless you are
 *                 creating a special map.
 * @return the newly created and allocated map.
 */
struct Map *gen_map(
    struct Vector origin,
    int height,
    struct Map *previous,
    char const *type
);

/**
 * Reallocates the map's tile data so that it is just big enough to fit all of
 * the used tile data in the map.
 * @param map is a pointer to the map to do this to.
 */
void gen_fitMap(struct Map *map);

#endif
