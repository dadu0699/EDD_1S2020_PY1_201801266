#ifndef SCRABBLE___BINARYSEARCHTREENODE_H
#define SCRABBLE___BINARYSEARCHTREENODE_H

#include "../SinglyLinkedList/SimpleList.h"

class BinarySearchTreeNode
{
private:
    string name;
    SimpleList *scores;
    BinarySearchTreeNode *leftNode;
    BinarySearchTreeNode *rightNode;

public:
    BinarySearchTreeNode(string name);
    ~BinarySearchTreeNode();

    string getName();
    void setName(string name);

    SimpleList *getScores();

    BinarySearchTreeNode *getLeftNode() const;
    void setLeftNode(BinarySearchTreeNode *leftNode);

    BinarySearchTreeNode *getRightNode() const;
    void setRightNode(BinarySearchTreeNode *rightNode);
};

#endif //SCRABBLE___BINARYSEARCHTREENODE_H
