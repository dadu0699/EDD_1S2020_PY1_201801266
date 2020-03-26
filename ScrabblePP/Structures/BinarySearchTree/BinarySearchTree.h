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

public:
	BinarySearchTree();

	~BinarySearchTree();

	void addNode(string name);

	void report();
};

#endif //SCRABBLE___BINARYSEARCHTREE_H
