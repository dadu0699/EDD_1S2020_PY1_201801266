#ifndef SCRABBLE___SORTEDSIMPLENODE_H
#define SCRABBLE___SORTEDSIMPLENODE_H

#include <iostream>

using namespace std;

class SortedSimpleNode
{
private:
    string name;
    int score;
    SortedSimpleNode *nextNode;

public:
    SortedSimpleNode(string name, int score);
    ~SortedSimpleNode();

    string getName();
    void setName(string name);

    int getScore();
    void setScore(int score);

    SortedSimpleNode *getNextNode() const;
    void setNextNode(SortedSimpleNode *nextNode);
};

#endif //SCRABBLE___SORTEDSIMPLENODE_H
