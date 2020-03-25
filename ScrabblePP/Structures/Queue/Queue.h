#ifndef SCRABBLE___QUEUE_H
#define SCRABBLE___QUEUE_H

#include "QueueNode.h"

template<class T>
class Queue {
private:
    QueueNode<T> *firstNode;
    QueueNode<T> *lastNode;
    int length;

    bool isEmpty();

public:
    Queue();
    ~Queue();
    void push(T object);
    QueueNode<T> *pop();
    int getLength();
};


template<class T>
Queue<T>::Queue() {
    firstNode = nullptr;
    lastNode = nullptr;
    length = 0;
}

template<class T>
Queue<T>::~Queue() {
}

template<class T>
bool Queue<T>::isEmpty() {
    return firstNode == nullptr;
}

template<class T>
void Queue<T>::push(T object) {
    QueueNode<T> *node = new QueueNode<T>(object);
    if (isEmpty()) {
        firstNode = node;
        lastNode = node;
    } else {
        lastNode->setNextNode(node);
    }
    length++;
}

template<class T>
QueueNode<T> *Queue<T>::pop() {
    if (!isEmpty()) {
        QueueNode<T> *node = firstNode;
        firstNode = firstNode->getNextNode();
        length--;
        return node;
    }
    return nullptr;
}

template<class T>
int Queue<T>::getLength() {
    return length;
}

#endif //SCRABBLE___QUEUE_H
