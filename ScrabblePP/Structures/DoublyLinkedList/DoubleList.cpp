#include "DoubleList.h"
#include <iostream>
#include <fstream>

using namespace std;

DoubleList::DoubleList()
{
    firstNode = nullptr;
    lastNode = nullptr;
}

DoubleList::~DoubleList()
{
}

bool DoubleList::isEmpty()
{
    return firstNode == nullptr;
}

void DoubleList::addFirstNode(char letter)
{
    DoubleNode *node = new DoubleNode(letter);
    if (isEmpty())
    {
        lastNode = node;
    }
    else
    {
        node->setNextNode(firstNode);
        firstNode->setPreviousNode(node);
    }
    firstNode = node;
}

void DoubleList::addLastNode(char letter)
{
    DoubleNode *node = new DoubleNode(letter);
    if (isEmpty())
    {
        firstNode = node;
    }
    else
    {
        node->setPreviousNode(lastNode);
        lastNode->setNextNode(node);
    }
    lastNode = node;
}

void DoubleList::readStartNodes()
{
    DoubleNode *auxiliaryNode = firstNode;
    while (auxiliaryNode != nullptr)
    {
        cout << auxiliaryNode->getLetter() << " <--> ";
        auxiliaryNode = auxiliaryNode->getNextNode();
    }
    cout << endl;
}

void DoubleList::readEndNodes()
{
    DoubleNode *auxiliaryNode = lastNode;
    while (auxiliaryNode != nullptr)
    {
        cout << auxiliaryNode->getLetter() << " <--> ";
        auxiliaryNode = auxiliaryNode->getPreviousNode();
    }
    cout << endl;
}

void DoubleList::updateNode(char oldLetter, char newLetter)
{
    DoubleNode *node = searchNode(oldLetter);
    if (node != nullptr)
    {
        node->setLetter(newLetter);
    }
}

void DoubleList::deleteFirstNode()
{
    if (!isEmpty())
    {
        firstNode = firstNode->getNextNode();
        firstNode->setPreviousNode(nullptr);
    }
}

void DoubleList::deleteLastNode()
{
    if (!isEmpty())
    {
        DoubleNode *auxiliaryNode = firstNode;
        while (auxiliaryNode->getNextNode() != lastNode)
        {
            auxiliaryNode = auxiliaryNode->getNextNode();
        }
        lastNode = auxiliaryNode;
        lastNode->setNextNode(nullptr);
    }
}

void DoubleList::deleteSpecificNode(char letter)
{
    if (!isEmpty())
    {
        if (firstNode == lastNode && letter == firstNode->getLetter())
        {
            firstNode = nullptr;
        }
        else if (letter == firstNode->getLetter())
        {
            firstNode = firstNode->getNextNode();
            firstNode->setPreviousNode(nullptr);
        }
        else
        {
            DoubleNode *auxiliaryNode = searchNode(letter);
            if (auxiliaryNode != nullptr)
            {
                DoubleNode *previousNode = auxiliaryNode->getPreviousNode();
                DoubleNode *nextNode = auxiliaryNode->getNextNode();
                previousNode->setNextNode(auxiliaryNode->getNextNode());
                if (nextNode != nullptr)
                {
                    nextNode->setPreviousNode(auxiliaryNode->getPreviousNode());
                }
            }
        }
    }
}

DoubleNode *DoubleList::searchNode(char letter)
{
    DoubleNode *auxiliaryNode = firstNode;
    while (auxiliaryNode != nullptr && auxiliaryNode->getLetter() != letter)
    {
        auxiliaryNode = auxiliaryNode->getNextNode();
    }
    return auxiliaryNode;
}

void DoubleList::report()
{
    if (!isEmpty())
    {
        DoubleNode* auxiliaryNode = firstNode;
        ofstream myfile("DoublyLinkedList.dot");
        int index = 0;

        if (myfile.is_open())
        {
            myfile << "digraph G { rankdir = LR;";
            myfile << "node[shape=record, style=filled fillcolor=cornsilk2];";

            while (auxiliaryNode != nullptr)
            {
                myfile << "N" << index << " [label =\"" << auxiliaryNode->getLetter() << "\"];";
                auxiliaryNode = auxiliaryNode->getNextNode();
                index++;
            }

            for (int i = 0; i < (index - 1); i++)
            {
                myfile << "N" << i << " -> N" << (i + 1) << ";";
                myfile << "N" << (i + 1) << " -> N" << i << ";";
            }

            myfile << "}";

            myfile.close();
            system("dot -Tpng DoublyLinkedList.dot -o DoublyLinkedList.png");
            system("DoublyLinkedList.png");
        }
        else
        {
            cout << "Unable to open file";
        }
    }
}
