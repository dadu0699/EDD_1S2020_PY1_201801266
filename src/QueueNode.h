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

#endif //SCRABBLE___QUEUENODE_H
