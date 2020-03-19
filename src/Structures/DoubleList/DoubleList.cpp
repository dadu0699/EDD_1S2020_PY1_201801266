/*
#include <iostream>
#include "DoubleList.h"

using namespace std;

template<class T>
DoubleList<T>::DoubleList() {
    firstNode = nullptr;
    lastNode = nullptr;
}

template<class T>
DoubleList<T>::~DoubleList() {
}

template<class T>
bool DoubleList<T>::isEmpty() {
    return firstNode == nullptr;
}

template<class T>
void DoubleList<T>::addFirstNode(T object) {
    DoubleNode<T> *node = new DoubleNode<T>(object);
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

template<class T>
void DoubleList<T>::addLastNode(T object) {
    DoubleNode<T> *node = new DoubleNode<T>(object);
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

template<class T>
void DoubleList<T>::readStartNodes() {
    DoubleNode<T> *auxiliaryNode = firstNode;
    while (auxiliaryNode != nullptr)
    {
        cout << auxiliaryNode->getObject() << " <--> ";
        auxiliaryNode = auxiliaryNode->getNextNode();
    }
    cout << endl;
}

template<class T>
void DoubleList<T>::readEndNodes() {
    DoubleNode<T> *auxiliaryNode = lastNode;
    while (auxiliaryNode != nullptr)
    {
        cout << auxiliaryNode->getObject() << " <--> ";
        auxiliaryNode = auxiliaryNode->getPreviousNode();
    }
    cout << endl;
}

template<class T>
void DoubleList<T>::updateNode(T oldObject, T newObject) {
    DoubleNode<T> *node = searchNode(oldObject);
    if (node != nullptr) {
        node->setObject(newObject);
    }
}

template<class T>
void DoubleList<T>::deleteFirstNode() {
    if (!isEmpty()) {
        firstNode = firstNode->getNextNode();
        firstNode->setPreviousNode(nullptr);
    }
}

template<class T>
void DoubleList<T>::deleteLastNode() {
    if (!isEmpty()) {
        DoubleNode<T> *auxiliaryNode = firstNode;
        while (auxiliaryNode->getNextNode() != lastNode) {
            auxiliaryNode = auxiliaryNode->getNextNode();
        }
        lastNode = auxiliaryNode;
        lastNode->setNextNode(nullptr);
    }
}

template<class T>
void DoubleList<T>::deleteSpecificNode(T object) {
    if (!isEmpty()) {
        if (firstNode == lastNode && object == firstNode->getObject()) {
            firstNode = nullptr;
        } else if (object == firstNode->getObject()) {
            firstNode = firstNode->getNextNode();
            firstNode->setPreviousNode(nullptr);
        } else {
            DoubleNode<T> *auxiliaryNode = searchNode(object);
            if (auxiliaryNode != nullptr) {
                DoubleNode<T> *previousNode = auxiliaryNode->getPreviousNode();
                DoubleNode<T> *nextNode = auxiliaryNode->getNextNode();
                previousNode->setNextNode(auxiliaryNode->getNextNode());
                if (nextNode != nullptr) {
                    nextNode->setPreviousNode(auxiliaryNode->getPreviousNode());
                }
            }
        }
    }
}

template<class T>
DoubleNode<T> *DoubleList<T>::searchNode(T object) {
    DoubleNode<T> *auxiliaryNode = firstNode;
    while (auxiliaryNode != nullptr && auxiliaryNode->getObject() != object) {
        auxiliaryNode = auxiliaryNode->getNextNode();
    }
    return auxiliaryNode;
}
*/
