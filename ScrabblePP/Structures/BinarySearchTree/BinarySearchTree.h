#ifndef SCRABBLE___BINARYSEARCHTREE_H
#define SCRABBLE___BINARYSEARCHTREE_H

#include "BinarySearchTreeNode.h"
#include "../SortedSinglyLinkedList/SortedSimpleList.h"

class BinarySearchTree
{
private:
	BinarySearchTreeNode *root;
	SortedSimpleList *scoreBoardList;
	int indexNode;

	bool isEmpty();

	string printBinarySearchTree(BinarySearchTreeNode *root);
	string printInOrder(BinarySearchTreeNode *root);
	string printPreOrder(BinarySearchTreeNode *root);
	string printPostOrder(BinarySearchTreeNode *root);
	void scoreBoard(BinarySearchTreeNode *root);

public:
	BinarySearchTree();

	~BinarySearchTree();

	bool addNode(Player *player);

	Player *search(string name);

	void report();

	void reportInOrder();

	void reportPreOrder();

	void reportPostOrder();

	void scoreBoard();
};

#endif //SCRABBLE___BINARYSEARCHTREE_H
