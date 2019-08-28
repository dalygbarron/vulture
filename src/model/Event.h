#ifndef EVENT_H
#define EVENT_H

/**
 * Represents an event of user input.
 */
struct Event {
    enum {
        Event_KEY,
        Event_QUIT,
        Event_NOTHING
    } type;
    short value;
};

#endif
