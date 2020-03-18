#ifndef SCRABBLE___CIRCULARDOUBLELIST_H
#define SCRABBLE___CIRCULARDOUBLELIST_H

#include "CircularDoubleNode.h"

template<class T>
class CircularDoubleList {
private:
    CircularDoubleNode<T> *firstNode;
    CircularDoubleNode<T> *lastNode;

    bool isEmpty();

public:
    CircularDoubleList();
    ~CircularDoubleList();
    void addNode(T object);
    void readStartNodes();
    void readEndNodes();
    void updateNode(T oldObject, T newObject);
    void deleteSpecificNode(T object);
    CircularDoubleNode<T> *searchNode(T object);
};

#endif //SCRABBLE___CIRCULARDOUBLELIST_H
