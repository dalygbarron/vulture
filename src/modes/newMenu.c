#include "src/modes.h"
#include "src/engine.h"

void modes_initNewMenu(struct State *state) {
    if (strcmp(state->sa, "tango") == 0) {
        state->ca = "try again without the word tango";
        engine_transition(state, Mode_READ_STRING);
    } else if (state->ca) {
        state->a = Mode_MAIN_MENU;
        state->ca = "You are an idiota haha";
        state->cb = state->sa;
        engine_transition(state, Mode_NOTICE);
    } else {
        state->a = Mode_NEW_MENU;
        state->ca = "New File Name: ";
        engine_transition(state, Mode_READ_STRING);
    }
}

void modes_updateNewMenu(struct State *state, struct Event event) {

}

void modes_renderNewMenu(struct Context *context, struct State *state) {

}
