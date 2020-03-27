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
    sparseMatrix.addNode(8, 4, 1,"�");
    sparseMatrix.addNode(4, 3, 1,"c");
    sparseMatrix.addNode(2, 7, 2,"�");
    sparseMatrix.addNode(1, 1, 3,"11");
    sparseMatrix.report();

    BinarySearchTree binarySearchTree;
    binarySearchTree.addNode(new Player("Didier", false));
    binarySearchTree.addNode(new Player("Fatima", false));
    binarySearchTree.addNode(new Player("Aracely", false));
    binarySearchTree.addNode(new Player("Mary", false));
    binarySearchTree.addNode(new Player("Dominguez", false));
    binarySearchTree.addNode(new Player("Adolfo", false));
    binarySearchTree.addNode(new Player("Jacqueline", false));
    binarySearchTree.addNode(new Player("Juan", false));
    binarySearchTree.addNode(new Player("Pedro", false));
    binarySearchTree.addNode(new Player("Vivi", false));
    binarySearchTree.report();
    binarySearchTree.reportInOrder();
    binarySearchTree.reportPreOrder();
    binarySearchTree.reportPostOrder();

    // system("pause");
    return 0;
}
