#include "src/modes.h"
#include "src/io.h"
#include "src/util.h"
#include "src/engine.h"

void modes_initNotice(struct State *state) {
}

void modes_updateNotice(struct State *state, struct Event event) {
    engine_transition(state, state->a);
}

void modes_renderNotice(struct Context *context, struct State *state) {
    io_flushGradient(context, io_GREEN, io_BLUE);
    struct Rect bounds = {
        context->dimensions.x / 4,
        10,
        context->dimensions.x / 2,
        3
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
    io_blitString(context, state->ca, util_inner(bounds), io_RED);
    bounds.pos.y += 3;
    bounds.size.y += 25;
    io_blitBox(
        context,
        bounds,
        0xcd,
        0xba,
        0xce,
        io_WHITE,
        io_NAVY
    );
    io_blitString(context, state->cb, util_inner(bounds), io_WHITE);
}
