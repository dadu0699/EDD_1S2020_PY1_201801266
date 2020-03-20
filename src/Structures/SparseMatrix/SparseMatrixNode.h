#ifndef SCRABBLE___SPARSEMATRIXNODE_H
#define SCRABBLE___SPARSEMATRIXNODE_H

template <class T>
class SparseMatrixNode {
private:
    T object;
    int x;
    int y;
    SparseMatrixNode *nextNode;
    SparseMatrixNode *previousNode;
    SparseMatrixNode *upNode;
    SparseMatrixNode *downNode;
public:
    SparseMatrixNode(int x, int y, T object);
    ~SparseMatrixNode();

    int getX();
    void setX(int x);

    int getY();
    void setY(int y);

    T getObject();
    void setObject(T object);

    SparseMatrixNode *getNextNode() const;
    void setNextNode(SparseMatrixNode *nextNode);

    SparseMatrixNode *getPreviousNode() const;
    void setPreviousNode(SparseMatrixNode *previousNode);

    SparseMatrixNode *getUpNode() const;
    void setUpNode(SparseMatrixNode *upNode);

    SparseMatrixNode *getDownNode() const;
    void setDownNode(SparseMatrixNode *downNode);
};


template<class T>
SparseMatrixNode<T>::SparseMatrixNode(int x, int y, T object) {
    this->object = object;
    this->x = x;
    this->y = y;
    nextNode = nullptr;
    previousNode = nullptr;
    upNode = nullptr;
    downNode = nullptr;
}

template<class T>
SparseMatrixNode<T>::~SparseMatrixNode() {
}

template<class T>
int SparseMatrixNode<T>::getX() {
    return x;
}

template<class T>
void SparseMatrixNode<T>::setX(int x) {
    this->x = x;
}

template<class T>
int SparseMatrixNode<T>::getY() {
    return y;
}

template<class T>
void SparseMatrixNode<T>::setY(int y) {
    this->y = y;
}

template<class T>
T SparseMatrixNode<T>::getObject() {
    return object;
}

template<class T>
void SparseMatrixNode<T>::setObject(T object) {
    this->object = object;
}

template<class T>
typename SparseMatrixNode<T>::SparseMatrixNode *SparseMatrixNode<T>::getNextNode() const {
    return nextNode;
}

template<class T>
void SparseMatrixNode<T>::setNextNode(SparseMatrixNode *nextNode) {
    this->nextNode = nextNode;
}

template<class T>
typename SparseMatrixNode<T>::SparseMatrixNode *SparseMatrixNode<T>::getPreviousNode() const {
    return previousNode;
}

template<class T>
void SparseMatrixNode<T>::setPreviousNode(SparseMatrixNode *previousNode) {
    this->previousNode = previousNode;
}

template<class T>
typename SparseMatrixNode<T>::SparseMatrixNode *SparseMatrixNode<T>::getUpNode() const {
    return upNode;
}

template<class T>
void SparseMatrixNode<T>::setUpNode(SparseMatrixNode *upNode) {
    this->upNode = upNode;
}

template<class T>
typename SparseMatrixNode<T>::SparseMatrixNode *SparseMatrixNode<T>::getDownNode() const {
    return downNode;
}

template<class T>
void SparseMatrixNode<T>::setDownNode(SparseMatrixNode *downNode) {
    this->downNode = downNode;
}

#endif //SCRABBLE___SPARSEMATRIXNODE_H
