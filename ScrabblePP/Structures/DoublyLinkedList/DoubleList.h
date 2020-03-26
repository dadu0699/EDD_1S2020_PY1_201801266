#ifndef SCRABBLE___DOUBLELIST_H
#define SCRABBLE___DOUBLELIST_H

#include <iostream>
#include "DoubleNode.h"

using namespace std;

class DoubleList
{
private:
    DoubleNode *firstNode;
    DoubleNode *lastNode;

    bool isEmpty();

public:
    DoubleList();
    ~DoubleList();
    void addFirstNode(char letter);
    void addLastNode(char letter);
    void readStartNodes();
    void readEndNodes();
    void updateNode(char oldLetter, char newLetter);
    void deleteFirstNode();
    void deleteLastNode();
    void deleteSpecificNode(char letter);
    DoubleNode *searchNode(char letter);
};

#endif //SCRABBLE___DOUBLELIST_H
