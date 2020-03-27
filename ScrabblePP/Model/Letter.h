#ifndef SCRABBLE_LETTER_H
#define SCRABBLE_LETTER_H

class Letter
{
private:
	char character;
	int score;

public:
	Letter(char character, int score);
	~Letter();

	char getCharacter();
	void setCharacter(char character);

	int getScore();
	void setScore(int score);
};

#endif // SCRABBLE_LETTER_H
