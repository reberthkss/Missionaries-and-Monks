//
// Created by Reberth Kelvin on 10/05/21.
//

#ifndef IA_EX4_AGENT_H
#define IA_EX4_AGENT_H
#include "Agent.h"
#endif

class Missionary: public Agent {
public:
    Missionary(int onLeft, int onRight): Agent(onLeft, onRight) {
        this->onLeft = onLeft;
        this->onRight = onRight;
    }
};


