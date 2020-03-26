#ifndef SCRABBLE___QUEUENODE_H
#define SCRABBLE___QUEUENODE_H

class QueueNode
{
private:
	char letter;
	int score;
	QueueNode *nextNode;

public:
	QueueNode(char letter, int score);
	~QueueNode();

	char getLetter();
	void setLetter(char letter);

	int getScore();
	void setScore(int score);

	QueueNode *getNextNode() const;
	void setNextNode(QueueNode *nextNode);
};

#endif //SCRABBLE___QUEUENODE_H
