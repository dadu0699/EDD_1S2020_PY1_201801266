#ifndef SCRABBLE___CIRCULARDOUBLELIST_H
#define SCRABBLE___CIRCULARDOUBLELIST_H

#include <iostream>
#include "CircularDoubleNode.h"

using namespace std;

class CircularDoubleList
{
private:
    CircularDoubleNode *firstNode;

    bool isEmpty();
    CircularDoubleNode *getLastNode();

public:
    CircularDoubleList();
    ~CircularDoubleList();
    void addNode(string word);
    void readStartNodes();
    void readEndNodes();
    void updateNode(string oldWord, string newWord);
    void deleteSpecificNode(string word);
    CircularDoubleNode *searchNode(string word);
    void report();
};

#endif //SCRABBLE___CIRCULARDOUBLELIST_H
