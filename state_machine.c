#include "state_machine.h"

void state_machine_init(StateMachine *sm, void *host, StateFn initial_state) {
    sm->host = host;
    sm->current_state = initial_state;
}

void state_machine_feed(StateMachine *sm, Event e) {
    if (sm && sm->current_state) {
        sm->current_state = sm->current_state(sm->host, &e);
    }
}