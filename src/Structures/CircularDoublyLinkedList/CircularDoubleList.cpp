/*#include <iostream>
#include "Circular DoublyLinkedList.h"

using namespace std;

template<class T>
Circular DoublyLinkedList<T>::Circular DoublyLinkedList() {
    firstNode = nullptr;
}

template<class T>
Circular DoublyLinkedList<T>::~Circular DoublyLinkedList() {
}

template<class T>
bool Circular DoublyLinkedList<T>::isEmpty() {
    return firstNode == nullptr;
}

template<class T>
void Circular DoublyLinkedList<T>::addNode(T object) {
    CircularDoubleNode<T> *newNode = new CircularDoubleNode<T>(object);
    CircularDoubleNode<T> *lastNode = getLastNode();

    if (firstNode != nullptr) {
        newNode->setNextNode(firstNode->getNextNode());
        newNode->setPreviousNode(firstNode);
        firstNode->setNextNode(newNode);
    }
    firstNode = newNode;

    if (lastNode != nullptr) {
        lastNode->getNextNode()->setPreviousNode(newNode);
    }
}

template<class T>
void Circular DoublyLinkedList<T>::readStartNodes() {
    if (!isEmpty()) {
        CircularDoubleNode<T> *auxiliaryNode = firstNode->getNextNode();
        do {
            cout <<auxiliaryNode->getPreviousNode()->getObject() << " <--> ";
            cout << auxiliaryNode->getObject() << " <--> ";
            cout << auxiliaryNode->getNextNode()->getObject() << endl;
            auxiliaryNode = auxiliaryNode->getNextNode();
        } while (auxiliaryNode != firstNode->getNextNode());
        cout << endl;
    }
}

template<class T>
void Circular DoublyLinkedList<T>::readEndNodes() {
    if (!isEmpty()) {
        CircularDoubleNode<T> *auxiliaryNode = getLastNode();
        do {
            cout <<auxiliaryNode->getPreviousNode()->getObject() << " <--> ";
            cout << auxiliaryNode->getObject() << " <--> ";
            cout << auxiliaryNode->getNextNode()->getObject() << endl;
            auxiliaryNode = auxiliaryNode->getPreviousNode();
        } while (auxiliaryNode != firstNode);
        cout << endl;
    }
}

template<class T>
void Circular DoublyLinkedList<T>::updateNode(T oldObject, T newObject) {
    CircularDoubleNode<T> *node = searchNode(oldObject);
    if (node != nullptr) {
        node->setObject(newObject);
    }
}

template<class T>
void Circular DoublyLinkedList<T>::deleteSpecificNode(T object) {
    if (!isEmpty()) {
        CircularDoubleNode<T> *auxiliaryNode = searchNode(object);
        if (auxiliaryNode != nullptr) {
            CircularDoubleNode<T> *previousNode = auxiliaryNode->getPreviousNode();
            CircularDoubleNode<T> *nextNode = auxiliaryNode->getNextNode();

            previousNode->setNextNode(auxiliaryNode->getNextNode());
            nextNode->setPreviousNode(auxiliaryNode->getPreviousNode());

            if (firstNode == auxiliaryNode) {
                if (firstNode == previousNode && firstNode == nextNode) {
                    firstNode = nullptr;
                } else {
                    firstNode = firstNode->getPreviousNode();
                    firstNode->setNextNode(nextNode);
                }
            }
        }
    }
}

template<class T>
CircularDoubleNode<T> *Circular DoublyLinkedList<T>::searchNode(T object) {
    CircularDoubleNode<T> *auxiliaryNode = firstNode;
    do {
        if (auxiliaryNode->getObject() == object) {
            return auxiliaryNode;
        } else {
            auxiliaryNode = auxiliaryNode->getNextNode();
        }
    } while (auxiliaryNode != firstNode);
    return nullptr;
}

template<class T>
CircularDoubleNode<T> *Circular DoublyLinkedList<T>::getLastNode() {
    CircularDoubleNode<T> *lastNode = firstNode;
    if (firstNode != nullptr) {
        do {
            lastNode = lastNode->getNextNode();
        } while (lastNode != firstNode);
    }
    return lastNode;
}
}*/
