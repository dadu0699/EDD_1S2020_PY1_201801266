#ifndef SCRABBLE___BINARYSEARCHTREE_H
#define SCRABBLE___BINARYSEARCHTREE_H

#include <iostream>
#include <fstream>
#include <string>
#include "BinarySearchTreeNode.h"

using namespace std;

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

	bool addNode(string name);

	void report();

	void inOrder(BinarySearchTreeNode* root);

	void preOrder(BinarySearchTreeNode* root);
	
	void postOrder(BinarySearchTreeNode* root);
};

#endif //SCRABBLE___BINARYSEARCHTREE_H
