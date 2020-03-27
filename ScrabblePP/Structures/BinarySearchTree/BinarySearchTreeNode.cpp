#include "BinarySearchTreeNode.h"

BinarySearchTreeNode::BinarySearchTreeNode(Player *player)
{
	this->player = player;
	leftNode = nullptr;
	rightNode = nullptr;
}

BinarySearchTreeNode::~BinarySearchTreeNode()
{
}

Player *BinarySearchTreeNode::getPlayer() const
{
	return player;
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
