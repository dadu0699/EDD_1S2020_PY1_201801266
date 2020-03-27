#include "Letter.h"

Letter::Letter(char character, int score)
{
    this->character = character;
    this->score = score;
}

char Letter::getCharacter()
{
    return character;
}

void Letter::setCharacter(char character)
{
    this->character = character;
}

int Letter::getScore()
{
    return score;
}

void Letter::setScore(int score)
{
    this->score = score;
}
