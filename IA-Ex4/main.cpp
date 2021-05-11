#include <iostream>
#include <list>
#include "Main.h"

using namespace std;

int main() {
    cout << "initializing the algorithm... " << endl;
    DLS depthLimitedSearch;
    auto pCannibals = new Cannibal(3, 0);
    auto pMissionaries = new Missionary(3, 0);
    auto initialState = new State(pCannibals, pMissionaries, BOAT_SIDE::LEFT);
    list <State> steps = depthLimitedSearch.exec(initialState);
    steps.reverse();
    for (State step : steps) {
        if (step.boatSide == BOAT_SIDE::LEFT) {
            cout << "TO LEFT SIDE" << endl;
            cout << "(Cannibals, Missionaries)" << endl;
            cout << "L" << "(" << step.cannibal->onLeft  << "," << step.missionary->onLeft << ") ";
            cout << "R" << "(" << step.cannibal->onRight << "," << step.missionary->onRight << ")" << endl;
        } else {
            cout << "TO RIGHT SIDE" << endl;
            cout << "(Cannibals, Missionaries)" << endl;
            cout << "L" << "(" << step.cannibal->onLeft  << "," << step.missionary->onLeft << ") ";
            cout << "R" << "(" << step.cannibal->onRight << "," << step.missionary->onRight << ")" << endl;
        }
        cout << "/////////////////////////" << endl;
    }
    return 0;
}
