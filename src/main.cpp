#include <iostream>
#include <cstdlib>

#include "Structures/SparseMatrix/SparseMatrix.h"

using namespace std;

int main() {
    SparseMatrix<int> sparseMatrix;

    sparseMatrix.addNode(0,1,01);
    sparseMatrix.addNode(1,3,13);
    sparseMatrix.addNode(3,7,37);
    sparseMatrix.addNode(9,4,94);
    sparseMatrix.addNode(2,10,210);
    sparseMatrix.addNode(8,4,84);
    sparseMatrix.addNode(4,3,43);
    sparseMatrix.addNode(2,7,27);
    sparseMatrix.addNode(1,1,11);
    sparseMatrix.report();

    // system("pause");
    return 0;
}
