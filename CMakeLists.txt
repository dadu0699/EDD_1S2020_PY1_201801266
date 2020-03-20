cmake_minimum_required(VERSION 3.15)
project(Scrabble__)

set(CMAKE_CXX_STANDARD 14)

add_executable(Scrabble__ src/main.cpp
        src/Structures/Queue/QueueNode.cpp src/Structures/Queue/QueueNode.h
        src/Structures/Queue/Queue.cpp src/Structures/Queue/Queue.h
        "src/Structures/CircularDoublyLinkedList/CircularDoubleNode.cpp" "src/Structures/CircularDoublyLinkedList/CircularDoubleNode.h"
        "src/Structures/CircularDoublyLinkedList/CircularDoubleList.cpp" "src/Structures/CircularDoublyLinkedList/CircularDoubleList.h"
        src/Structures/SinglyLinkedList/SimpleNode.cpp src/Structures/SinglyLinkedList/SimpleNode.h
        src/Structures/SinglyLinkedList/SimpleList.cpp src/Structures/SinglyLinkedList/SimpleList.h
        "src/Structures/DoublyLinkedList/DoubleNode.cpp" "src/Structures/DoublyLinkedList/DoubleNode.h"
        "src/Structures/DoublyLinkedList/DoubleList.cpp" "src/Structures/DoublyLinkedList/DoubleList.h"
        "src/Structures/SparseMatrix/SparseMatrixNode.cpp" "src/Structures/SparseMatrix/SparseMatrixNode.h"
        src/Structures/SparseMatrix/SparseMatrix.cpp src/Structures/SparseMatrix/SparseMatrix.h)