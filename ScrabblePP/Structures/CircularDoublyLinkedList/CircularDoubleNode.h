#ifndef SCRABBLE___CIRCULARDOUBLENODE_H
#define SCRABBLE___CIRCULARDOUBLENODE_H

#include <iostream>

using namespace std;

class CircularDoubleNode
{
private:
    string word;
    CircularDoubleNode *nextNode;
    CircularDoubleNode *previousNode;

public:
    CircularDoubleNode(string word);
    ~CircularDoubleNode();

    string getWord();
    void setWord(string word);

    CircularDoubleNode *getNextNode() const;
    void setNextNode(CircularDoubleNode *nextNode);

    CircularDoubleNode *getPreviousNode() const;
    void setPreviousNode(CircularDoubleNode *previousNode);
};

#endif //SCRABBLE___CIRCULARDOUBLENODE_H
