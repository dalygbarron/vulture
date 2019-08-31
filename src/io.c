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
struct Colour const io_YELLOW = {255, 255, 0};
struct Colour const io_NAVY = {0, 0, 25};
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

int io_execute(int (*body)(struct Context *)) {
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

void io_flush(struct Context *context, struct Colour colour) {
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
    struct Context *context,
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
    struct Context *context,
    struct Colour colour,
    struct Rect rect
) {
    SDL_Rect box = {rect.pos.x, rect.pos.y, rect.size.x, rect.size.y};
    box.x *= context->src.w;
    box.w *= context->src.w;
    box.y *= context->src.h;
    box.h *= context->src.h;
    SDL_SetRenderDrawColor(
        context->renderer,
        colour.red,
        colour.green,
        colour.blue,
        0xff
    );
    SDL_RenderFillRect(context->renderer, &box);
}

void io_blitCharacter(
    struct Context *context,
    unsigned char c,
    struct Vector pos,
    struct Colour colour
) {
    context->src.x = (c % const_TILE_COUNT) * context->src.w;
    context->src.y = c / const_TILE_COUNT * context->src.h;
    context->dst.x = pos.x * context->src.w;
    context->dst.y = pos.y * context->src.h;
    SDL_SetTextureColorMod(
        context->tileset,
        colour.red,
        colour.green,
        colour.blue
    );
    SDL_RenderCopy(
        context->renderer,
        context->tileset,
        &context->src,
        &context->dst
    );
}

void io_blitCharacters(
    struct Context *context,
    char const *c,
    int length,
    struct Vector pos,
    struct Colour colour
) {
    for (int i = 0; i < length; i++) {
        io_blitCharacter(context, c[i], pos, colour);
        pos.x++;
    }
}

void io_blitIcon(
    struct Context *context,
    unsigned char icon,
    struct Vector pos,
    struct Colour fg,
    struct Colour bg
) {
    // TODO: this. It's just blit character with blitting a colour below.
}

int io_blitString(
    struct Context *context,
    char const *string,
    struct Rect bounds,
    struct Colour colour
) {
    if (bounds.size.x < 1 || bounds.size.y < 1) {
        log_warn("trying to blit string '%s' with empty bounds", string);
        return - 1;
    }
    int length = strlen(string);
    int writer = 0;
    int bottom = bounds.pos.y + bounds.size.y;
    while (writer < length - 1 && bounds.pos.y < bottom) {
        int checker = util_min(writer + bounds.size.x, length);
        int whiteoffset = 1;
        while (!util_whitespace(string[checker]) && string[checker] &&
            checker > writer) {
            checker--;
        }
        if (checker == writer) {
            checker = util_min(writer + bounds.size.x, length);
            whiteoffset = 0;
        }
        io_blitCharacters(
            context,
            string + writer,
            checker - writer,
            bounds.pos,
            colour
        );
        writer = checker + whiteoffset;
        bounds.pos.y++;
    }
    return bounds.pos.y - (bottom - bounds.size.y);
}

void io_blitBox(
    struct Context *context,
    struct Rect box,
    unsigned char horizontal,
    unsigned char vertical,
    unsigned char corner,
    struct Colour fg,
    struct Colour bg
) {
    io_flushRect(context, bg, box);
    struct Vector pos;
    pos.y = box.pos.y;
    for (pos.x = box.pos.x + 1; pos.x < box.pos.x + box.size.x - 1; pos.x++) {
        io_blitCharacter(context, horizontal, pos, fg);
    }
    pos.y = box.pos.y + box.size.y - 1;
    for (pos.x = box.pos.x + 1; pos.x < box.pos.x + box.size.x - 1; pos.x++) {
        io_blitCharacter(context, horizontal, pos, fg);
    }
    pos.x = box.pos.x;
    for (pos.y = box.pos.y + 1; pos.y < box.pos.y + box.size.y - 1; pos.y++) {
        io_blitCharacter(context, vertical, pos, fg);
    }
    pos.x = box.pos.x + box.size.x - 1;
    for (pos.y = box.pos.y + 1; pos.y < box.pos.y + box.size.y - 1; pos.y++) {
        io_blitCharacter(context, vertical, pos, fg);
    }
    pos = box.pos;
    io_blitCharacter(context, corner, pos, fg);
    pos.x += box.size.x - 1;
    io_blitCharacter(context, corner, pos, fg);
    pos.y += box.size.y - 1;
    io_blitCharacter(context, corner, pos, fg);
    pos.x -= box.size.x - 1;
    io_blitCharacter(context, corner, pos, fg);
}

void io_options(
    struct Context *context,
    struct Rect bounds,
    char const **strings,
    int n,
    int selected
) {
    for (int i = 0; i < n; i++) {
        struct Colour colour = (i == selected) ? io_RED : io_WHITE;
        int length = io_blitString(context, strings[i], bounds, colour);
        bounds.pos.y += length;
        bounds.size.y -= length;
    }
}

void io_frame(struct Context *context) {
    SDL_RenderPresent(context->renderer);
}
