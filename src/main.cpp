#include <iostream>
#include <cstdlib>

#include "Structures/SparseMatrix/SparseMatrix.h"

using namespace std;

int main() {
    SparseMatrix<string> sparseMatrix;

    sparseMatrix.addNode(0,1,"A");
    sparseMatrix.addNode(1,3,"d");
    sparseMatrix.addNode(3,7,"f");
    sparseMatrix.addNode(9,4,"w");
    sparseMatrix.addNode(2,10,"210");
    sparseMatrix.addNode(8,4,"Ñ");
    sparseMatrix.addNode(4,3,"c");
    sparseMatrix.addNode(2,7,"ñ");
    sparseMatrix.addNode(1,1,"11");
    sparseMatrix.report();

    // system("pause");
    return 0;
}
