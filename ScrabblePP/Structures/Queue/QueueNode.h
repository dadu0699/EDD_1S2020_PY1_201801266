#ifndef SCRABBLE___QUEUENODE_H
#define SCRABBLE___QUEUENODE_H

#include "../../Model/Letter.h"

class QueueNode
{
private:
	Letter *letter;
	QueueNode *nextNode;

public:
	QueueNode(Letter *letter);
	~QueueNode();

	Letter *getLetter() const;

	QueueNode *getNextNode() const;
	void setNextNode(QueueNode *nextNode);
};

#endif //SCRABBLE___QUEUENODE_H
