#include "Menu.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
// #include <typeinfo>
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

Menu::Menu()
{
	board = new SparseMatrix();
	dictionary = new CircularDoubleList();
	letters = new Queue();
	players = new BinarySearchTree();
	scoreBoard = new SortedSimpleList();

	boardDimensions = 0;
	turn = false;
}

Menu::~Menu()
{
}

void Menu::principal()
{
	int option;
	bool loop = true;
	while (loop)
	{
		cout << endl
			 << "\tMenu Principal";
		cout << endl
			 << "\t1. Iniciar";
		cout << endl
			 << "\t2. Escoger / Agregar / Reporte Jugadores";
		cout << endl
			 << "\t3. Tablero de puntuaci�n";
		cout << endl
			 << "\t4. Salir";
		cout << endl
			 << "\t >> ";
		cin >> option;

		switch (option)
		{
		case 1:
			if (playerOne != nullptr && playerTwo != nullptr)
			{
				startGame();
			}
			break;
		case 2:
			choosePlayer();
			break;
		case 3:
			scoreBoard->report();
			break;
		case 4:
			cout << endl
				 << "\tSALIENDO!!!!!!!!!!!!!!";
			loop = false;
			break;
		default:
			cout << endl
				 << "\tOPCION INCORRECTA";
			cout << endl;
			break;
		}
		system("CLS");
	}
}

void Menu::choosePlayer()
{
	string namePlayerOne;
	bool flagPlayerOne = false;
	DoubleList lettersPlayerOne;

	string namePlayerTwo;
	bool flagPlayerTwo = false;
	DoubleList lettersPlayerTwo;

	int option;
	bool loop = true;

	while (!flagPlayerOne || !flagPlayerTwo)
	{
		cout << endl
			 << "\t1. Escoger jugador";
		cout << endl
			 << "\t2. Agregar Jugador";
		cout << endl
			 << "\t3. Reporte Jugadores";
		cout << endl
			 << "\t >> ";
		cin >> option;

		switch (option)
		{
		case 1:
			if (!flagPlayerOne)
			{
				cout << endl
					 << "\t >> Jugador 1: ";
				cin >> namePlayerOne;
				playerOne = players->search(namePlayerOne);
				if (playerOne == nullptr)
				{
					cout << "\t El juador " << namePlayerOne << " no se ha registrado previamente";
				}
				else
				{
					flagPlayerOne = true;
				}
			}

			if (!flagPlayerTwo)
			{
				cout << endl
					 << "\t >> Jugador 2: ";
				cin >> namePlayerTwo;
				playerTwo = players->search(namePlayerTwo);
				if (playerTwo == nullptr)
				{
					cout << "\t El juador: " << namePlayerTwo << " no se ha registrado previamente";
				}
				else
				{
					flagPlayerTwo = true;
				}
			}
			break;
		case 2:
			if (!flagPlayerOne)
			{
				playerOne = new Player("");
				cout << endl
					 << "\t >> Jugador 1: ";
				cin >> namePlayerOne;
				playerOne->setName(namePlayerOne);
				flagPlayerOne = players->addNode(playerOne);
				if (!flagPlayerOne)
				{
					cout << "\t El juador " << namePlayerOne << " se ha registrado previamente";
				}
			}

			if (!flagPlayerTwo)
			{
				playerTwo = new Player("");
				cout << endl
					 << "\t >> Jugador 2: ";
				cin >> namePlayerTwo;
				playerTwo->setName(namePlayerTwo);
				flagPlayerTwo = players->addNode(playerTwo);
				if (!flagPlayerTwo)
				{
					cout << "\t El juador: " << namePlayerTwo << " se ha registrado previamente";
				}
			}
			break;
		case 3:
			players->report();
			players->reportPreOrder();
			players->reportInOrder();
			players->reportPostOrder();
			return;
		default:
			cout << endl
				 << "\tOPCION INCORRECTA";
			cout << endl;
			break;
		}

		if (playerOne == playerTwo)
		{
			flagPlayerOne = false;
			flagPlayerTwo = false;
			cout << endl
				 << "\t No se puede escoger dos veces el mismo jugador";
		}
		cout << endl;
	}
	system("CLS");
}

void Menu::startGame()
{
	system("CLS");
	DoubleList lettersPlayerOne;
	DoubleList lettersPlayerTwo;

	readJSON("properties.json");

	for (int i = 0; i < 7; i++)
	{
		lettersPlayerOne.addLastNode(letters->pop()->getLetter());
		lettersPlayerTwo.addLastNode(letters->pop()->getLetter());
	}

	while (true)
	{
		if (turn)
		{
			lettersPlayerOne.report();

			turn = !turn;
		}
		else
		{
			lettersPlayerTwo.report();

			turn = !turn;
		}
	}
}

void Menu::readJSON(string route)
{
	ifstream jsonFile(route);
	if (jsonFile.is_open())
	{
		json jsonData;
		jsonFile >> jsonData;

		int x;
		int y;

		boardDimensions = jsonData.at("dimension");
		cout << "Dimension: " << boardDimensions << endl;
		cout << "Casillas: " << endl;
		cout << "\tDobles: " << endl;
		for (size_t i = 0; i < jsonData.at("casillas").at("dobles").size(); i++)
		{
			x = jsonData.at("casillas").at("dobles")[i].at("x");
			y = jsonData.at("casillas").at("dobles")[i].at("y");
			board->addNode(x, y, 2, "");

			cout << "\t\tX: " << x << endl;
			cout << "\t\tY: " << y << endl;
		}
		cout << "\tTriples: " << endl;
		for (size_t i = 0; i < jsonData.at("casillas").at("triples").size(); i++)
		{
			x = jsonData.at("casillas").at("triples")[i].at("x");
			y = jsonData.at("casillas").at("triples")[i].at("y");
			board->addNode(x, y, 3, "");

			cout << "\t\tX: " << x << endl;
			cout << "\t\tY: " << y << endl;
		}

		cout << "Diccionario: " << endl;
		for (size_t i = 0; i < jsonData.at("diccionario").size(); i++)
		{
			cout << "\tPalabra: " << jsonData.at("diccionario")[i].at("palabra") << endl;
			dictionary->addNode(jsonData.at("diccionario")[i].at("palabra"));
		}
		dictionary->report();
		board->report();
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
}

void Menu::assignTurn()
{
	srand(time(NULL));
	if (rand() % 2 == 2)
	{
		turn = true;
	}
	else
	{
		turn = false;
	}
}