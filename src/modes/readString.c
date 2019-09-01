#include "src/modes.h"
#include "src/io.h"
#include "src/util.h"
#include "src/engine.h"

void modes_initReadString(struct State *state) {
    state->b = 0;
    state->sa[0] = 0;
}

void modes_updateReadString(struct State *state, struct Event event) {
    if (event.value == io_ENTER && state->b > 0) {
        engine_transition(state, state->a);
    } else if (io_keyAlphanumeric(event.value) && state->b < State_S_SIZE - 1) {
        state->sa[state->b] = event.value;
        state->b++;
        state->sa[state->b] = 0;
    } else if (event.value == io_BACKSPACE && state->b > 0) {
        state->b--;
        state->sa[state->b] = 0;
    }
}

void modes_renderReadString(struct Context *con, struct State *state) {
    io_flushGradient(con, io_GREEN, io_BLUE);
    struct Rect bounds = {con->dimensions.x / 4, 10, con->dimensions.x / 2, 8};
    io_blitBox(con, bounds, 0xcd, 0xba, 0xce, io_WHITE, io_NAVY);
    io_blitString(con, state->ca, util_inner(bounds), io_RED);
    bounds.pos.y += 1;
    bounds.size.y -= 1;
    io_blitCharacters(con, state->sa, state->b, util_inner(bounds).pos, io_WHITE);
}
