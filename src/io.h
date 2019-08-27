#ifndef IO_H
#define IO_H

#include "model/Context.h"
#include "model/Vector.h"
#include "model/Rect.h"
#include "model/Colour.h"
#include <SDL2/SDL.h>

extern struct Colour const io_RED;
extern struct Colour const io_GREEN;
extern struct Colour const io_BLUE;
extern struct Colour const io_BLACK;
extern struct Colour const io_WHITE;

/**
 * Executes the body of the game within the lifespan of the technical
 * context within which the game is running.
 * @param int (*)(Context const *) is a pointer to the game body code to run.
 * @return the value returned by the game body.
 */
int io_execute(int (*body)(struct Context const *));

/**
 * Fills the screen with a nice colour.
 * @param context is the context with the screen to render to.
 * @param colour  is the colour to flush it with.
 */
void io_flush(struct Context const *context, struct Colour colour);

/**
 * Fills a rectangle on the screen with a nice colour.
 * @param context is the context with the screen to render to.
 * @param colour  is the colour to fill it with.
 * @param rect    is the rectangle to fill with colour.
 */
void io_flushRect(
    struct Context const *context,
    struct Colour colour,
    struct Rect rect
);

/**
 * Render the current frame to the screen and such. You have gotta call this
 * after you do some drawing operations.
 * @param context is the context of the screen to make the frame on.
 */
void io_frame(struct Context const *context);

#endif
