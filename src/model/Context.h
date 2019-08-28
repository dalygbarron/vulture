#ifndef CONTEXT_H
#define CONTEXT_H

#include "src/model/Vector.h"
#include <SDL2/SDL.h>

/**
 * Stores everything that is needed to render the game.
 */
struct Context {
    /** the window we are drawing to */
    SDL_Window *window;

    /** the sdl renderer used on the window */
    SDL_Renderer *renderer;
    
    /** the tileset used to draw the game's graphics */
    SDL_Texture *tileset;

    /** a rectangle used for drawing kept at tile size */
    SDL_Rect src;

    /** another rectangle used for drawing kept at tile size */
    SDL_Rect dst;
    
    /** dimensions of the screen in terms of tiles */
    struct Vector dimensions;

    /** dimensions of the screen in terms of pixels */
    struct Vector size;
};

#endif
