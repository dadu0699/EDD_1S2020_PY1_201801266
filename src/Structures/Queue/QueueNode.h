#ifndef SCRABBLE___QUEUENODE_H
#define SCRABBLE___QUEUENODE_H

template<class T>
class QueueNode {
private:
    T object;
    QueueNode *nextNode;

public:
    QueueNode(T object);
    ~QueueNode();

    T getObject();
    void setObject(T object);

    QueueNode *getNextNode() const;
    void setNextNode(QueueNode *nextNode);
};


template<class T>
QueueNode<T>::QueueNode(T object) {
    this->object = object;
    nextNode = nullptr;
}

template<class T>
QueueNode<T>::~QueueNode() {
}

template<class T>
T QueueNode<T>::getObject() {
    return object;
}

template<class T>
void QueueNode<T>::setObject(T object) {
    this->object = object;
}

template<class T>
typename QueueNode<T>::QueueNode* QueueNode<T>::getNextNode() const {
    return nextNode;
}

template<class T>
void QueueNode<T>::setNextNode(QueueNode *nextNode) {
    this->nextNode = nextNode;
}

#endif //SCRABBLE___QUEUENODE_H
