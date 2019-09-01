#ifndef MODES_H
#define MODES_H

#include "src/model/Mode.h"
#include "src/model/State.h"
#include "src/model/Event.h"
#include "src/model/Context.h"

/**
 * Initialises the start mode.
 * @param state is the state of the program.
 */
void modes_initStart(struct State *state);

/**
 * Initialises the notice mode.
 * @param state is the state of the program.
 */
void modes_initNotice(struct State *state);

/**
 * Initialises the main menu mode.
 * @param state is the state of the program.
 */
void modes_initMainMenu(struct State *state);

/**
 * Initialises the new menu program.
 * @param state is the state of the program.
 */
void modes_initNewMenu(struct State *state);

/**
 * Initialises the existing menu mode.
 * @param state is the state of the program.
 */
void modes_initExistingMenu(struct State *state);

/**
 * Initialises the options menu mode.
 * @param state is the state of the program.
 */
void modes_initOptionsMenu(struct State *state);

/**
 * Initialises the read string mode.
 * @param state is the state of the program.
 */
void modes_initReadString(struct State *state);

/**
 * Initialises the dead mode.
 * @param state is the state of the program.
 */
void modes_initDead(struct State *state);

/**
 * Initialises the show file mode.
 * @param state is the state of the program.
 */
void modes_initShowFile(struct State *state);

/**
 * Updates the start mode.
 * @param state is the state of the program.
 * @param event is the event that is updating the program.
 */
void modes_updateStart(struct State *state, struct Event event);

/**
 * Updates the notice mode.
 * @param state is the state of the program.
 * @param event is the event it is responding to.
 */
void modes_updateNotice(struct State *state, struct Event event);

/**
 * Updates the main menu mode.
 * @param state is the state of the program.
 * @param event is the event it is responding to.
 */
void modes_updateMainMenu(struct State *state, struct Event event);

/**
 * Updates the new menu mode.
 * @param state us the state of the program.
 * @param event is the event that the program is responding to.
 */
void modes_updateNewMenu(struct State *state, struct Event event);
/**
 * Updates the existing menu mode.
 * @param state is the state of the program.
 * @param event is the event that has occurred.
 */
void modes_updateExistingMenu(struct State *state, struct Event event);

/**
 * Updates the options menu mode.
 * @param state is the state of the program.
 * @param event is the event that has occurred.
 */
void modes_updateOptionsMenu(struct State *state, struct Event event);

/**
 * Updates the read string mode.
 * @param state is the the state of the program.
 * @param event is the event that has occurred.
 */
void modes_updateReadString(struct State *state, struct Event event);

/**
 * Updates the dead mode.
 * @param state is the state of the program.
 * @param event is the event that has caused an updatre.
 */
void modes_updateDead(struct State *state, struct Event event);

/**
 * Updates the show file mode.
 * @param state is the state of the program.
 * @param event is the event that has caused an updatre.
 */
void modes_updateShowFile(struct State *state, struct Event event);

/**
 * Renders the start mode.
 * @param context is the rendering context.
 * @param state   is the state of the program.
 */
void modes_renderStart(struct Context *context, struct State *state);

/**
 * Renders the notice  mode.
 * @param context is the rendering context.
 * @param state   is the state of the program.
 */
void modes_renderNotice(struct Context *context, struct State *state);

/**
 * Renders the main menu mode.
 * @param context is the rendering context.
 * @param state   is the state of the program.
 */
void modes_renderMainMenu(struct Context *context, struct State *state);

/**
 * Renders the new menu mode.
 * @param context is the rendering context.
 * @param state   is the state of the program.
 */
void modes_renderNewMenu(struct Context *context, struct State *state);

/**
 * Renders the existing menu mode.
 * @param context is the rendering context.
 * @param state   is the state of the program.
 */
void modes_renderExistingMenu(struct Context *context, struct State *state);

/**
 * Renders the options menu.
 * @param context is the rendering context.
 * @param state   is the state of the program.
 */
void modes_renderOptionsMenu(struct Context *context, struct State *state);

/**
 * Renders the read string mode.
 * @param context is the rendering context.
 * @param state   is the state of the program.
 */
void modes_renderReadString(struct Context *context, struct State *state);

/**
 * Renders the dead mode.
 * @param context is the rendering context.
 * @param state   is the state of the program.
 */
void modes_renderDead(struct Context *context, struct State *state);

/**
 * Renders the show file mode.
 * @param context is the rendering context.
 * @param state   is the state of the program.
 */
void modes_renderShowFile(struct Context *context, struct State *state);

/**
 * Renders the quit mode.
 * @param context is the rendering context.
 * @param state   is the state of the program.
 */
void modes_renderQuit(struct Context *context, struct State *state);

#endif
