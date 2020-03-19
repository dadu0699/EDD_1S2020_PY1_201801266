#ifndef SCRABBLE___SIMPLENODE_H
#define SCRABBLE___SIMPLENODE_H

template<class T>
class SimpleNode {
private:
    T object;
    SimpleNode *nextNode;
public:
    SimpleNode(T object);
    ~SimpleNode();

    T getObject();
    void setObject(T object);

    SimpleNode *getNextNode() const;
    void setNextNode(SimpleNode *nextNode);
};


template<class T>
SimpleNode<T>::SimpleNode(T object) {
    this->object = object;
    nextNode = nullptr;
}

template<class T>
SimpleNode<T>::~SimpleNode() {
}

template<class T>
T SimpleNode<T>::getObject() {
    return object;
}

template<class T>
void SimpleNode<T>::setObject(T object) {
    this->object = object;
}

template<class T>
typename SimpleNode<T>::SimpleNode* SimpleNode<T>::getNextNode() const {
    return nextNode;
}

template<class T>
void SimpleNode<T>::setNextNode(SimpleNode *nextNode) {
    this->nextNode = nextNode;
}

#endif //SCRABBLE___SIMPLENODE_H
