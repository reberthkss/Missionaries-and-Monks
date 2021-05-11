//
// Created by Reberth Kelvin on 10/05/21.
//

#include "DLS.h"
#include <iostream>
#include <list>

list <State> DLS::exec(State * initialState) {
    int limit = 20;
    State * finalState = nullptr;
    list <State> steps;
    this->recursiveDLS(initialState, limit, &finalState, &steps);
    return steps;
}

State * DLS::recursiveDLS(State *targetState, int limit, State ** finalState, list <State> * steps) {
    if (targetState->isFinalState()) {
        return targetState;
    } else if (limit == 0) {
        if (*finalState == nullptr && !steps->empty()) steps->pop_back();
        return nullptr;
    } else {
        list <State> successors = targetState->generateSuccessors();
        for (State state : successors) {
            State * result = this->recursiveDLS(&state, limit - 1, finalState, steps);
            auto * pState = new State(new Cannibal(state.cannibal->onLeft, state.cannibal->onRight), new Missionary(state.missionary->onLeft, state.missionary->onRight), BOAT_SIDE::LEFT);
            if (result != nullptr) {
                if (*finalState == nullptr && result->isFinalState()) {
                    *finalState = new State(new Cannibal(0, 3), new Missionary(0, 3), BOAT_SIDE::LEFT);
                    steps->push_back(**finalState);
                    return *finalState;
                }
                if (* finalState != nullptr) {
                    steps->push_back(state);
                }
                return pState;
            }
        }
            return nullptr;
    }
}