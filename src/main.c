#include "io.h"
#include "log.h"
#include "engine.h"
#include "model/Event.h"
#include "model/State.h"
#include "model/Context.h"
#include <stdio.h>

int body(struct Context *context) {
    struct State *state = engine_createState();
    engine_render(context, state);
    while (1) {
        struct Event event = io_handleInput();
        if (event.type == Event_QUIT) {
            return 0;
        } else if (event.type != Event_NOTHING) {
            int response = engine_update(state, event);
            if (response >= 0) return response;
            engine_render(context, state);
        }
    }
}

int main(int argc, char const **argv) {
    log_info("Commencing");
    int response = io_execute(body);
    log_info("Exiting with response %d", response);
    return 0;
}
