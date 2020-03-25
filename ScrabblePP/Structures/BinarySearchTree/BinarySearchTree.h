#ifndef SCRABBLE___BINARYSEARCHTREE_H
#define SCRABBLE___BINARYSEARCHTREE_H

#include <iostream>
#include <fstream>
#include <string>
#include "BinarySearchTreeNode.h"

using namespace std;

template<class T>
class BinarySearchTree {
private:
	BinarySearchTreeNode<T>* root;
	int indexNode;

	bool isEmpty();

	string printBinarySearchTree(BinarySearchTreeNode<T>* root);

public:
	BinarySearchTree();

	~BinarySearchTree();

	void addNode(T object);

	void report();
};

template<class T>
BinarySearchTree<T>::BinarySearchTree() {
	root = nullptr;
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
}

template<class T>
bool BinarySearchTree<T>::isEmpty() {
	return root == nullptr;
}

template<class T>
void BinarySearchTree<T>::addNode(T object) {
	BinarySearchTreeNode<T>* newNode = new BinarySearchTreeNode<T>(object);
	if (isEmpty()) {
		root = newNode;
	}
	else {
		BinarySearchTreeNode<T>* auxiliaryNode = root;
		BinarySearchTreeNode<T>* parentNode;

		while (true) {
			parentNode = auxiliaryNode;
			if (object < auxiliaryNode->getObject()) {
				auxiliaryNode = auxiliaryNode->getLeftNode();
				if (auxiliaryNode == nullptr) {
					parentNode->setLeftNode(newNode);
					return;
				}
			}
			else if (object > auxiliaryNode->getObject()) {
				auxiliaryNode = auxiliaryNode->getRightNode();
				if (auxiliaryNode == nullptr) {
					parentNode->setRightNode(newNode);
					return;
				}
			}
			else if (object == auxiliaryNode->getObject()) {
				return;
			}
		}
	}
}

template<class T>
string BinarySearchTree<T>::printBinarySearchTree(BinarySearchTreeNode<T>* root) {
	string myfile;
	if (!isEmpty()) {
		int indexParentNode = indexNode;
		myfile.append("N" + to_string(indexNode) + "[label = \"" + to_string(root->getObject()) + "\"]; ");

		if (root->getLeftNode() != nullptr) {
			indexNode++;
			int indexLeftNode = indexNode;
			myfile.append(printBinarySearchTree(root->getLeftNode()));
			myfile.append("N" + to_string(indexParentNode) + " -> N" + to_string(indexLeftNode) + "; ");
		}

		if (root->getRightNode() != nullptr) {
			indexNode++;
			int indexRightNode = indexNode;
			myfile.append(printBinarySearchTree(root->getRightNode()));
			myfile.append("N" + to_string(indexParentNode) + " -> N" + to_string(indexRightNode) + "; ");
		}

		
	}
	return myfile;
}

template<class T>
void BinarySearchTree<T>::report() {
	ofstream myfile("BinarySearchTree.dot");

	if (myfile.is_open()) {
		if (root != nullptr) {
			myfile << "digraph G { ";

			indexNode = 0;
			myfile << printBinarySearchTree(root);

			myfile << " }";
			myfile.close();
			system("dot -Tpng BinarySearchTree.dot -o BinarySearchTree.png");
			system("BinarySearchTree.png");
		}
		else {
			cout << "Unable to open file";
		}
	}
}

#endif //SCRABBLE___BINARYSEARCHTREE_H
