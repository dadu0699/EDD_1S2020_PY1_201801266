#ifndef SCRABBLE___SIMPLENODE_H
#define SCRABBLE___SIMPLENODE_H

class SimpleNode
{
private:
    int score;
    SimpleNode *nextNode;

public:
    SimpleNode(int score);
    ~SimpleNode();

    int getScore();
    void setScore(int score);

    SimpleNode *getNextNode() const;
    void setNextNode(SimpleNode *nextNode);
};

#endif //SCRABBLE___SIMPLENODE_H
