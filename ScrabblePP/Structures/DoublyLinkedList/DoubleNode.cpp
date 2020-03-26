#include "DoubleNode.h"

DoubleNode::DoubleNode(char letter)
{
    this->letter = letter;
    nextNode = nullptr;
    previousNode = nullptr;
}

DoubleNode::~DoubleNode()
{
}

char DoubleNode::getLetter()
{
    return letter;
}

void DoubleNode::setLetter(char letter)
{
    this->letter = letter;
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