//
// Created by Reberth Kelvin on 10/05/21.
//

#include "State.h"
#include <array>
list <State> State::generateSuccessors() {
    list <State> successors;
    Cannibal refCannibal = * this->cannibal;
    Missionary refMissionary = * this->missionary;

    if (boatSide == BOAT_SIDE::LEFT) {
        // two cannibals for the right;
        this->testAndAdd(&successors, new State(new Cannibal(refCannibal.onLeft -2 , refCannibal.onRight + 2), new Missionary(refMissionary.onLeft, refMissionary.onRight), BOAT_SIDE::RIGHT));
        // two missionaries for the right;
        this->testAndAdd(&successors, new State(new Cannibal(refCannibal.onLeft , refCannibal.onRight), new Missionary(refMissionary.onLeft - 2, refMissionary.onRight + 2), BOAT_SIDE::RIGHT));
        // one cannibal and missionary for the right;
        this->testAndAdd(&successors, new State(new Cannibal(refCannibal.onLeft -1 , refCannibal.onRight + 1), new Missionary(refMissionary.onLeft - 1, refMissionary.onRight + 1), BOAT_SIDE::RIGHT));
        // one cannibal for the right;
        this->testAndAdd(&successors, new State(new Cannibal(refCannibal.onLeft - 1 , refCannibal.onRight + 1), new Missionary(refMissionary.onLeft, refMissionary.onRight), BOAT_SIDE::RIGHT));
        // one cannibal for the right;
        this->testAndAdd(&successors, new State(new Cannibal(refCannibal.onLeft, refCannibal.onRight), new Missionary(refMissionary.onLeft - 1, refMissionary.onRight + 1), BOAT_SIDE::RIGHT));
    } else {
        // two cannibals for the left;
        this->testAndAdd(&successors, new State(new Cannibal(refCannibal.onLeft + 2 , refCannibal.onRight - 2), new Missionary(refMissionary.onLeft, refMissionary.onRight), BOAT_SIDE::LEFT));
        // two missionaries for the left;
        this->testAndAdd(&successors, new State(new Cannibal(refCannibal.onLeft , refCannibal.onRight), new Missionary(refMissionary.onLeft + 2, refMissionary.onRight - 2), BOAT_SIDE::LEFT));
        // one cannibal and missionary for the left;
        this->testAndAdd(&successors, new State(new Cannibal(refCannibal.onLeft + 1 , refCannibal.onRight - 1), new Missionary(refMissionary.onLeft + 1, refMissionary.onRight - 1), BOAT_SIDE::LEFT));
        // one cannibal for the left;
        this->testAndAdd(&successors, new State(new Cannibal(refCannibal.onLeft + 1 , refCannibal.onRight - 1), new Missionary(refMissionary.onLeft, refMissionary.onRight), BOAT_SIDE::LEFT));
        // one missionary for the left;
        this->testAndAdd(&successors, new State(new Cannibal(refCannibal.onLeft, refCannibal.onRight), new Missionary(refMissionary.onLeft + 1, refMissionary.onRight - 1), BOAT_SIDE::LEFT));
    }
    return successors;
}

void State::testAndAdd(list<State> *successors, State * newState) {
    if (newState->isValidState()) {
        successors->push_back(*newState);
    }
}

bool State::isFinalState() {
    return (this->missionary->onRight == 3 && this->cannibal->onRight == 3);
}

bool State::isValidState() {
    return (this->missionary->isValid() && this->cannibal->isValid()) &&
    (this->missionary->onLeft >= this->cannibal->onLeft || this->missionary->onLeft == 0) &&
    (this->missionary->onRight >= this->cannibal->onRight || this->missionary->onRight == 0);
}
