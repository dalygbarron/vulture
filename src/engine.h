#ifndef ENGINE_H
#define ENGINE_H

#include "src/model/State.h"
#include "src/model/Context.h"
#include "src/model/Event.h"

/**
 * Creates a new engine state object and starts it up.
 * @return the new state.
 */
struct State *engine_createState();

/**
 * Changes the program state from one mode to another.
 * @param state is the program state to alter.
 * @param mode  is the mode to change it to.
 */
void engine_transition(struct State *state, enum Mode mode);

/**
 * Updates the engine state based on an input event.
 * @param state is the program state.
 * @param event is the input event to update it with.
 */
void engine_update(struct State *state, struct Event event);

/**
 * Displays the current state of the program on the screen.
 * @param context is the rendering context.
 * @param state   is the state of the program.
 */
void engine_render(struct Context *context, struct State *state);

/**
 * Chooses the value from one of the integer registers based on the value in
 * the given index.
 * @param state is the program state to choose in.
 * @param index is the index of the register to choose. If you give an invalid
 *              index then the result will just be -1.
 * @return the value of the register for 0 -> a, 1 -> b, 2 -> c, 3 -> d, 4 ->
 *         e, 5 -> f. and negative 1 for all other inputs.
 */
int engine_choice(struct State *state, int index);

#endif
