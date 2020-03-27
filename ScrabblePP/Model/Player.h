#ifndef SCRABBLE_PLAYER_H
#define SCRABBLE_PLAYER_H

#include <iostream>
#include "../Structures/SinglyLinkedList/SimpleList.h"

using namespace std;

class Player
{
private:
	string name;
	SimpleList* scores;
	bool turn;
public:
	Player(string name, bool turn);
	~Player();

	string getName();
	void setName(string name);

	SimpleList* getScores() const;

	bool getTurn();
	void setTurn(bool turn);
};

#endif // SCRABBLE_PLAYER_H
