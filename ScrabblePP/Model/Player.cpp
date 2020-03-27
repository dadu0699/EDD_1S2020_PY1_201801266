#include "Player.h"

Player::Player(string name, bool turn)
{
	this->name = name;
	this->turn = turn;
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

bool Player::getTurn()
{
	return turn;
}

void Player::setTurn(bool turn)
{
	this->turn = turn;
}
