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

#endif //SCRABBLE___SIMPLENODE_H
