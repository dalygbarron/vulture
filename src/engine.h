#ifndef ENGINE_H
#define ENGINE_H

#include "src/model/Mode.h"
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

#endif
