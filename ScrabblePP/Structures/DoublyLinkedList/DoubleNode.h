#ifndef SCRABBLE___DOUBLENODE_H
#define SCRABBLE___DOUBLENODE_H

#include "../../Model/Letter.h"

class DoubleNode
{
private:
    Letter *letter;
    DoubleNode *nextNode;
    DoubleNode *previousNode;

public:
    DoubleNode(Letter *letter);
    ~DoubleNode();

    Letter *getLetter() const;

    DoubleNode *getNextNode() const;
    void setNextNode(DoubleNode *nextNode);

    DoubleNode *getPreviousNode() const;
    void setPreviousNode(DoubleNode *previousNode);
};

#endif //SCRABBLE___DOUBLENODE_H
