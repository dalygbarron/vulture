#include "src/modes.h"
#include "src/io.h"
#include "src/util.h"

char const *mainMenuOptions[] = {
    "Existing Game",
    "New Game",
    "Options",
    "Quit"
};

void modes_initMainMenu(struct State *state) {
    state->a = 0;
}

void modes_updateMainMenu(struct State *state, struct Event event) {
    state->a++;
}

void modes_renderMainMenu(struct Context *context, struct State *state) {
    io_flushGradient(context, io_NAVY, io_BLACK);
    struct Rect bounds = {30, 10, 30, 3};
    io_blitBox(
        context,
        bounds,
        0xcd,
        0xba,
        0xce,
        io_WHITE,
        io_NAVY
    );
    io_blitString(context, "Conan RL", util_inner(bounds), io_RED);
    bounds.pos.y += 3;
    bounds.size.y += 5;
    io_blitBox(
        context,
        bounds,
        0xcd,
        0xba,
        0xce,
        io_WHITE,
        io_NAVY
    );
    io_options(context, util_inner(bounds), mainMenuOptions, 4, state->a);
}
