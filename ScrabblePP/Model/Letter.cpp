#include "Letter.h"

Letter::Letter(char letter, int score)
{
    this->character = letter;
    this->score = score;
}

char Letter::getCharacter()
{
    return character;
}

void Letter::setCharacter(char letter)
{
    this->character = letter;
}

int Letter::getScore()
{
    return score;
}

void Letter::setScore(int score)
{
    this->score = score;
}
