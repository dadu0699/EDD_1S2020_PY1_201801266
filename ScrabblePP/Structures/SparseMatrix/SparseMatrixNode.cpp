#include "SparseMatrixNode.h"

SparseMatrixNode::SparseMatrixNode(int x, int y, int score, string data)
{
	this->x = x;
	this->y = y;
	this->score = score;
	this->data = data;
	nextNode = nullptr;
	previousNode = nullptr;
	upNode = nullptr;
	downNode = nullptr;
}

SparseMatrixNode::~SparseMatrixNode()
{
}

int SparseMatrixNode::getX()
{
	return x;
}

void SparseMatrixNode::setX(int x)
{
	this->x = x;
}

int SparseMatrixNode::getY()
{
	return y;
}

void SparseMatrixNode::setY(int y)
{
	this->y = y;
}

int SparseMatrixNode::getScore()
{
	return score;
}

void SparseMatrixNode::setScore(int score)
{
	this->score = score;
}

string SparseMatrixNode::getData()
{
	return data;
}

void SparseMatrixNode::setData(string data)
{
	this->data = data;
}

SparseMatrixNode *SparseMatrixNode::getNextNode() const
{
	return nextNode;
}

void SparseMatrixNode::setNextNode(SparseMatrixNode *nextNode)
{
	this->nextNode = nextNode;
}

SparseMatrixNode *SparseMatrixNode::getPreviousNode() const
{
	return previousNode;
}

void SparseMatrixNode::setPreviousNode(SparseMatrixNode *previousNode)
{
	this->previousNode = previousNode;
}

SparseMatrixNode *SparseMatrixNode::getUpNode() const
{
	return upNode;
}

void SparseMatrixNode::setUpNode(SparseMatrixNode *upNode)
{
	this->upNode = upNode;
}

SparseMatrixNode *SparseMatrixNode::getDownNode() const
{
	return downNode;
}

void SparseMatrixNode::setDownNode(SparseMatrixNode *downNode)
{
	this->downNode = downNode;
}
