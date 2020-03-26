#include "QueueNode.h"

QueueNode::QueueNode(char letter, int score)
{
	this->letter = letter;
	this->score = score;
	nextNode = nullptr;
}

QueueNode::~QueueNode()
{
}

char QueueNode::getLetter()
{
	return letter;
}

void QueueNode::setLetter(char letter)
{
	this->letter = letter;
}

int QueueNode::getScore()
{
	return score;
}

void QueueNode::setScore(int score)
{
	this->score = score;
}

QueueNode *QueueNode::getNextNode() const
{
	return nextNode;
}

void QueueNode::setNextNode(QueueNode *nextNode)
{
	this->nextNode = nextNode;
}
