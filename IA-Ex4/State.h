#include <iostream>
#include <list>

#ifndef IA_EX4_CANNIBAL_H
#define IA_EX4_CANNIBAL_H
#include "Cannibal.h"
#endif

#ifndef IA_EX4_MISSIONARY_H
#define IA_EX4_MISSIONARY_H_H
#include "Missionary.h"
#endif

#ifndef IA_EX4_HELPERS_H
#define IA_EX4_HELPERS_H
#include "Helpers.h"
#endif

using namespace std;
class State {
public:
    // Constructor
    State(Cannibal * cannibal, Missionary * missionary, BOAT_SIDE boatSide) {
        this->cannibal = cannibal;
        this->missionary = missionary;
        this->boatSide = boatSide;
    }

    // Values
    Cannibal* cannibal = nullptr;
    Missionary* missionary = nullptr;
    BOAT_SIDE boatSide;

    // Functions
    list<State> generateSuccessors();
    bool isFinalState(), isValidState(), isEqual(State * targetState);
    void testAndAdd(list <State> * successors, State * newState);
};