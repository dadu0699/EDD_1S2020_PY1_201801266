#ifndef SCRABBLE___BINARYSEARCHTREE_H
#define SCRABBLE___BINARYSEARCHTREE_H

#include "BinarySearchTreeNode.h"

class BinarySearchTree
{
private:
	BinarySearchTreeNode *root;
	int indexNode;

	bool isEmpty();

	string printBinarySearchTree(BinarySearchTreeNode *root);
	string printInOrder(BinarySearchTreeNode *root);
	string printPreOrder(BinarySearchTreeNode *root);
	string printPostOrder(BinarySearchTreeNode *root);

public:
	BinarySearchTree();

	~BinarySearchTree();

	bool addNode(Player *player);

	void report();

	void reportInOrder();

	void reportPreOrder();

	void reportPostOrder();
};

#endif //SCRABBLE___BINARYSEARCHTREE_H
