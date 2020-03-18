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

#endif //SCRABBLE___DOUBLENODE_H
