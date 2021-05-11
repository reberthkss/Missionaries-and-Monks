# Missionaries and Cannibals Problem

Solutions for the [Missionaries and Cannibals Problem](https://en.wikipedia.org/wiki/Missionaries_and_cannibals_problem).


> In this problem, three missionaries and three cannibals must cross a river using a boat which can carry at most two people, under the constraint that, for both banks, if there are missionaries present on the bank, they cannot be outnumbered by cannibals (if they were, the cannibals would eat the missionaries). The boat cannot cross the river by itself with no people on board. And, in some variations, one of the cannibals has only one arm and cannot row. [source: Wikipedia]

## Solutions

The problem was solved using three different languages: Java, Python and Prolog:

### CPP

A `State` class saves the current state of the problem, that is, how many missionaries and cannibals are in each side of the river and where is the boat (left or right).

The `generateSuccessors` method checks the actions (e.g. cross a two missionaries from left to right) that can be applied to a particular state and returns the valid successor states.

The initial state of the problem is passed as input to the Depth Limited search algorithm (class `DLS`) that returns the solution to the problem.

You can use the project and open in a Intellij IDE.
