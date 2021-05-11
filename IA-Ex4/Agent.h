//
// Created by Reberth Kelvin on 10/05/21.
//

#ifndef IA_EX4_AGENT_H
#define IA_EX4_AGENT_H
#endif //IA_EX4_AGENT_H


class Agent {
public:
    // Constructor
    Agent(int onLeft, int onRight) {
        this->onLeft = onLeft;
        this->onRight = onRight;
    }
//protected:

    // Values
     int onLeft, onRight;
     // Methods
     bool isValid();
};


