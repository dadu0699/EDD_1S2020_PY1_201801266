cmake_minimum_required(VERSION 3.15)
project(Scrabble__)

set(CMAKE_CXX_STANDARD 14)

add_executable(Scrabble__ src/main.cpp
        src/Structures/Queue/QueueNode.cpp src/Structures/Queue/QueueNode.h
        src/Structures/Queue/Queue.cpp src/Structures/Queue/Queue.h
        src/Structures/CircularDoubleList/CircularDoubleNode.cpp src/Structures/CircularDoubleList/CircularDoubleNode.h
        src/Structures/CircularDoubleList/CircularDoubleList.cpp src/Structures/CircularDoubleList/CircularDoubleList.h
        src/Structures/SimpleList/SimpleNode.cpp src/Structures/SimpleList/SimpleNode.h
        src/Structures/SimpleList/SimpleList.cpp src/Structures/SimpleList/SimpleList.h
        src/Structures/DoubleList/DoubleNode.cpp src/Structures/DoubleList/DoubleNode.h
        src/Structures/DoubleList/DoubleList.cpp src/Structures/DoubleList/DoubleList.h)