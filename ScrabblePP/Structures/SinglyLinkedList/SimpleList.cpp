#include "SimpleList.h"
#include <iostream>
#include <fstream>

using namespace std;

SimpleList::SimpleList()
{
    firstNode = nullptr;
    lastNode = nullptr;
}

SimpleList::~SimpleList()
{
}

bool SimpleList::isEmpty()
{
    return firstNode == nullptr;
}

SimpleNode* SimpleList::getFirstNode() const
{
    return firstNode;
}

SimpleNode* SimpleList::getLastNode() const
{
    return lastNode;
}

void SimpleList::addFirstNode(int score)
{
    SimpleNode *node = new SimpleNode(score);
    if (isEmpty())
    {
        lastNode = node;
    }
    else
    {
        node->setNextNode(firstNode);
    }
    firstNode = node;
    sortList();
}

void SimpleList::addLastNode(int score)
{
    SimpleNode *node = new SimpleNode(score);
    if (isEmpty())
    {
        firstNode = node;
    }
    else
    {
        lastNode->setNextNode(node);
    }
    lastNode = node;
    sortList();
}

void SimpleList::readNodes()
{
    SimpleNode *auxiliaryNode = firstNode;
    while (auxiliaryNode != nullptr)
    {
        cout << auxiliaryNode->getScore() << " --> ";
        auxiliaryNode = auxiliaryNode->getNextNode();
    }
    cout << endl;
}

void SimpleList::updateNode(int oldScore, int newScore)
{
    SimpleNode *node = searchNode(oldScore);
    if (node != nullptr)
    {
        node->setScore(newScore);
    }
}

void SimpleList::deleteFirstNode()
{
    if (!isEmpty())
    {
        firstNode = firstNode->getNextNode();
    }
}

void SimpleList::deleteLastNode()
{
    if (!isEmpty())
    {
        SimpleNode *auxiliaryNode = firstNode;
        while (auxiliaryNode->getNextNode() != lastNode)
        {
            auxiliaryNode = auxiliaryNode->getNextNode();
        }
        lastNode = auxiliaryNode;
        lastNode->setNextNode(nullptr);
    }
}

void SimpleList::deleteSpecificNode(int score)
{
    if (!isEmpty())
    {
        if (firstNode == lastNode && score == firstNode->getScore())
        {
            firstNode = nullptr;
        }
        else if (score == firstNode->getScore())
        {
            firstNode = firstNode->getNextNode();
        }
        else
        {
            SimpleNode *previousNode = firstNode;
            SimpleNode *auxiliaryNode = firstNode->getNextNode();
            while (auxiliaryNode != nullptr && auxiliaryNode->getScore() != score)
            {
                previousNode = previousNode->getNextNode();
                auxiliaryNode = auxiliaryNode->getNextNode();
            }
            if (auxiliaryNode != nullptr)
            {
                previousNode->setNextNode(auxiliaryNode->getNextNode());
            }
        }
    }
}

SimpleNode *SimpleList::searchNode(int score)
{
    SimpleNode *auxiliaryNode = firstNode;
    while (auxiliaryNode != nullptr && auxiliaryNode->getScore() != score)
    {
        auxiliaryNode = auxiliaryNode->getNextNode();
    }
    return auxiliaryNode;
}

void SimpleList::sortList()
{
    SimpleNode *current = firstNode;
    SimpleNode *index;
    int temp;

    if (!isEmpty())
    {
        while (current != nullptr)
        {
            index = current->getNextNode();
            while (index != nullptr)
            {
                if (current->getScore() < index->getScore())
                {
                    temp = current->getScore();
                    current->setScore(index->getScore());
                    index->setScore(temp);
                }
                index = index->getNextNode();
            }
            current = current->getNextNode();
        }
    }
}

void SimpleList::report()
{
    if (!isEmpty())
    {
        SimpleNode *auxiliaryNode = firstNode;
        ofstream myfile("playerScores.dot");
        int index = 0;

        if (myfile.is_open())
        {
            myfile << "digraph G { rankdir = LR;";
            myfile << "node[shape=record, style=filled fillcolor=cornsilk2];";

            while (auxiliaryNode != nullptr)
            {
                myfile << "N" << index << " [label =\"" << auxiliaryNode->getScore() << "\"];";
                auxiliaryNode = auxiliaryNode->getNextNode();
                index++;
            }

            for (int i = 0; i < (index - 1); i++)
            {
                myfile << "N" << i << " -> N" << (i + 1) << ";";
            }

            myfile << "}";

            myfile.close();
            system("dot -Tpng playerScores.dot -o playerScores.png");
            system("playerScores.png");
        }
        else
        {
            cout << "Unable to open file";
        }
    }
}