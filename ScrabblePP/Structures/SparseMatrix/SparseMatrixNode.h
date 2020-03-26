#ifndef SCRABBLE___SPARSEMATRIXNODE_H
#define SCRABBLE___SPARSEMATRIXNODE_H

#include <iostream>

using namespace std;

class SparseMatrixNode
{
private:
	int x;
	int y;
	int score;
	string data;
	SparseMatrixNode *nextNode;
	SparseMatrixNode *previousNode;
	SparseMatrixNode *upNode;
	SparseMatrixNode *downNode;

public:
	SparseMatrixNode(int x, int y, int score, string data);
	~SparseMatrixNode();

	int getX();
	void setX(int x);

	int getY();
	void setY(int y);

	int getScore();
	void setScore(int score);

	string getData();
	void setData(string data);

	SparseMatrixNode *getNextNode() const;
	void setNextNode(SparseMatrixNode *nextNode);

	SparseMatrixNode *getPreviousNode() const;
	void setPreviousNode(SparseMatrixNode *previousNode);

	SparseMatrixNode *getUpNode() const;
	void setUpNode(SparseMatrixNode *upNode);

	SparseMatrixNode *getDownNode() const;
	void setDownNode(SparseMatrixNode *downNode);
};

#endif //SCRABBLE___SPARSEMATRIXNODE_H
