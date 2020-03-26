#ifndef SCRABBLE___DOUBLENODE_H
#define SCRABBLE___DOUBLENODE_H

#include <iostream>

using namespace std;

class DoubleNode
{
private:
    char letter;
    DoubleNode *nextNode;
    DoubleNode *previousNode;

public:
    DoubleNode(char letter);
    ~DoubleNode();

    char getLetter();
    void setLetter(char letter);

    DoubleNode *getNextNode() const;
    void setNextNode(DoubleNode *nextNode);

    DoubleNode *getPreviousNode() const;
    void setPreviousNode(DoubleNode *previousNode);
};

#endif //SCRABBLE___DOUBLENODE_H
