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
 * Returns an input event that must be dealt with, or a no events event if
 * there are none. The idea is that you call this function in a loop and handle
 * all the events until there are none left.
 * @return an event object describing the next event in the queue.
 */
struct Event io_handleInput();

/**
 * Fills the screen with a nice colour.
 * @param context is the context with the screen to render to.
 * @param colour  is the colour to flush it with.
 */
void io_flush(struct Context const *context, struct Colour colour);

/**
 * Fills the screen with a nice gradient that goes from the top of the screen
 * to the bottom.
 * @param context is the rendering context to render with.
 * @param top     is the colour at the top.
 * @param bottom  is the colour at the bottom.
 */
void io_flushGradient(
    struct Context const *context,
    struct Colour top,
    struct Colour bottom
);

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
 * Draws a character on the screen at the given spot.
 * @param context   is the rendering context.
 * @param character is the character to draw.
 * @param pos       is the location on the screen to draw it.
 * @param colour    is the colour to draw it in.
 */
void io_blitCharacter(
    struct Context const *context,
    char character,
    struct Vector pos,
    struct Colour colour
);

/**
 * Draws one icon on the screen at the given spot.
 * @param context is the rendering context.
 * @param icon    is the icon to draw.
 * @param pos     is the location on the screen to draw it.
 * @param fg      is the colour to draw it in.
 * @param bg      is the colour to place behind it 
 */
void io_blitIcon(
    struct Context const *context,
    char icon,
    struct Vector pos,
    struct Colour fg,
    struct Colour bg
);

/**
 * Draws a box on the screen with a nice border.
 * @param context    is the drawing context.
 * @param rect       is the dimensions of the box to draw.
 * @param horizontal is the icon to use for horizontal border segments.
 * @param vertical   is the icon to use for vertical border segments.
 * @param corner     is the icon to use for corner bits.
 * @param fg         is the colour of the border.
 * @param bg         is the colour of the background.
 */
void io_blitBox(
    struct Context const *context,
    struct Rect rect,
    char horizontal,
    char vertical,
    char corner,
    struct Colour fg,
    struct Colour bg
);

/**
 * Draws a box that lets the user select an answer to a question / prompt.
 * @param context  is the rendering context.
 * @param rect     is the rectangle within to draw it all.
 * @param selected is the index of the item which is currently selected.
 * @param ...      strings that have got the potential answers in them.
 */
void io_questionBox(
    struct Context const *context,
    struct Rect rect,
    char const *title,
    int selected,
    ...
);

/**
 * Render the current frame to the screen and such. You have gotta call this
 * after you do some drawing operations.
 * @param context is the context of the screen to make the frame on.
 */
void io_frame(struct Context const *context);

#endif
