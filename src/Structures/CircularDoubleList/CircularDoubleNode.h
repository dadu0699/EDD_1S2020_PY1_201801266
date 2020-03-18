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

#endif //SCRABBLE___CIRCULARDOUBLENODE_H
