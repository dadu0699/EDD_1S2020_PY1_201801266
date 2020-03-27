#ifndef SCRABBLE___BINARYSEARCHTREENODE_H
#define SCRABBLE___BINARYSEARCHTREENODE_H

#include "../../Model/Player.h"

class BinarySearchTreeNode
{
private:
    Player *player;
    BinarySearchTreeNode *leftNode;
    BinarySearchTreeNode *rightNode;

public:
    BinarySearchTreeNode(Player *player);
    ~BinarySearchTreeNode();

    Player* getPlayer() const;

    BinarySearchTreeNode *getLeftNode() const;
    void setLeftNode(BinarySearchTreeNode *leftNode);

    BinarySearchTreeNode *getRightNode() const;
    void setRightNode(BinarySearchTreeNode *rightNode);
};

#endif //SCRABBLE___BINARYSEARCHTREENODE_H
