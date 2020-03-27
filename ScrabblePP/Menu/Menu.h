#ifndef SCRABBLE___MENU_H
#define SCRABBLE_MENU_H

#include "../Structures/SparseMatrix/SparseMatrix.h"
#include "../Structures/CircularDoublyLinkedList/CircularDoubleList.h"
#include "../Structures/Queue/Queue.h"
#include "../Structures/BinarySearchTree/BinarySearchTree.h"
#include "../Structures/SinglyLinkedList/SimpleList.h"
#include "../Structures/SortedSinglyLinkedList/SortedSimpleList.h"
#include "../Structures/DoublyLinkedList/DoubleList.h"

class Menu
{
private:
	int boardDimensions;
	SparseMatrix board;
	CircularDoubleList dictionary;
	Queue letters;
	BinarySearchTree players;
	SortedSimpleList scoreBoard;

public:
	Menu();
	~Menu();

	void StartGame();
};

Menu::Menu()
{
}

Menu::~Menu()
{
}

#endif // SCRABBLE___MENU_H
