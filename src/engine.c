#include "src/engine.h"
#include "src/io.h"
#include "src/log.h"
#include <stdlib.h>

void initStart(struct State *state) {
    state->a = 0;
}

void initMainMenu(struct State *state) {

}

void initNewMenu(struct State *state) {

}

void initExistingMenu(struct State *state) {

}

void initOptionsMenu(struct State *state) {

}

void initReadString(struct State *state) {

}

void initDead(struct State *state) {

}

void updateStart(struct State *state, struct Event event) {
    state->a++;
    if (state->a > 2) {
        engine_transition(state, Mode_MAIN_MENU);
    }
}

void updateMainMenu(struct State *state, struct Event event) {

}

void updateNewMenu(struct State *state, struct Event event) {

}

void updateExistingMenu(struct State *state, struct Event event) {

}

void updateOptionsMenu(struct State *state, struct Event event) {

}

void updateReadString(struct State *state, struct Event event) {

}

void updateDead(struct State *state, struct Event event) {

}

void renderStart(struct Context *context, struct State *state) {
    struct Colour colour;
    colour.red = rand() % 255;
    colour.green = rand() % 255;
    colour.blue = rand() % 255;
    io_flushGradient(context, io_GREEN, colour);
}

void renderMainMenu(struct Context *context, struct State *state) {
    struct Rect bounds = {30, 10, 10, 10};
    io_flushGradient(context, io_NAVY, io_BLACK);
    io_blitBox(
        context,
        bounds,
        0xcd,
        0xba,
        0xce,
        io_WHITE,
        io_NAVY
    );
    bounds.pos.x += 1;
    bounds.pos.y += 1;
    bounds.size.x -= 2;
    bounds.size.y -= 2;
    io_blitString(context, "Hello my friends.", bounds, io_WHITE);
}

void renderNewMenu(struct Context *context, struct State *state) {

}

void renderExistingMenu(struct Context *context, struct State *state) {

}

void renderOptionsMenu(struct Context *context, struct State *state) {

}

void renderReadString(struct Context *context, struct State *state) {

}

void renderDead(struct Context *context, struct State *state) {

}

struct State *engine_createState() {
    struct State *state = malloc(sizeof(struct State));
    state->world = 0;
    state->sa[0] = 0;
    state->sb[0] = 0;
    engine_transition(state, Mode_START);
    return state;
}

void engine_transition(struct State *state, enum Mode mode) {
    log_info(
        "Entering mode %d. A: %d, B: %d, C: %d, VA: (%d, %d)"
        ", VB: (%d, %d), SA: '%s', SB: '%s'",
        mode,
        state->a,
        state->b,
        state->c,
        state->va.x,
        state->va.y,
        state->vb.x,
        state->vb.y,
        state->sa,
        state->sb
    );
    state->mode = mode;
    switch(mode) {
        case Mode_START:
            initStart(state);
            break;
        case Mode_MAIN_MENU:
            initMainMenu(state);
            break;
        case Mode_NEW_MENU:
            initNewMenu(state);
            break;
        case Mode_EXISTING_MENU:
            initExistingMenu(state);
            break;
        case Mode_OPTIONS_MENU:
            initOptionsMenu(state);
            break;
        case Mode_READ_STRING:
            initReadString(state);
            break;
        case Mode_DEAD:
            initDead(state);
            break;
        default:
            log_error("No such mode as %d", mode);
    }
}

void engine_update(struct State *state, struct Event event) {
    switch (state->mode) {
        case Mode_START:
            updateStart(state, event);
            break;
        case Mode_MAIN_MENU:
            updateMainMenu(state, event);
            break;
        case Mode_NEW_MENU:
            // do stuff.
            break;
        case Mode_EXISTING_MENU:
            // do stuff.
            break;
        case Mode_OPTIONS_MENU:
            // do stuff.
            break;
        case Mode_READ_STRING:
            // do stuff.
            break;
        case Mode_DEAD:
            // do stuff.
            break;
    }
}

void engine_render(struct Context *context, struct State *state) {
    switch (state->mode) {
    case Mode_START:
        renderStart(context, state);
        break;
    case Mode_MAIN_MENU:
        renderMainMenu(context, state);
        break;
    case Mode_NEW_MENU:
        // do stuff.
        break;
    case Mode_EXISTING_MENU:
        // do stuff.
        break;
    case Mode_OPTIONS_MENU:
        // do stuff.
        break;
    case Mode_READ_STRING:
        // do stuff.
        break;
    case Mode_DEAD:
        // do stuff.
        break;
    }
    io_frame(context);
}
