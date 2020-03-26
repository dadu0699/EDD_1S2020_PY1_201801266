#ifndef SCRABBLE___SORTEDSIMPLENODE_H
#define SCRABBLE___SORTEDSIMPLENODE_H

class SortedSimpleNode
{
private:
    string name;
    int score;
    SortedSimpleNode *nextNode;

public:
    SortedSimpleNode(int score);
    ~SortedSimpleNode();

    int getScore();
    void setScore(int score);

    SortedSimpleNode *getNextNode() const;
    void setNextNode(SortedSimpleNode *nextNode);
};

#endif //SCRABBLE___SORTEDSIMPLENODE_H
