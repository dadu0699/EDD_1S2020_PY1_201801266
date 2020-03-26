#include "SortedSimpleList.h"
#include <iostream>
#include <fstream>

using namespace std;

SortedSimpleList::SortedSimpleList()
{
    firstNode = nullptr;
    lastNode = nullptr;
}

SortedSimpleList::~SortedSimpleList()
{
}

bool SortedSimpleList::isEmpty()
{
    return firstNode == nullptr;
}

void SortedSimpleList::addFirstNode(string name, int score)
{
    SortedSimpleNode *node = new SortedSimpleNode(name, score);
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

void SortedSimpleList::addLastNode(string name, int score)
{
    SortedSimpleNode *node = new SortedSimpleNode(name, score);
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

void SortedSimpleList::readNodes()
{
    SortedSimpleNode *auxiliaryNode = firstNode;
    while (auxiliaryNode != nullptr)
    {
        cout << auxiliaryNode->getName() << " --> ";
        auxiliaryNode = auxiliaryNode->getNextNode();
    }
    cout << endl;
}

void SortedSimpleList::sortList()
{
    SortedSimpleNode *current = firstNode;
    SortedSimpleNode *index;
    int tempScore;
    string tempName;

    if (!isEmpty())
    {
        while (current != nullptr)
        {
            index = current->getNextNode();
            while (index != nullptr)
            {
                if (current->getScore() < index->getScore())
                {
                    tempScore = current->getScore();
                    tempName = current->getName();
                    current->setScore(index->getScore());
                    current->setName(index->getName());
                    index->setScore(tempScore);
                    index->setName(tempName);
                }
                index = index->getNextNode();
            }
            current = current->getNextNode();
        }
    }
}

void SortedSimpleList::report()
{
    if (!isEmpty())
    {
        SortedSimpleNode *auxiliaryNode = firstNode;
        ofstream myfile("scoreboard.dot");
        int index = 0;

        if (myfile.is_open())
        {
            myfile << "digraph G { rankdir = LR;";
            myfile << "node[shape=record, style=filled fillcolor=cornsilk2];";

            while (auxiliaryNode != nullptr)
            {
                myfile << "N" << index << " [label =\"" << auxiliaryNode->getName() << ", " << auxiliaryNode->getScore() << "\"];";
                auxiliaryNode = auxiliaryNode->getNextNode();
                index++;
            }

            for (int i = 0; i < (index - 1); i++)
            {
                myfile << "N" << i << " -> N" << (i + 1) << ";";
            }

            myfile << "}";

            myfile.close();
            system("dot -Tpng scoreboard.dot -o scoreboard.png");
            system("scoreboard.png");
        }
        else
        {
            cout << "Unable to open file";
        }
    }
}