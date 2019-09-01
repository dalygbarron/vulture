#include "src/modes.h"
#include "src/io.h"
#include "src/util.h"
#include "src/model/Rect.h"

void modes_renderQuit(struct Context *context, struct State *state) {
    io_flush(context, io_BLACK);
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
    io_blitString(
        context,
        "Goodbye. press any key.",
        util_inner(bounds),
        io_RED
    );

}
