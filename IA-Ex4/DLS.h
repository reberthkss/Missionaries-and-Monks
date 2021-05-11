//
// Created by Reberth Kelvin on 10/05/21.
//

// Depth-limited-search
#ifndef IA_EX4_STATE_H
#define IA_EX4_STATE_H
 #include "State.h"
#endif



using namespace std;

class DLS {
public:
    // Constructor
    DLS(){}

    // Method
    list <State> exec(State * initialState);
    State * recursiveDLS(State * state, int limit, State ** finalState, list <State> * steps);
};


