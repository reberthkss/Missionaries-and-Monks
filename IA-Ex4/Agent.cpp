//
// Created by Reberth Kelvin on 10/05/21.
//

#include "Agent.h"

bool Agent::isValid() {
    return this->onLeft >= 0 && this->onRight >= 0;
}