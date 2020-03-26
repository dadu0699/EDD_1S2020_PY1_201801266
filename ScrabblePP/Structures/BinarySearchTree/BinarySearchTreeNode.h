#ifndef SCRABBLE___BINARYSEARCHTREENODE_H
#define SCRABBLE___BINARYSEARCHTREENODE_H

template <class T>
class BinarySearchTreeNode
{
private:
    T object;
    BinarySearchTreeNode *leftNode;
    BinarySearchTreeNode *rightNode;

public:
    BinarySearchTreeNode(T object);
    ~BinarySearchTreeNode();

    T getObject();
    void setObject(T object);

    BinarySearchTreeNode *getLeftNode() const;
    void setLeftNode(BinarySearchTreeNode *leftNode);

    BinarySearchTreeNode *getRightNode() const;
    void setRightNode(BinarySearchTreeNode *rightNode);
};

template <class T>
BinarySearchTreeNode<T>::BinarySearchTreeNode(T object)
{
    this->object = object;
    leftNode = nullptr;
    rightNode = nullptr;
}

template <class T>
BinarySearchTreeNode<T>::~BinarySearchTreeNode()
{
}

template <class T>
T BinarySearchTreeNode<T>::getObject()
{
    return object;
}

template <class T>
void BinarySearchTreeNode<T>::setObject(T object)
{
    this->object = object;
}

template <class T>
typename BinarySearchTreeNode<T>::BinarySearchTreeNode *BinarySearchTreeNode<T>::getLeftNode() const
{
    return leftNode;
}

template <class T>
void BinarySearchTreeNode<T>::setLeftNode(BinarySearchTreeNode *leftNode)
{
    this->leftNode = leftNode;
}

template <class T>
typename BinarySearchTreeNode<T>::BinarySearchTreeNode *BinarySearchTreeNode<T>::getRightNode() const
{
    return rightNode;
}

template <class T>
void BinarySearchTreeNode<T>::setRightNode(BinarySearchTreeNode *rightNode)
{
    this->rightNode = rightNode;
}

#endif //SCRABBLE___BINARYSEARCHTREENODE_H
