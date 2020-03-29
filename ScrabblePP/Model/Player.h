#ifndef SCRABBLE_PLAYER_H
#define SCRABBLE_PLAYER_H

#include <iostream>
#include "../Structures/SinglyLinkedList/SimpleList.h"

using namespace std;

class Player
{
private:
	string name;
	SimpleList *scores;

public:
	Player(string name);
	~Player();

	string getName();
	void setName(string name);

	SimpleList *getScores() const;
};

#endif // SCRABBLE_PLAYER_H
