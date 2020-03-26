#include "BinarySearchTreeNode.h"

BinarySearchTreeNode::BinarySearchTreeNode(string name)
{
	this->name = name;
	scores = new SimpleList();
	leftNode = nullptr;
	rightNode = nullptr;
}

BinarySearchTreeNode::~BinarySearchTreeNode()
{
}

string BinarySearchTreeNode::getName()
{
	return name;
}

void BinarySearchTreeNode::setName(string name)
{
	this->name = name;
}

SimpleList *BinarySearchTreeNode::getScores()
{
	return scores;
}
BinarySearchTreeNode *BinarySearchTreeNode::getLeftNode() const
{
	return leftNode;
}

void BinarySearchTreeNode::setLeftNode(BinarySearchTreeNode *leftNode)
{
	this->leftNode = leftNode;
}

BinarySearchTreeNode *BinarySearchTreeNode::getRightNode() const
{
	return rightNode;
}

void BinarySearchTreeNode::setRightNode(BinarySearchTreeNode *rightNode)
{
	this->rightNode = rightNode;
}
