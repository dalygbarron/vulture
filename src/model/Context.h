#ifndef CONTEXT_H
#define CONTEXT_H

#include <SDL2/SDL.h>

/**
 * Stores everything that is needed to render the game.
 */
struct Context {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *tileset;
    SDL_Rect src;
    SDL_Rect dst;
};

#endif
