#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "io.h"
#include "const.h"
#include "log.h"
#include "model/Context.h"
#include "model/Vector.h"
#include "model/Colour.h"
#include "model/Rect.h"

static struct Context *makeContext(
        char const *title,
        int fullscreen,
        struct Vector dimensions,
        char const *tilesetFile
) {
    struct Context *context = malloc(sizeof(struct Context));
    // Start sdl and stuff.
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        log_error("sdl error: %s\n", SDL_GetError());
        return 0;
    }
    // Load the tilset.
    SDL_Surface* loadedSurface = IMG_Load(tilesetFile);
    if(!loadedSurface) {
        log_error("sdl error: %s\n", SDL_GetError());
        return 0;
    }
    // make window.
    context->window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        dimensions.x * loadedSurface->w / const_TILE_COUNT,
        dimensions.y * loadedSurface->h / const_TILE_COUNT,
        SDL_WINDOW_SHOWN | (fullscreen ? SDL_WINDOW_FULLSCREEN : 0)
    );
    if (!context->window) {
        log_error("sdl error: %s\n", SDL_GetError());
        return 0;
    }
    // make renderer.
    context->renderer = SDL_CreateRenderer(
        context->window,
        -1,
        SDL_RENDERER_ACCELERATED
    );
    if (!context->renderer) {
        log_error("sdl error: %s\n", SDL_GetError());
        return 0;
    }
    // turn on fancy pictures.
    int imgFlags = IMG_INIT_PNG;
    if(!(IMG_Init(imgFlags) & imgFlags)) {
        log_error("sdl error: %s\n", SDL_GetError());
        return 0;
    }
    context->tileset = SDL_CreateTextureFromSurface(
        context->renderer,
        loadedSurface
    );
    if (!context->tileset) {
        log_error("sdl error: %s\n", SDL_GetError());
        return 0;
    }
    SDL_FreeSurface(loadedSurface);
    // Turn off vsync.
    // Set up the tiling rectangles.
    SDL_QueryTexture(context->tileset, 0, 0, &context->src.w, &context->src.h);
    context->src.w /= const_TILE_COUNT;
    context->src.h /= const_TILE_COUNT;
    context->dst.w = context->src.w;
    context->dst.h = context->src.h;
    return context;
}

static void destroyContext(struct Context *context) {
    // TODO: this.
}

int io_execute(int (*body)(struct Context const *)) {
    struct Vector dimensions = {1024, 600};
    struct Context *context = makeContext(
        "title",
        1,
        dimensions,
        "tileset.png"
    );
    io_flush(context, Colour_BLACK);
    io_frame(context);
    int response = body(context);
    // free the context and stuff.
    return response;
}

void io_flush(struct Context const *context, struct Colour colour) {

}

void io_flushRect(
    struct Context const *context,
    struct Colour colour,
    struct Rect rect
) {

}

void io_frame(struct Context const *context) {

}
