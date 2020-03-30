#ifndef SCRABBLE___SPARSEMATRIX_H
#define SCRABBLE___SPARSEMATRIX_H

#include <iostream>
#include <fstream>
#include "SparseMatrixNode.h"

using namespace std;

class SparseMatrix
{
private:
    SparseMatrixNode *root;

    SparseMatrixNode *searchColumn(int x);

    SparseMatrixNode *searchRow(int y);

    SparseMatrixNode *insertIntoColumn(SparseMatrixNode *node, SparseMatrixNode *headerRow);

    SparseMatrixNode *insertIntoRow(SparseMatrixNode *node, SparseMatrixNode *headerColumn);

    SparseMatrixNode *createColumn(int x);

    SparseMatrixNode *createRow(int y);

public:
    SparseMatrix();

    ~SparseMatrix();

    void addNode(int x, int y, int score, string data);

    void printRowHeaders();

    void printColumnHeaders();

    void printRows();

    void printColumns();

    void report();

    SparseMatrixNode *getNode(int x, int y);
};

#endif //SCRABBLE___SPARSEMATRIX_H
