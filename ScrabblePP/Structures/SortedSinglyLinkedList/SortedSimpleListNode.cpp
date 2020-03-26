#include "SortedSimpleNode.h"

SortedSimpleNode::SortedSimpleNode(int score)
{
    this->score = score;
    nextNode = nullptr;
}

SortedSimpleNode::~SortedSimpleNode()
{
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
