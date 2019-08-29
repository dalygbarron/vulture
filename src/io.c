#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "io.h"
#include "const.h"
#include "log.h"
#include "util.h"
#include "model/Context.h"
#include "model/Vector.h"
#include "model/Colour.h"
#include "model/Rect.h"
#include "model/Event.h"

struct Colour const io_RED = {255, 0, 0};
struct Colour const io_GREEN = {0, 255, 0};
struct Colour const io_BLUE = {0, 0, 255};
struct Colour const io_BLACK = {0, 0, 0};
struct Colour const io_WHITE = {255, 255, 255};

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
    struct Vector size = {
        dimensions.x * loadedSurface->w / const_TILE_COUNT,
        dimensions.y * loadedSurface->h / const_TILE_COUNT,
    };
    context->window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        size.x,
        size.y,
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
    context->dimensions = dimensions;
    context->size = size;
    return context;
}

static void destroyContext(struct Context *context) {
    // TODO: this.
}

int io_execute(int (*body)(struct Context const *)) {
    struct Vector dimensions = {80, 50};
    struct Context *context = makeContext(
        "title",
        0,
        dimensions,
        "tileset.png"
    );
    int response = body(context);
    // free the context and stuff.
    return response;
}

struct Event io_handleInput() {
    SDL_Event e;
    struct Event event;
    while (1) {
        if (SDL_PollEvent(&e) == 0) {
            event.type = Event_NOTHING;
            break;
        } else if (e.type == SDL_QUIT) {
            event.type = Event_QUIT;
            break;
        } else if (e.type == SDL_KEYDOWN) {
            event.type = Event_KEY;
            event.value = e.key.keysym.sym;
            break;
        }
    }
    return event;
}

void io_flush(struct Context const *context, struct Colour colour) {
    SDL_SetRenderDrawColor(
        context->renderer,
        colour.red,
        colour.green,
        colour.blue,
        0xff
    );
    SDL_RenderClear(context->renderer);
}

void io_flushGradient(
    struct Context const *context,
    struct Colour top,
    struct Colour bottom
) {
    SDL_Rect line = context->dst;
    line.x = 0;
    line.y = 0;
    line.w = context->size.x;
    struct Colour increment = util_cFDiv(
        util_cSub(bottom, top),
        context->dimensions.y
    );
    for (int i = 0; i < context->dimensions.y; i++) {
        SDL_SetRenderDrawColor(
            context->renderer,
            top.red,
            top.green,
            top.blue,
            0xff
        );
        SDL_RenderFillRect(context->renderer, &line);
        line.y += line.h;
        top = util_cAdd(top, increment);
    }
}

void io_flushRect(
    struct Context const *context,
    struct Colour colour,
    struct Rect rect
) {
}

void io_blitCharacter(
    struct Context const *context,
    char character,
    struct Vector pos,
    struct Colour colour
) {

}

void io_blitIcon(
    struct Context const *context,
    char icon,
    struct Vector pos,
    struct Colour fg,
    struct Colour bg
) {

}

void io_blitBox(
    struct Context const *context,
    struct Rect rect,
    char horizontal,
    char vertical,
    char corner,
    struct Colour fg,
    struct Colour bg
) {
    io_flushRect(context, bg, rect);
    struct Vector pos;
    pos.y = rect.pos.y;
    for (pos.x = rect.pos.x + 1; pos.x < rect.pos.x + rect.size.x; pos.x++) {
        io_blitIcon(context, horizontal, pos, fg);
    }
    pos.y = rect.pos.y + rect.size.y;
    for (pos.x = rect.pos.x + 1; pos.x < rect.pos.x + rect.size.x; pos.x++) {
        io_blitIcon(context, horizontal, pos, fg);
    }
    pos.x = rect.pos.x;
    for (pos.y = rect.pos.y + 1; pos.y < rect.pos.y + rect.size.y; pos.y++) {
        io_blitIcon(context, vertical, pos, fg);
    }
    pos.x = rect.pos.x + rect.size.x;
    for (pos.y = rect.pos.y + 1; pos.y < rect.pos.y + rect.size.y; pos.y++) {
        io_blitIcon(context, vertical, pos, fg);
    }
}

void io_questionBox(
    struct Context const *context,
    struct Rect rect,
    char const *title,
    int selected,
    ...
) {
    io_flushRect(context, FUCK, rect);
    io_blitLine(context, title, rect.pos);

}

void io_frame(struct Context const *context) {
    SDL_RenderPresent(context->renderer);
}
