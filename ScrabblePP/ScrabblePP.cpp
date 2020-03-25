#include <iostream>
#include <cstdlib>

#include "Structures/SparseMatrix/SparseMatrix.h"
#include "Structures/BinarySearchTree/BinarySearchTree.h"

using namespace std;

int main() {
    SparseMatrix<string> sparseMatrix;

    sparseMatrix.addNode(0, 1, "A");
    sparseMatrix.addNode(1, 3, "d");
    sparseMatrix.addNode(3, 7, "f");
    sparseMatrix.addNode(9, 4, "w");
    sparseMatrix.addNode(2, 10, "210");
    sparseMatrix.addNode(8, 4, "�");
    sparseMatrix.addNode(4, 3, "c");
    sparseMatrix.addNode(2, 7, "�");
    sparseMatrix.addNode(1, 1, "11");
    sparseMatrix.report();


    BinarySearchTree<string> binarySearchTree;
    binarySearchTree.addNode("H");
    binarySearchTree.addNode("C");
    binarySearchTree.addNode("J");
    binarySearchTree.addNode("A");
    binarySearchTree.addNode("F");
    binarySearchTree.addNode("M");
    binarySearchTree.addNode("N");
    binarySearchTree.addNode("E");
    binarySearchTree.addNode("G");
    binarySearchTree.report();

    // system("pause");
    return 0;
}
