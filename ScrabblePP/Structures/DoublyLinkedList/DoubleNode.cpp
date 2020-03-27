#include "DoubleNode.h"

DoubleNode::DoubleNode(Letter *letter)
{
    this->letter = letter;
    nextNode = nullptr;
    previousNode = nullptr;
}

DoubleNode::~DoubleNode()
{
}

Letter *DoubleNode::getLetter() const
{
    return letter;
}

DoubleNode *DoubleNode::getNextNode() const
{
    return nextNode;
}

void DoubleNode::setNextNode(DoubleNode *nextNode)
{
    this->nextNode = nextNode;
}

DoubleNode *DoubleNode::getPreviousNode() const
{
    return previousNode;
}

void DoubleNode::setPreviousNode(DoubleNode *previousNode)
{
    this->previousNode = previousNode;
}