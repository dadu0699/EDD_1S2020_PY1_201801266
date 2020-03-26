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


    BinarySearchTree binarySearchTree;
    binarySearchTree.addNode("Didier");
    binarySearchTree.addNode("Fatima");
    binarySearchTree.addNode("Aracely");
    binarySearchTree.addNode("Mary");
    binarySearchTree.addNode("Danilo");
    binarySearchTree.addNode("Adolfo");
    binarySearchTree.addNode("Donis");
    binarySearchTree.addNode("Juan");
    binarySearchTree.addNode("Pedro");
    binarySearchTree.addNode("Alfredo");
    binarySearchTree.addNode("Esteban");
    binarySearchTree.addNode("Gatica");
    binarySearchTree.report();

    // system("pause");
    return 0;
}
