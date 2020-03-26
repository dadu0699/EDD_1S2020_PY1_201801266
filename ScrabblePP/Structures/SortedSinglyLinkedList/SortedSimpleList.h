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
    void addFirstNode(int score);
    void addLastNode(int score);
    void readNodes();
};

#endif //SCRABBLE___SORTEDSIMPLELIST_H
