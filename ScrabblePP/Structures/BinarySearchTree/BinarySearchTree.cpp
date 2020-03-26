#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
}

bool BinarySearchTree::isEmpty()
{
	return root == nullptr;
}

bool BinarySearchTree::addNode(string name)
{
	BinarySearchTreeNode *newNode = new BinarySearchTreeNode(name);
	if (isEmpty())
	{
		root = newNode;
	}
	else
	{
		BinarySearchTreeNode *auxiliaryNode = root;
		BinarySearchTreeNode *parentNode;

		while (true)
		{
			parentNode = auxiliaryNode;
			if (name < auxiliaryNode->getName())
			{
				auxiliaryNode = auxiliaryNode->getLeftNode();
				if (auxiliaryNode == nullptr)
				{
					parentNode->setLeftNode(newNode);
					return true;
				}
			}
			else if (name > auxiliaryNode->getName())
			{
				auxiliaryNode = auxiliaryNode->getRightNode();
				if (auxiliaryNode == nullptr)
				{
					parentNode->setRightNode(newNode);
					return true;
				}
			}
			else if (name == auxiliaryNode->getName())
			{
				return false;
			}
		}
	}
}

string BinarySearchTree::printBinarySearchTree(BinarySearchTreeNode *root)
{
	string myfile;
	if (!isEmpty())
	{
		int indexParentNode = indexNode;
		myfile.append("N" + to_string(indexNode) + "[label = \"" + root->getName() + "\"]; ");

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
		if (root != nullptr)
		{
			myfile << "digraph G { ";

			indexNode = 0;
			myfile << printBinarySearchTree(root);

			myfile << " }";
			myfile.close();
			system("dot -Tpng BinarySearchTree.dot -o BinarySearchTree.png");
			system("BinarySearchTree.png");
		}
		else
		{
			cout << "Unable to open file";
		}
	}
}