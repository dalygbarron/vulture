#include "src/modes.h"
#include "src/io.h"
#include "src/engine.h"
#include "src/util.h"

void modes_initStart(struct State *state) {
    state->a = 0;
}

void modes_updateStart(struct State *state, struct Event event) {
    state->a++;
    if (state->a > 2) {
        engine_transition(state, Mode_MAIN_MENU);
    }
}

void modes_renderStart(struct Context *context, struct State *state) {
    struct Colour colour;
    colour.red = rand() % 255;
    colour.green = rand() % 255;
    colour.blue = rand() % 255;
    io_flushGradient(context, io_GREEN, colour);
}
