#include <iostream>
#include <cstdlib>

#include "Structures/SparseMatrix/SparseMatrix.h"
#include "Structures/BinarySearchTree/BinarySearchTree.h"

using namespace std;

int main() {
    SparseMatrix sparseMatrix;

    sparseMatrix.addNode(0, 1, 1,"A");
    sparseMatrix.addNode(1, 3, 2,"d");
    sparseMatrix.addNode(3, 7, 2,"f");
    sparseMatrix.addNode(9, 4, 3,"w");
    sparseMatrix.addNode(2, 10, 3,"210");
    sparseMatrix.addNode(8, 4, 1,"Ñ");
    sparseMatrix.addNode(4, 3, 1,"c");
    sparseMatrix.addNode(2, 7, 2,"ñ");
    sparseMatrix.addNode(1, 1, 3,"11");
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
