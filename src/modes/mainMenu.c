#include "src/modes.h"
#include "src/io.h"
#include "src/util.h"
#include "src/engine.h"

char const *options[] = {"Existing Game", "New Game", "Options", "Quit"};

void modes_initMainMenu(struct State *state) {
    state->a = 0;
}

void modes_updateMainMenu(struct State *state, struct Event event) {
    if (event.value == io_ENTER) {
        if (state->a == 0) engine_transition(state, Mode_START);
        else if (state->a == 1) engine_transition(state, Mode_START);
        else if (state->a == 2) engine_transition(state, Mode_START);
        else if (state->a == 3) {
            state->ca = "Mr Bongos";
            state->cb = "tes test test est etstes ttez ts test es ttesz teh";
            state->a = Mode_MAIN_MENU;
            engine_transition(state, Mode_NOTICE);
        }
    } else {
        state->a++;
    }
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
    io_options(context, util_inner(bounds), options, 4, state->a);
}
