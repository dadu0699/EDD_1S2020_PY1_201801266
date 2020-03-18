#ifndef SCRABBLE___DOUBLELIST_H
#define SCRABBLE___DOUBLELIST_H

#include "DoubleNode.h"

template<class T>
class DoubleList {
private:
    DoubleNode<T> *firstNode;
    DoubleNode<T> *lastNode;

    bool isEmpty();

public:
    DoubleList();
    ~DoubleList();
    void addFirstNode(T object);
    void addLastNode(T object);
    void readStartNodes();
    void readEndNodes();
    void updateNode(T oldObject, T newObject);
    void deleteFirstNode();
    void deleteLastNode();
    void deleteSpecificNode(T object);
    DoubleNode<T> *searchNode(T object);
};

#endif //SCRABBLE___DOUBLELIST_H
