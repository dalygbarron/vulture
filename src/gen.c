#include "src/gen.h"

#define PROTO_MAP_WIDTH 200
#define PROTO_MAP_HEIGHT 200

struct Map *gen_map(
    struct Vector3 origin,
    int height,
    struct Map *previous,
    char const *type
) {
    char tiles[PROTO_MAP_WIDTH * PROTO_MAP_HEIGHT * Layer_N];
    struct Map map;
    map->tiles = tiles;
}
