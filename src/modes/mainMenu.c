#include "src/modes.h"
#include "src/io.h"
#include "src/util.h"

void modes_initMainMenu(struct State *state) {
    state->e = 0;
}

void modes_updateMainMenu(struct State *state, struct Event event) {
    state->e++;
}

void modes_renderMainMenu(struct Context *context, struct State *state) {
    io_flushGradient(context, io_NAVY, io_RED);
    for (int x = 0; x < context->dimensions.x; x++) {
        for (int y = 0; y < context->dimensions.y; y++) {
            char c = ((x + y) % 2) ? 0xc0 : 0xc5;
            io_blitCharacter(context, c, util_v(x, y), io_WHITE);
        }
    }
    struct Rect bounds = {
        context->dimensions.x / 4,
        10,
        context->dimensions.x / 2,
        4
    };
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
    bounds.pos.y += 4;
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
    char const *strings[] = {state->ca, state->cb, state->cc, state->cd};
    io_options(context, util_inner(bounds), strings, state->f, state->e);
}
