#include "io.h"
#include "log.h"
#include "engine.h"
#include "model/Event.h"
#include "model/State.h"
#include "model/Context.h"
#include <stdio.h>

int body(struct Context const *context) {
    struct State *state = engine_createState();
    engine_render(context, state);
    while (1) {
        struct Event event = io_handleInput();
        if (event.type == Event_QUIT) {
            break;
        } else if (event.type != Event_NOTHING) {
            engine_update(state, event);
            engine_render(context, state);
        }
    }
    return 69;
}

int main(int argc, char const **argv) {
    log_info("Commencing");
    int response = io_execute(body);
    log_info("Exiting with response %d", response);
    return 0;
}
