#include "SimpleList.h"

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
                if (current->getScore() > index->getScore())
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