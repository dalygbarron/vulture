#include "io.h"
#include "log.h"
#include "model/Event.h"
#include <stdio.h>

int body(struct Context const *context) {
    struct Colour bottom = io_GREEN;
    while (1) {
        while (1) {
            struct Event event = io_handleInput();
            if (event.type == Event_NOTHING) {
                break;
            } else if (event.type == Event_QUIT) {
                return 69;
            }
        }
        io_flushGradient(context, bottom, io_BLUE);
        bottom.red++;
        io_frame(context);
    }
    return 69;
}

int main(int argc, char const **argv) {
    log_info("Commencing");
    int response = io_execute(body);
    log_info("Exiting with response %d", response);
    return 0;
}
