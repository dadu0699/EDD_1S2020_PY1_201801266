/*
#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

template<class T>
SinglyLinkedList<T>::SinglyLinkedList() {
    firstNode = nullptr;
    lastNode = nullptr;
}

template<class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
}

template<class T>
bool SinglyLinkedList<T>::isEmpty() {
    return firstNode == nullptr;
}

template<class T>
void SinglyLinkedList<T>::addFirstNode(T object) {
    SimpleNode<T> *node = new SimpleNode<T>(object);
    if (isEmpty()) {
        lastNode = node;
    } else {
        node->setNextNode(firstNode);
    }
    firstNode = node;
}

template<class T>
void SinglyLinkedList<T>::addLastNode(T object) {
    SimpleNode<T> *node = new SimpleNode<T>(object);
    if (isEmpty()) {
        firstNode = node;
    } else {
        lastNode->setNextNode(node);
    }
    lastNode = node;
}

template<class T>
void SinglyLinkedList<T>::readNodes() {
    SimpleNode<T> *auxiliaryNode = firstNode;
    while (auxiliaryNode != nullptr) {
        cout << auxiliaryNode->getObject() << " --> ";
        auxiliaryNode = auxiliaryNode->getNextNode();
    }
    cout << endl;
}

template<class T>
void SinglyLinkedList<T>::updateNode(T oldObject, T newObject) {
    SimpleNode<T> *node = searchNode(oldObject);
    if (node != nullptr) {
        node->setObject(newObject);
    }
}

template<class T>
void SinglyLinkedList<T>::deleteFirstNode() {
    if (!isEmpty()) {
        firstNode = firstNode->getNextNode();
    }
}

template<class T>
void SinglyLinkedList<T>::deleteLastNode() {
    if (!isEmpty()) {
        SimpleNode<T> *auxiliaryNode = firstNode;
        while (auxiliaryNode->getNextNode() != lastNode) {
            auxiliaryNode = auxiliaryNode->getNextNode();
        }
        lastNode = auxiliaryNode;
        lastNode->setNextNode(nullptr);
    }
}

template<class T>
void SinglyLinkedList<T>::deleteSpecificNode(T object) {
    if (!isEmpty()) {
        if (firstNode == lastNode && object == firstNode->getObject()) {
            firstNode = nullptr;
        } else if (object == firstNode->getObject()) {
            firstNode = firstNode->getNextNode();
        } else {
            SimpleNode<T> *previousNode = firstNode;
            SimpleNode<T> *auxiliaryNode = firstNode->getNextNode();
            while (auxiliaryNode != nullptr && auxiliaryNode->getObject() != object) {
                previousNode = previousNode->getNextNode();
                auxiliaryNode = auxiliaryNode->getNextNode();
            }
            if (auxiliaryNode != nullptr) {
                previousNode->setNextNode(auxiliaryNode->getNextNode());
            }
        }
    }
}

template<class T>
SimpleNode<T> *SinglyLinkedList<T>::searchNode(T object) {
    SimpleNode<T> *auxiliaryNode = firstNode;
    while (auxiliaryNode != nullptr && auxiliaryNode->getObject() != object) {
        auxiliaryNode = auxiliaryNode->getNextNode();
    }
    return auxiliaryNode;
}

template<class T>
void SinglyLinkedList<T>::sortList() {
    SimpleNode<T> *current = firstNode;
    SimpleNode<T> *index;
    T temp;

    if (!isEmpty()) {
        while (current != nullptr) {
            index = current->getNextNode();
            while (index != nullptr) {
                if (current->getObject() > index->getObject()) {
                    temp = current->getObject();
                    current->setObject(index->getObject());
                    index->setObject(temp);
                }
                index = index->getNextNode();
            }
            current = current->getNextNode();
        }
    }
}
*/
