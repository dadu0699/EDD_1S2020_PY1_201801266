#ifndef SCRABBLE___SORTEDSIMPLELIST_H
#define SCRABBLE___SORTEDSIMPLELIST_H

#include <iostream>
#include "SortedSimpleNode.h"

using namespace std;

class SortedSimpleList
{
private:
    SortedSimpleNode *firstNode;
    SortedSimpleNode *lastNode;

    bool isEmpty();
    void sortList();

public:
    SortedSimpleList();
    ~SortedSimpleList();
    void addFirstNode(string name, int score);
    void addLastNode(string name, int score);
    void readNodes();
    void report();
};

#endif //SCRABBLE___SORTEDSIMPLELIST_H
