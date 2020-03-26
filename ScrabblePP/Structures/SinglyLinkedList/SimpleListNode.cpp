#include "SimpleNode.h"

SimpleNode::SimpleNode(int score)
{
    this->score = score;
    nextNode = nullptr;
}

SimpleNode::~SimpleNode()
{
}

int SimpleNode::getScore()
{
    return score;
}

void SimpleNode::setScore(int score)
{
    this->score = score;
}

SimpleNode *SimpleNode::getNextNode() const
{
    return nextNode;
}

void SimpleNode::setNextNode(SimpleNode *nextNode)
{
    this->nextNode = nextNode;
}
