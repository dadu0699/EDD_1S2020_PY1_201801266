#include "CircularDoubleNode.h"

CircularDoubleNode::CircularDoubleNode(string word)
{
    this->word = word;
    nextNode = this;
    previousNode = this;
}

CircularDoubleNode::~CircularDoubleNode()
{
}

string CircularDoubleNode::getWord()
{
    return word;
}

void CircularDoubleNode::setWord(string word)
{
    this->word = word;
}

CircularDoubleNode *CircularDoubleNode::getNextNode() const
{
    return nextNode;
}

void CircularDoubleNode::setNextNode(CircularDoubleNode *nextNode)
{
    this->nextNode = nextNode;
}

CircularDoubleNode *CircularDoubleNode::getPreviousNode() const
{
    return previousNode;
}

void CircularDoubleNode::setPreviousNode(CircularDoubleNode *previousNode)
{
    this->previousNode = previousNode;
}