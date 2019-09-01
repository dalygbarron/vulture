#include "src/engine.h"
#include "src/io.h"
#include "src/log.h"
#include "src/util.h"
#include "src/modes.h"
#include "src/model/Mode.h"
#include <stdlib.h>

struct State *engine_createState() {
    struct State *state = malloc(sizeof(struct State));
    state->world = 0;
    state->sa[0] = 0;
    state->sb[0] = 0;
    state->ca = 0;
    state->cb = 0;
    state->cc = 0;
    state->cd = 0;
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
            modes_initStart(state);
            break;
        case Mode_NOTICE:
            modes_initNotice(state);
            break;
        case Mode_MAIN_MENU:
            modes_initMainMenu(state);
            break;
        case Mode_NEW_MENU:
            modes_initNewMenu(state);
            break;
        case Mode_EXISTING_MENU:
            modes_initExistingMenu(state);
            break;
        case Mode_OPTIONS_MENU:
            modes_initOptionsMenu(state);
            break;
        case Mode_READ_STRING:
            modes_initReadString(state);
            break;
        case Mode_DEAD:
            modes_initDead(state);
            break;
        case Mode_QUIT:
            break;
        default:
            log_error("No such mode as %d", mode);
    }
}

int engine_update(struct State *state, struct Event event) {
    switch (state->mode) {
        case Mode_START:
            modes_updateStart(state, event);
            break;
        case Mode_NOTICE:
            modes_updateNotice(state, event);
            break;
        case Mode_MAIN_MENU:
            modes_updateMainMenu(state, event);
            break;
        case Mode_NEW_MENU:
            modes_updateNewMenu(state, event);
            break;
        case Mode_EXISTING_MENU:
            modes_updateExistingMenu(state, event);
            break;
        case Mode_OPTIONS_MENU:
            modes_updateOptionsMenu(state, event);
            break;
        case Mode_READ_STRING:
            modes_updateReadString(state, event);
            break;
        case Mode_DEAD:
            modes_updateDead(state, event);
            break;
        case Mode_QUIT:
            return 0;
    }
    return -1;
}

void engine_render(struct Context *context, struct State *state) {
    switch (state->mode) {
    case Mode_START:
        modes_renderStart(context, state);
        break;
    case Mode_NOTICE:
        modes_renderNotice(context, state);
        break;
    case Mode_MAIN_MENU:
        modes_renderMainMenu(context, state);
        break;
    case Mode_NEW_MENU:
        modes_renderNewMenu(context, state);
        break;
    case Mode_EXISTING_MENU:
        modes_renderExistingMenu(context, state);
        break;
    case Mode_OPTIONS_MENU:
        modes_renderOptionsMenu(context, state);
        break;
    case Mode_READ_STRING:
        modes_renderReadString(context, state);
        break;
    case Mode_DEAD:
        modes_renderDead(context, state);
        break;
    case Mode_QUIT:
        modes_renderQuit(context, state);
        break;
    }
    io_frame(context);
}

int engine_choice(struct State *state, int index) {
    switch(index) {
        case 0: return state->a;
        case 1: return state->b;
        case 2: return state->c;
        case 3: return state->d;
        case 4: return state->e;
        case 5: return state->f;
        default:
            log_error("%d is not a valid register index", index);
            return -1;
    }
}
