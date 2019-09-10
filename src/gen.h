#ifndef GEN_H
#define GEN_H

/**
 * Generates a new map and returns it.
 * @param conf   is the configuration data used to know what algorithms to use
 *               and stuff.
 * @param origin is the point where the new map starts from.
 * @param source is the point where the originating passageway is.
 * @param type   is a string for the type of map to create. if it is null then
 *               it is inferred from the previous map.
 * @return the newly created and allocated map.
 */
struct Map *gen_map(
    struct Config const *conf,
    struct Vector3 origin,
    struct Vector3 source,
    char const *type
);

/**
 * Reallocates the map's tile data so that it is just big enough to fit all of
 * the used tile data in the map.
 * @param map is a pointer to the map to do this to.
 */
void gen_fitMap(struct Map *map);

#endif
