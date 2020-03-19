#ifndef SCRABBLE___CIRCULARDOUBLENODE_H
#define SCRABBLE___CIRCULARDOUBLENODE_H

template<class T>
class CircularDoubleNode {
private:
    T object;
    CircularDoubleNode *nextNode;
    CircularDoubleNode *previousNode;
public:
    CircularDoubleNode(T object);
    ~CircularDoubleNode();

    T getObject();
    void setObject(T object);

    CircularDoubleNode *getNextNode() const;
    void setNextNode(CircularDoubleNode *nextNode);

    CircularDoubleNode *getPreviousNode() const;
    void setPreviousNode(CircularDoubleNode *nextNode);
};


template<class T>
CircularDoubleNode<T>::CircularDoubleNode(T object) {
    this->object = object;
    nextNode = nullptr;
    previousNode = nullptr;
}

template<class T>
CircularDoubleNode<T>::~CircularDoubleNode() {
}

template<class T>
T CircularDoubleNode<T>::getObject() {
    return object;
}

template<class T>
void CircularDoubleNode<T>::setObject(T object) {
    this->object = object;
}

template<class T>
typename CircularDoubleNode<T>::CircularDoubleNode* CircularDoubleNode<T>::getNextNode() const {
    return nextNode;
}

template<class T>
void CircularDoubleNode<T>::setNextNode(CircularDoubleNode *nextNode) {
    this->nextNode = nextNode;
}

template<class T>
typename CircularDoubleNode<T>::CircularDoubleNode* CircularDoubleNode<T>::getPreviousNode() const {
    return previousNode;
}

template<class T>
void CircularDoubleNode<T>::setPreviousNode(CircularDoubleNode *previousNode) {
    this->previousNode = previousNode;
}

#endif //SCRABBLE___CIRCULARDOUBLENODE_H
