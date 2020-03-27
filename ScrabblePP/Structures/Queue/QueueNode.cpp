#include "QueueNode.h"

QueueNode::QueueNode(Letter *letter)
{
	this->letter = letter;
	nextNode = nullptr;
}

QueueNode::~QueueNode()
{
}

Letter *QueueNode::getLetter() const
{
	return letter;
}

QueueNode *QueueNode::getNextNode() const
{
	return nextNode;
}

void QueueNode::setNextNode(QueueNode *nextNode)
{
	this->nextNode = nextNode;
}
