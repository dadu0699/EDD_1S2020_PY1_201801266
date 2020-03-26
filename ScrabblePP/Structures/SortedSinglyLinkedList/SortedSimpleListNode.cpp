#include "SortedSimpleNode.h"

SortedSimpleNode::SortedSimpleNode(string name, int score)
{
    this->score = score;
    nextNode = nullptr;
}

SortedSimpleNode::~SortedSimpleNode()
{
}

string SortedSimpleNode::getName()
{
    return name;
}

void SortedSimpleNode::setName(string name)
{
    this->name = name;
}

int SortedSimpleNode::getScore()
{
    return score;
}

void SortedSimpleNode::setScore(int score)
{
    this->score = score;
}

SortedSimpleNode *SortedSimpleNode::getNextNode() const
{
    return nextNode;
}

void SortedSimpleNode::setNextNode(SortedSimpleNode *nextNode)
{
    this->nextNode = nextNode;
}
