#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
	indexNode = 0;
}

BinarySearchTree::~BinarySearchTree()
{
}

bool BinarySearchTree::isEmpty()
{
	return root == nullptr;
}

bool BinarySearchTree::addNode(Player *player)
{
	BinarySearchTreeNode *newNode = new BinarySearchTreeNode(player);
	if (isEmpty())
	{
		root = newNode;
		return true;
	}
	else
	{
		BinarySearchTreeNode *auxiliaryNode = root;
		BinarySearchTreeNode *parentNode;

		while (true)
		{
			parentNode = auxiliaryNode;
			if (player->getName() < auxiliaryNode->getPlayer()->getName())
			{
				auxiliaryNode = auxiliaryNode->getLeftNode();
				if (auxiliaryNode == nullptr)
				{
					parentNode->setLeftNode(newNode);
					return true;
				}
			}
			else if (player->getName() > auxiliaryNode->getPlayer()->getName())
			{
				auxiliaryNode = auxiliaryNode->getRightNode();
				if (auxiliaryNode == nullptr)
				{
					parentNode->setRightNode(newNode);
					return true;
				}
			}
			else if (player->getName() == auxiliaryNode->getPlayer()->getName())
			{
				return false;
			}
		}
	}
	return false;
}

Player *BinarySearchTree::search(string name)
{
	if (!isEmpty())
	{
		BinarySearchTreeNode *auxiliaryNode = root;
		while (auxiliaryNode->getPlayer()->getName() != name)
		{
			if (name < auxiliaryNode->getPlayer()->getName())
			{
				auxiliaryNode = auxiliaryNode->getLeftNode();
			}
			else
			{
				auxiliaryNode = auxiliaryNode->getRightNode();
			}

			if (auxiliaryNode == nullptr)
			{
				return nullptr;
			}
		}
		return auxiliaryNode->getPlayer();
	}
	return nullptr;
}

string BinarySearchTree::printBinarySearchTree(BinarySearchTreeNode *root)
{
	string myfile;
	if (!isEmpty())
	{
		int indexParentNode = indexNode;
		myfile.append("N" + to_string(indexNode) + "[label = \"" + root->getPlayer()->getName() + "\"]; ");

		if (root->getLeftNode() != nullptr)
		{
			indexNode++;
			int indexLeftNode = indexNode;
			myfile.append(printBinarySearchTree(root->getLeftNode()));
			myfile.append("N" + to_string(indexParentNode) + " -> N" + to_string(indexLeftNode) + "; ");
		}

		if (root->getRightNode() != nullptr)
		{
			indexNode++;
			int indexRightNode = indexNode;
			myfile.append(printBinarySearchTree(root->getRightNode()));
			myfile.append("N" + to_string(indexParentNode) + " -> N" + to_string(indexRightNode) + "; ");
		}
	}
	return myfile;
}

void BinarySearchTree::report()
{
	ofstream myfile("BinarySearchTree.dot");

	if (myfile.is_open())
	{
		if (!isEmpty())
		{
			myfile << "digraph G { ";

			indexNode = 0;
			myfile << printBinarySearchTree(root);

			myfile << " }";
			myfile.close();
			system("dot -Tpng BinarySearchTree.dot -o BinarySearchTree.png");
			system("BinarySearchTree.png");
		}
	}
	else
	{
		cout << "Unable to open file";
	}
}

string BinarySearchTree::printInOrder(BinarySearchTreeNode *root)
{
	string myfile;
	if (root != nullptr)
	{
		myfile.append(printInOrder(root->getLeftNode()));
		indexNode++;
		myfile.append("N" + to_string(indexNode) + " [label =\"" + root->getPlayer()->getName() + "\"];");
		myfile.append(printInOrder(root->getRightNode()));
	}
	return myfile;
}

string BinarySearchTree::printPreOrder(BinarySearchTreeNode *root)
{
	string myfile;
	if (root != nullptr)
	{
		indexNode++;
		myfile.append("N" + to_string(indexNode) + " [label =\"" + root->getPlayer()->getName() + "\"];");
		myfile.append(printPreOrder(root->getLeftNode()));
		myfile.append(printPreOrder(root->getRightNode()));
	}
	return myfile;
}

string BinarySearchTree::printPostOrder(BinarySearchTreeNode *root)
{
	string myfile;
	if (root != nullptr)
	{
		myfile.append(printPostOrder(root->getLeftNode()));
		myfile.append(printPostOrder(root->getRightNode()));
		indexNode++;
		myfile.append("N" + to_string(indexNode) + " [label =\"" + root->getPlayer()->getName() + "\"];");
	}
	return myfile;
}

void BinarySearchTree::reportInOrder()
{
	ofstream myfile("inOrder.dot");

	if (myfile.is_open())
	{
		if (!isEmpty())
		{
			myfile << "digraph G { rankdir = LR;";
			myfile << "node[shape=record, style=filled fillcolor=cornsilk2];";

			indexNode = -1;
			myfile << printInOrder(root);

			for (int i = 0; i < indexNode; i++)
			{
				myfile << "N" << i << " -> N" << (i + 1) << ";";
			}

			myfile << " }";
			myfile.close();
			system("dot -Tpng inOrder.dot -o inOrder.png");
			system("inOrder.png");
		}
	}
	else
	{
		cout << "Unable to open file";
	}
}

void BinarySearchTree::reportPreOrder()
{
	ofstream myfile("preOrder.dot");

	if (myfile.is_open())
	{
		if (!isEmpty())
		{
			myfile << "digraph G { rankdir = LR;";
			myfile << "node[shape=record, style=filled fillcolor=cornsilk2];";

			indexNode = -1;
			myfile << printPreOrder(root);

			for (int i = 0; i < indexNode; i++)
			{
				myfile << "N" << i << " -> N" << (i + 1) << ";";
			}

			myfile << " }";
			myfile.close();
			system("dot -Tpng preOrder.dot -o preOrder.png");
			system("preOrder.png");
		}
	}
	else
	{
		cout << "Unable to open file";
	}
}

void BinarySearchTree::reportPostOrder()
{
	ofstream myfile("postOrder.dot");

	if (myfile.is_open())
	{
		if (!isEmpty())
		{
			myfile << "digraph G { rankdir = LR;";
			myfile << "node[shape=record, style=filled fillcolor=cornsilk2];";

			indexNode = -1;
			myfile << printPostOrder(root);

			for (int i = 0; i < indexNode; i++)
			{
				myfile << "N" << i << " -> N" << (i + 1) << ";";
			}

			myfile << " }";
			myfile.close();
			system("dot -Tpng postOrder.dot -o postOrder.png");
			system("postOrder.png");
		}
	}
	else
	{
		cout << "Unable to open file";
	}
}

void BinarySearchTree::scoreBoard(BinarySearchTreeNode *root)
{
	if (root != nullptr)
	{
		scoreBoard(root->getLeftNode());
		indexNode++;
		scoreBoardList->addFirstNode(root->getPlayer()->getName(), root->getPlayer()->getScores()->getFirstNode()->getScore());
		scoreBoard(root->getRightNode());
	}
}

void BinarySearchTree::scoreBoard()
{
	scoreBoardList = new SortedSimpleList();
	scoreBoard(root);
	scoreBoardList->report();
}