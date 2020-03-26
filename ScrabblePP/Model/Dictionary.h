#ifndef SCRABBLE___DICTIONARY_H
#define SCRABBLE___DICTIONARY_H

#include <iostream>
#include "../Structures/DoublyLinkedList/DoubleList.h"

using namespace std;

class Dictionary
{
private:
	DoubleList<string> listWords;
public:
	Dictionary();
	~Dictionary();

	DoubleList<string> getListWords();
};

#endif //SCRABBLE___DICTIONARY_H