#ifndef SCRABBLE___DOUBLELIST_H
#define SCRABBLE___DOUBLELIST_H

#include "DoubleNode.h"

class DoubleList
{
private:
    DoubleNode *firstNode;
    DoubleNode *lastNode;

    bool isEmpty();

public:
    DoubleList();
    ~DoubleList();
    void addFirstNode(Letter *letter);
    void addLastNode(Letter *letter);
    void deleteFirstNode();
    void deleteLastNode();
    void deleteSpecificNode(char letter);
    DoubleNode *searchNode(char letter);
    void report();
};

#endif //SCRABBLE___DOUBLELIST_H
