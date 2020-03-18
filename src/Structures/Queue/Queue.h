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

#endif //SCRABBLE___QUEUE_H
