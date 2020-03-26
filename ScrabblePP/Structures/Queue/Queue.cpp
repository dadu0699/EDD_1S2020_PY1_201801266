#include "Queue.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Queue::Queue()
{
	firstNode = nullptr;
	lastNode = nullptr;
	length = 0;
	pushLetter();
}

Queue::~Queue()
{
}

bool Queue::isEmpty()
{
	return firstNode == nullptr;
}

void Queue::push(char letter, int score)
{
	QueueNode* node = new QueueNode(letter, score);
	if (isEmpty())
	{
		firstNode = node;
	}
	else
	{
		lastNode->setNextNode(node);
	}
	lastNode = node;
	length++;
}

QueueNode* Queue::pop()
{
	if (!isEmpty())
	{
		QueueNode* node = firstNode;
		firstNode = firstNode->getNextNode();
		length--;
		return node;
	}
	return nullptr;
}

int Queue::getLength()
{
	return length;
}

void Queue::pushLetter()
{
	char letters[] = { 'A', 'A','A','A','A','A','A', 'A','A','A','A','A',
		'E','E','E','E','E','E','E','E','E','E','E','E',
		'O','O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
		'I','I', 'I', 'I', 'I', 'I', 'S','S', 'S', 'S', 'S', 'S',
		'N','N', 'N', 'N', 'N', 'R','R', 'R', 'R', 'R',
		'U','U', 'U', 'U', 'U', 'D','D', 'D', 'D', 'D',
		'L','L', 'L', 'L', 'T','T', 'T', 'T', 'C', 'C','C', 'C',
		'G', 'G', 'B','B', 'M', 'M', 'P','P','H','H',
		'F','V', 'Y', 'Q', 'J', '\u00D1', 'X', 'Z' };
	int length = sizeof(letters);
	int index = 0;

	while (length > 0)
	{
		srand(time(NULL));
		index = (rand() % length);
		switch (letters[index])
		{
		case 'A':
			push('A', 1);
			break;
		case 'E':
			push('E', 1);
			break;
		case 'O':
			push('O', 1);
			break;
		case 'I':
			push('I', 1);
			break;
		case 'S':
			push('S', 1);
			break;
		case 'N':
			push('N', 1);
			break;
		case 'L':
			push('L', 1);
			break;
		case 'R':
			push('R', 1);
			break;
		case 'U':
			push('U', 1);
			break;
		case 'T':
			push('T', 1);
			break;
		case 'D':
			push('D', 2);
			break;
		case 'G':
			push('G', 2);
			break;
		case 'C':
			push('C', 3);
			break;
		case 'B':
			push('B', 3);
			break;
		case 'M':
			push('M', 3);
			break;
		case 'P':
			push('P', 3);
			break;
		case 'H':
			push('H', 4);
			break;
		case 'F':
			push('F', 4);
			break;
		case 'V':
			push('V', 4);
			break;
		case 'Y':
			push('Y', 4);
			break;
		case 'Q':
			push('Q', 5);
			break;
		case 'J':
			push('J', 8);
			break;
		case '\u00D1':
			push('\u00D1', 8);
			break;
		case 'X':
			push('X', 8);
			break;
		case 'Z':
			push('Z', 10);
			break;
		}

		for (int i = index; i < length - 1; ++i) {
			letters[i] = letters[i + 1];
			cout << letters[i] << " ";
		}
		length--;
	}
}

void Queue::report()
{
	if (!isEmpty())
	{
		QueueNode* auxiliaryNode = firstNode;
		ofstream myfile("Queue.dot");
		int index = 0;

		if (myfile.is_open())
		{
			myfile << "digraph G { rankdir = BT;";
			myfile << "node[shape=record, style=filled fillcolor=cornsilk2];";

			while (auxiliaryNode != nullptr)
			{
				myfile << "N" << index << " [label =\"" << auxiliaryNode->getLetter() << "\"];";
				auxiliaryNode = auxiliaryNode->getNextNode();
				index++;
			}

			for (int i = 0; i < (index - 1); i++)
			{
				myfile << "N" << (i + 1) << " -> N" << i << ";";
			}

			myfile << "}";

			myfile.close();
			system("dot -Tpng Queue.dot -o Queue.png");
			system("Queue.png");
		}
		else
		{
			cout << "Unable to open file";
		}
	}
}