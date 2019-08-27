#ifndef MAP_H
#define MAP_H

#define Map_WIDTH 64
#define Map_HEIGHT 64

/**
 * Represents a single area of play for the game. Can either be in active mode
 * in which all of it's data is in the tiles array, or it can be in dormant
 * mode in which it's data is saved to a file.
 */
struct Map {
    enum {
        Map_DORMANT,
        Map_ACTIVE
    } status;
    char const *filename;
    struct Tile *tiles;
};

#endif
