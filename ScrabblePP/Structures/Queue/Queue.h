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

	void push(char letter, int score);
	QueueNode *pop();
	int getLength();
};

#endif //SCRABBLE___QUEUE_H
