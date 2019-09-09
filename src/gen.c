#include "src/gen.h"

struct Map *allocateMap(int width, int height) {
    struct Map *map = malloc(sizeof(struct Map));
    map->tiles = malloc(sizeof(unsigned char) * width * height * Layer_N);
}

struct Map *gen_map(
    struct Vector origin,
    int height,
    struct Map *previous,
    char const *type
) {
    struct Map *map = allocateMap();
}
