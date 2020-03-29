#ifndef SCRABBLE___MENU_H
#define SCRABBLE___MENU_H

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
	SparseMatrix *board;
	CircularDoubleList *dictionary;
	Queue *letters;
	BinarySearchTree *players;
	SortedSimpleList *scoreBoard;
	Player *playerOne;
	Player *playerTwo;
	bool turn;
	bool finish;

	void principal();
	void choosePlayer();
	void readJSON(string route);
	void startGame();
	void assignTurn();

public:
	Menu();
	~Menu();
};

#endif // SCRABBLE___MENU_H
