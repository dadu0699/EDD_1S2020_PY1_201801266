#include "CircularDoubleList.h"
#include <iostream>
#include <fstream>

using namespace std;

CircularDoubleList::CircularDoubleList()
{
	firstNode = nullptr;
}

CircularDoubleList::~CircularDoubleList()
{
}

bool CircularDoubleList::isEmpty()
{
	return firstNode == nullptr;
}

void CircularDoubleList::addNode(string word)
{
	CircularDoubleNode *newNode = new CircularDoubleNode(word);
	CircularDoubleNode *lastNode;

	if (firstNode != nullptr)
	{
		newNode->setNextNode(firstNode->getNextNode());
		newNode->setPreviousNode(firstNode);
		firstNode->setNextNode(newNode);
	}
	firstNode = newNode;

	lastNode = getLastNode();
	if (lastNode != nullptr)
	{
		lastNode->getNextNode()->setPreviousNode(newNode);
	}
}

void CircularDoubleList::readStartNodes()
{
	if (!isEmpty())
	{
		CircularDoubleNode *auxiliaryNode = firstNode->getNextNode();
		do
		{
			cout << auxiliaryNode->getPreviousNode()->getWord() << " <--> ";
			cout << auxiliaryNode->getWord() << " <--> ";
			cout << auxiliaryNode->getNextNode()->getWord() << endl;
			auxiliaryNode = auxiliaryNode->getNextNode();
		} while (auxiliaryNode != firstNode->getNextNode());
		cout << endl;
	}
}

void CircularDoubleList::readEndNodes()
{
	if (!isEmpty())
	{
		CircularDoubleNode *auxiliaryNode = getLastNode();
		do
		{
			cout << auxiliaryNode->getPreviousNode()->getWord() << " <--> ";
			cout << auxiliaryNode->getWord() << " <--> ";
			cout << auxiliaryNode->getNextNode()->getWord() << endl;
			auxiliaryNode = auxiliaryNode->getPreviousNode();
		} while (auxiliaryNode != firstNode);
		cout << endl;
	}
}

void CircularDoubleList::updateNode(string oldWord, string newWord)
{
	CircularDoubleNode *node = searchNode(oldWord);
	if (node != nullptr)
	{
		node->setWord(newWord);
	}
}

void CircularDoubleList::deleteSpecificNode(string word)
{
	if (!isEmpty())
	{
		CircularDoubleNode *auxiliaryNode = searchNode(word);
		if (auxiliaryNode != nullptr)
		{
			CircularDoubleNode *previousNode = auxiliaryNode->getPreviousNode();
			CircularDoubleNode *nextNode = auxiliaryNode->getNextNode();

			previousNode->setNextNode(auxiliaryNode->getNextNode());
			nextNode->setPreviousNode(auxiliaryNode->getPreviousNode());

			if (firstNode == auxiliaryNode)
			{
				if (firstNode == previousNode && firstNode == nextNode)
				{
					firstNode = nullptr;
				}
				else
				{
					firstNode = firstNode->getPreviousNode();
					firstNode->setNextNode(nextNode);
				}
			}
		}
	}
}

CircularDoubleNode *CircularDoubleList::searchNode(string word)
{
	CircularDoubleNode *auxiliaryNode = firstNode;
	string auxWord;
	do
	{
		auxWord = auxiliaryNode->getWord();
		for (int i = 0; i < auxWord.length(); i++)
		{
			auxWord[i] = towupper(auxWord[i]);
		}

		if (word == auxWord)
		{
			return auxiliaryNode;
		}
		else
		{
			auxiliaryNode = auxiliaryNode->getNextNode();
		}
	} while (auxiliaryNode != firstNode);
	return nullptr;
}

CircularDoubleNode *CircularDoubleList::getLastNode()
{
	CircularDoubleNode *lastNode = firstNode;
	if (firstNode != nullptr)
	{
		do
		{
			lastNode = lastNode->getNextNode();
		} while (lastNode != firstNode);
	}
	return lastNode;
}

void CircularDoubleList::report()
{
	if (!isEmpty())
	{
		CircularDoubleNode *auxiliaryNode = firstNode->getNextNode();
		ofstream myfile("CircularDoublyLinkedList.dot");
		int index = 0;

		if (myfile.is_open())
		{
			myfile << "digraph G { rankdir = LR;";
			myfile << "node[shape=record, style=filled fillcolor=cornsilk2];";

			do
			{
				myfile << "N" << index << " [label =\"" << auxiliaryNode->getWord() << "\"];";
				auxiliaryNode = auxiliaryNode->getNextNode();
				index++;
			} while (auxiliaryNode != firstNode->getNextNode());

			for (int i = 0; i < (index - 1); i++)
			{
				myfile << "N" << i << " -> N" << (i + 1) << ";";
				myfile << "N" << (i + 1) << " -> N" << i << ";";
			}
			myfile << "N" << 0 << " -> N" << (index - 1) << ";";
			myfile << "N" << (index - 1) << " -> N" << 0 << ";";

			myfile << "}";

			myfile.close();
			system("dot -Tpng CircularDoublyLinkedList.dot -o CircularDoublyLinkedList.png");
			system("CircularDoublyLinkedList.png");
		}
		else
		{
			cout << "Unable to open file";
		}
	}
}