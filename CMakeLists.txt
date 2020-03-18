cmake_minimum_required(VERSION 3.15)
project(Scrabble__)

set(CMAKE_CXX_STANDARD 14)

add_executable(Scrabble__ src/main.cpp src/QueueNode.cpp src/QueueNode.h src/Queue.cpp src/Queue.h)