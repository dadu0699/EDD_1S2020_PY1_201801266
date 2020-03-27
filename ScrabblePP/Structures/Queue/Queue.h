#ifndef SCRABBLE___QUEUE_H
#define SCRABBLE___QUEUE_H

#include "QueueNode.h"

class Queue
{
private:
	QueueNode *firstNode;
	QueueNode *lastNode;
	int length;

	bool isEmpty();
	void pushLetter();

public:
	Queue();
	~Queue();

	void push(Letter *letter);
	QueueNode *pop();
	int getLength();
	void report();
};

#endif //SCRABBLE___QUEUE_H
