#ifndef SCRABBLE___SIMPLELIST_H
#define SCRABBLE___SIMPLELIST_H

#include "SimpleNode.h"

template<class T>
class SimpleList {
private:
    SimpleNode<T> *firstNode;
    SimpleNode<T> *lastNode;

    bool isEmpty();

public:
    SimpleList();
    ~SimpleList();
    void addFirstNode(T object);
    void addLastNode(T object);
    void readNodes();
    void updateNode(T oldObject, T newObject);
    void deleteFirstNode();
    void deleteLastNode();
    void deleteSpecificNode(T object);
    SimpleNode<T> *searchNode(T object);
    void sortList();
};

#endif //SCRABBLE___SIMPLELIST_H
