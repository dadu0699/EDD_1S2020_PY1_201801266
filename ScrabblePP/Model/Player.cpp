#include "Player.h"

Player::Player(string name)
{
	this->name = name;
	scores = new SimpleList();
}

Player::~Player()
{
}

string Player::getName()
{
	return name;
}

void Player::setName(string name)
{
	this->name = name;
}

SimpleList *Player::getScores() const
{
	return scores;
}
