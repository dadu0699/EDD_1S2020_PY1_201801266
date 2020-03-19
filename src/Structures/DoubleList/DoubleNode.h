#ifndef SCRABBLE___DOUBLENODE_H
#define SCRABBLE___DOUBLENODE_H

template<class T>
class DoubleNode {
private:
    T object;
    DoubleNode *nextNode;
    DoubleNode *previousNode;

public:
    DoubleNode(T object);
    ~DoubleNode();

    T getObject();
    void setObject(T object);

    DoubleNode *getNextNode() const;
    void setNextNode(DoubleNode *nextNode);

    DoubleNode *getPreviousNode() const;
    void setPreviousNode(DoubleNode *previousNode);
};


template<class T>
DoubleNode<T>::DoubleNode(T object) {
    this->object = object;
    nextNode = nullptr;
    previousNode = nullptr;
}

template<class T>
DoubleNode<T>::~DoubleNode() {
}

template<class T>
T DoubleNode<T>::getObject() {
    return object;
}

template<class T>
void DoubleNode<T>::setObject(T object) {
    this->object = object;
}

template<class T>
typename DoubleNode<T>::DoubleNode* DoubleNode<T>::getNextNode() const {
    return nextNode;
}

template<class T>
void DoubleNode<T>::setNextNode(DoubleNode *nextNode) {
    this->nextNode = nextNode;
}

template<class T>
typename DoubleNode<T>::DoubleNode* DoubleNode<T>::getPreviousNode() const {
    return previousNode;
}

template<class T>
void DoubleNode<T>::setPreviousNode(DoubleNode *previousNode) {
    this->previousNode = previousNode;
}

#endif //SCRABBLE___DOUBLENODE_H
